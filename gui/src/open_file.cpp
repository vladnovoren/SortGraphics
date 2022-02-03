#include "open_file.hpp"


FILE* OpenFile(const char* file_name, const char* mode) {
	assert(file_name);
	assert(mode);

	FILE* opened_file = fopen(file_name, mode);
	if (!opened_file) {
		printf("Unable to open file \"%s\".\n", file_name);
	}

	return opened_file;
}


size_t SizeOfFile(FILE* file) {
	assert(file);

	fseek(file, 0, SEEK_END);
	size_t file_size = ftell(file);
	fseek(file, 0, SEEK_SET);
	return file_size;
}


size_t SizeOfFile(const char* file_name) {
	assert(file_name);

	struct stat stfile;

	if (stat(file_name, &stfile) == -1){
		return 0;
	} else {
		return stfile.st_size;
	}
}


char* FileToStr(FILE* src, size_t* size, bool new_line) {
	assert(size != nullptr);
	assert(src != nullptr);

	size_t buf_size = SizeOfFile(src);
	if (buf_size == 0) {
		printf("Empty input file.\n");
		return nullptr;
	}

	char* buf = (char*)calloc(buf_size + 2, sizeof(char));
	if (buf == NULL) {
		printf("Too big input file size.\n");
		return nullptr;
	}

	size_t fread_cnt = fread(buf, sizeof(char), buf_size, src);
	if (fread_cnt != buf_size) {
		printf("Too big input file size.\n");
		return nullptr;
	}

	if (new_line && buf[buf_size - 1] != '\n') {
		buf[buf_size] = '\n';
		buf_size++;
	}

	*size = buf_size;

	return buf;
}


char* FileToStr(const char* src_name, size_t* size, bool new_line) {
	assert(src_name != nullptr);
	assert(size     != nullptr);

	FILE* src = OpenFile(src_name, "rb");
	if (src == NULL) {
		return nullptr;
	}

	char* str = FileToStr(src, size, new_line);
	fclose(src);
	return str;
}
