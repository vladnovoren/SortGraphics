#include "gui_skin_manager.hpp"


gui::SkinManager::SkinManager(const char* folder_path) {
  assert(folder_path != nullptr);

  LoadFromFolder(folder_path);
  LoadSanFranciscoFont();
}


gui::SkinManager::~SkinManager() {
  delete m_san_francisco_font;
}


gui::SkinManager& gui::SkinManager::GetInstance() {
  static SkinManager instance(AQUA_SKIN_FOLDER_PATH);
  return instance;
}


char* gui::SkinManager::GetPath(const char* folder_path, const char* child_dir) {
  assert(folder_path != nullptr);
  assert(child_dir   != nullptr);

  char* path = (char*)calloc(strlen(folder_path) + strlen(child_dir) + 1, sizeof(char));
  strcpy(path, folder_path);
  strcat(path, child_dir);
  return path;
}


char* gui::SkinManager::SkipSpaces(char* carriage) {
  assert(carriage != nullptr);

  while (isspace(*carriage) || *carriage == '\n') {
    ++carriage;
  }
  return carriage;
}


char* gui::SkinManager::SkipComments(char* carriage) {
  assert(carriage != nullptr);

  if (*carriage != ';') {
    return carriage;
  }
  char* strchr_res = strchr(carriage, '\n');
  if (strchr_res == nullptr) {
    printf("invalid map.txt");
    return nullptr;
  }
  ++strchr_res;
  return strchr_res;
}


char* gui::SkinManager::SkipTrash(char* carriage) {
  assert(carriage != nullptr);

  bool is_parsing = true;
  while (is_parsing) {
    bool spaces_skipped = false;
    bool comments_skipped = false;
    char* skip_spaces_res = SkipSpaces(carriage);
    if (skip_spaces_res != carriage) {
      spaces_skipped = true;
    }
    carriage = skip_spaces_res;
    char* skip_comments_res = SkipComments(carriage);
    if (skip_spaces_res != carriage) {
      comments_skipped = true;
    }
    carriage = skip_comments_res;
    if (!spaces_skipped && !comments_skipped) {
      is_parsing = false;
    }
  }
  return carriage;
}


void gui::SkinManager::LoadSanFranciscoFont() {
  m_san_francisco_font = new glib::Font("SanFrancisco/SF-Pro-Display-Bold.otf");
  assert(m_san_francisco_font != nullptr);
}


char* gui::SkinManager::GetVector2iFromText(char* text, glib::Vector2i* vector) {
  assert(text != nullptr);
  assert(vector != nullptr);

  text = SkipTrash(text);
  int n_scanned_chars = 0;
  int n_scanned_nums = sscanf(text, "%d%d%n", &vector->x, &vector->y, &n_scanned_chars);
  if (n_scanned_nums != 2) {
    printf("Unable to get glib::Vector2i from text\n");
    return nullptr;
  }
  return text + n_scanned_chars;
}


char* gui::SkinManager::GetIntRectFromText(char* text, glib::IntRect* rect) {
  assert(text != nullptr);
  assert(rect != nullptr);

  text = GetVector2iFromText(text, &rect->m_position);
  if (text == nullptr) {
    return nullptr;
  }
  text = GetVector2iFromText(text, &rect->m_size);
  return text;
}


char* gui::SkinManager::GetButtonTypeFromText(char* text, ButtonType* button_type) {
  assert(text        != nullptr);
  assert(button_type != nullptr);

  text = SkipTrash(text);
  char* button_type_str = (char*)calloc(20, sizeof(char));
  int n_scanned_chars = 0;
  int sscanf_res = sscanf(text, "%s%n", button_type_str, &n_scanned_chars);
  text += n_scanned_chars;
  if (sscanf_res == 1) {
    if (strcmp(button_type_str, "circle") == 0) {
      *button_type = ButtonType::CIRCLE;
    } else if (strcmp(button_type_str, "rect") == 0) {
      *button_type = ButtonType::RECT;
    } else {
      printf("invalid button type\n");
      free(button_type_str);
      return nullptr;
    }
  } else {
    printf("invalid button type\n");
    free(button_type_str);
    return nullptr;
  }
  free(button_type_str);
  return text;
}


bool gui::SkinManager::LoadFromFolder(const char* folder_path) {
  assert(folder_path != nullptr);

  delete m_minimize_button_skin;
  delete m_maximize_button_skin;
  delete m_close_button_skin;
  delete m_title_bar_skin;
  delete m_main_menu_skin;

  char* minimize_button_path     = GetPath(folder_path, "/MinimizeButton");
  char* maximize_button_path     = GetPath(folder_path, "/MaximizeButton");
  char* close_button_path        = GetPath(folder_path, "/CloseButton");
  char* title_bar_path           = GetPath(folder_path, "/TitleBar");
  char* main_menu_path           = GetPath(folder_path, "/MainMenu");
  char* window_path              = GetPath(folder_path, "/Window");
  char* tool_bar_path            = GetPath(folder_path, "/ToolBar");
  char* color_select_button_path = GetPath(folder_path, "/ColorSelectButton");
  char* brush_button_skin_path   = GetPath(folder_path, "/BrushButton");
  char* fill_bucket_button_path  = GetPath(folder_path, "/FillBucketButton");
  char* canvas_skin_path         = GetPath(folder_path, "/Canvas");
  char* eraser_button_path       = GetPath(folder_path, "/Eraser");

  m_minimize_button_skin     = LoadButtonSkinFromFolder(minimize_button_path);
  m_maximize_button_skin     = LoadButtonSkinFromFolder(maximize_button_path);
  m_close_button_skin        = LoadButtonSkinFromFolder(close_button_path);
  m_title_bar_skin           = LoadTitleBarSkinFromFolder(title_bar_path);
  m_main_menu_skin           = LoadMainMenuSkinFromFolder(main_menu_path);
  m_window_skin              = LoadWindowSkinFromFolder(window_path);
  m_tool_bar_skin            = LoadToolBarSkinFromFolder(tool_bar_path);
  m_color_select_button_skin = LoadSelectButtonSkinFromFolder(color_select_button_path);
  m_brush_button_skin        = LoadButtonSkinFromFolder(brush_button_skin_path);
  m_fill_bucket_button_skin  = LoadButtonSkinFromFolder(fill_bucket_button_path);
  m_canvas_skin              = LoadCanvasSkinFromFolder(canvas_skin_path);
  m_eraser_button_skin       = LoadButtonSkinFromFolder(eraser_button_path);

  free(eraser_button_path);
  free(canvas_skin_path);
  free(fill_bucket_button_path);
  free(window_path);
  free(main_menu_path);
  free(minimize_button_path);
  free(maximize_button_path);
  free(close_button_path);
  free(title_bar_path);
  free(tool_bar_path);
  free(color_select_button_path);
  free(brush_button_skin_path);

  return true;
}


gui::AbstractButtonSkin* gui::SkinManager::LoadButtonSkinFromFolder(const char* folder_path) {
  assert(folder_path != nullptr);

  char* map_path = GetPath(folder_path, "/map.txt");

  size_t map_size = 0;
  char* map = FileToStr(map_path, &map_size, "rb");
  char* map_carriage = map;
  free(map_path);

  ButtonType button_type = ButtonType::RECT;
  map_carriage = GetButtonTypeFromText(map_carriage, &button_type);

  AbstractButtonSkin* button_skin = nullptr;
  switch (button_type) {
    case ButtonType::RECT:
      button_skin = new RectButtonSkin;
      break;
    case ButtonType::CIRCLE:
      button_skin = new CircleButtonSkin;
      break;
  }

  char* texture_path = GetPath(folder_path, "/texture.png");
  button_skin->m_source_texture.LoadFromFile(texture_path);
  free(texture_path);

  map_carriage = GetIntRectFromText(map_carriage, &button_skin->m_idle_texture_location);
  map_carriage = GetIntRectFromText(map_carriage, &button_skin->m_hovered_texture_location);
  map_carriage = GetIntRectFromText(map_carriage, &button_skin->m_pressed_texture_location);

  free(map);

  return button_skin;
}


gui::TitleBarSkin* gui::SkinManager::LoadTitleBarSkinFromFolder(const char* folder_path) {
  assert(folder_path != nullptr);

  TitleBarSkin* skin = new TitleBarSkin;
  char* texture_path = GetPath(folder_path, "/texture.png");
  skin->m_source_texture.LoadFromFile(texture_path);
  free(texture_path);

  char* map_path = GetPath(folder_path, "/map.txt");
  size_t map_size = 0;
  char* map = FileToStr(map_path, &map_size, true);
  char* map_carriage = map;
  free(map_path);

  map_carriage = GetIntRectFromText(map_carriage, &skin->m_left_origin_location);
  map_carriage = GetIntRectFromText(map_carriage, &skin->m_left_all_location);
  map_carriage = GetIntRectFromText(map_carriage, &skin->m_middle_origin_location);
  map_carriage = GetIntRectFromText(map_carriage, &skin->m_middle_all_location);
  map_carriage = GetIntRectFromText(map_carriage, &skin->m_right_origin_location);
  map_carriage = GetIntRectFromText(map_carriage, &skin->m_right_all_location);

  free(map);

  return skin;
}

gui::MainMenuSkin* gui::SkinManager::LoadMainMenuSkinFromFolder(const char* folder_path) {
  assert(folder_path != nullptr);

  MainMenuSkin* skin = new MainMenuSkin;

  char* texture_path = GetPath(folder_path, "/texture.png");
  skin->m_source_texture.LoadFromFile(texture_path);
  free(texture_path);

  char* map_path = GetPath(folder_path, "/map.txt");
  size_t map_size = 0;
  char* map = FileToStr(map_path, &map_size, true);
  char* map_carriage = map;
  free(map_path);

  map_carriage = GetIntRectFromText(map_carriage, &skin->m_location);

  free(map);

  return skin;
}


gui::WindowSkin* gui::SkinManager::LoadWindowSkinFromFolder(const char* folder_path) {
  assert(folder_path != nullptr);

  WindowSkin* skin = new WindowSkin;

  char* texture_path = GetPath(folder_path, "/texture.png");
  skin->m_source_texture.LoadFromFile(texture_path);
  free(texture_path);

  char* map_path = GetPath(folder_path, "/map.txt");
  size_t map_size = 0;
  char* map = FileToStr(map_path, &map_size, true);
  char* map_carriage = map;
  free(map_path);

  map_carriage = GetIntRectFromText(map_carriage, &skin->m_left_edge_location);
  map_carriage = GetIntRectFromText(map_carriage, &skin->m_left_bottom_angle_location);
  map_carriage = GetIntRectFromText(map_carriage, &skin->m_bottom_location);
  map_carriage = GetIntRectFromText(map_carriage, &skin->m_right_bottom_angle_location);
  map_carriage = GetIntRectFromText(map_carriage, &skin->m_right_edge_location);

  free(map);

  return skin;
}


gui::ToolBarSkin* gui::SkinManager::LoadToolBarSkinFromFolder(const char* folder_path) {
  assert(folder_path != nullptr);

  ToolBarSkin* skin = new ToolBarSkin;
  
  char* texture_path = GetPath(folder_path, "/texture.png");
  skin->m_source_texture.LoadFromFile(texture_path);
  free(texture_path);

  char* map_path = GetPath(folder_path, "/map.txt");
  size_t map_size = 0;
  char* map = FileToStr(map_path, &map_size, true);
  free(map_path);

  char* map_carriage = map;
  map_carriage = GetIntRectFromText(map_carriage, &skin->m_right_edge_location);
  free(map);

  return skin;
}


gui::ColorSelectButtonSkin* gui::SkinManager::LoadSelectButtonSkinFromFolder(const char* folder_path) {
  assert(folder_path != nullptr);

  ColorSelectButtonSkin* skin = new ColorSelectButtonSkin;

  char* texture_path = GetPath(folder_path, "/texture.png");
  skin->m_source_texture.LoadFromFile(texture_path);
  free(texture_path);

  char* map_path = GetPath(folder_path, "/map.txt");
  size_t map_size = 0;
  char* map = FileToStr(map_path, &map_size, true);
  free(map_path);

  char* map_carriage = map;
  map_carriage = GetIntRectFromText(map_carriage, &skin->m_idle_texture_location);
  map_carriage = GetIntRectFromText(map_carriage, &skin->m_hovered_texture_location);
  map_carriage = GetIntRectFromText(map_carriage, &skin->m_pressed_texture_location);
  map_carriage = GetIntRectFromText(map_carriage, &skin->m_hit_area);
  free(map);

  return skin;
}


gui::CanvasSkin* gui::SkinManager::LoadCanvasSkinFromFolder(const char* folder_path) {
  assert(folder_path != nullptr);

  CanvasSkin* skin = new CanvasSkin;

  char* texture_path = GetPath(folder_path, "/texture.png");
  skin->m_source_texture.LoadFromFile(texture_path);
  free(texture_path);

  char* map_path = GetPath(folder_path, "/map.txt");
  size_t map_size = 0;
  char* map = FileToStr(map_path, &map_size, true);
  free(map_path);

  GetIntRectFromText(map, &skin->m_location);
  free(map);

  return skin;
}


gui::AbstractButtonSkin* gui::SkinManager::GetMinimizeButtonSkin() const {
  return m_minimize_button_skin;
}


gui::AbstractButtonSkin* gui::SkinManager::GetMaximizeButtonSkin() const {
  return m_maximize_button_skin;
}


gui::AbstractButtonSkin* gui::SkinManager::GetCloseButtonSkin() const {
  return m_close_button_skin;
}


gui::TitleBarSkin* gui::SkinManager::GetTitleBarSkin() const {
  return m_title_bar_skin;
}


gui::MainMenuSkin* gui::SkinManager::GetMainMenuSkin() const {
  return m_main_menu_skin;
}


glib::Font* gui::SkinManager::GetSanFranciscoFont() const {
  return m_san_francisco_font;
}


gui::WindowSkin* gui::SkinManager::GetWindowSkin() const {
  return m_window_skin;
}


gui::ToolBarSkin* gui::SkinManager::GetToolBarSkin() const {
  return m_tool_bar_skin;
}


gui::ColorSelectButtonSkin* gui::SkinManager::GetColorSelectButtonSkin() const {
  return m_color_select_button_skin;
}


gui::AbstractButtonSkin* gui::SkinManager::GetBrushButtonSkin() const {
  return m_brush_button_skin;
}


gui::AbstractButtonSkin* gui::SkinManager::GetFillBucketButtonSkin() const {
  return m_fill_bucket_button_skin;
}


gui::CanvasSkin* gui::SkinManager::GetCanvasSkin() const {
  return m_canvas_skin;
}


gui::AbstractButtonSkin* gui::SkinManager::GetEraserButtonSkin() const {
  return m_eraser_button_skin;
}
