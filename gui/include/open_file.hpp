#ifndef OPEN_FILE_HPP
#define OPEN_FILE_HPP


#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <sys/stat.h>


FILE*  OpenFile(const char* file_name, const char* mode);

size_t SizeOfFile(FILE* file);

size_t SizeOfFile(const char* file_name);

char*  FileToStr(FILE* src, size_t* size, bool new_line);

char*  FileToStr(const char* src_name, size_t* size, bool new_line);


#endif /* open_file.hpp */