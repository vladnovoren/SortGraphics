#ifndef GUI_SKIN_MANAGER_HPP
#define GUI_SKIN_MANAGER_HPP


#include "open_file.hpp"
#include <cstring>

#include "gui_abstract_button_skin.hpp"
#include "gui_title_bar_skin.hpp"
#include "gui_main_menu_skin.hpp"
#include "gui_app_config.hpp"
#include "gui_window_skin.hpp"
#include "gui_tool_bar_skin.hpp"
#include "gui_color_select_button_skin.hpp"
#include "gui_canvas_skin.hpp"


namespace gui {
  class SkinManager {
   protected:
    SkinManager(const char* folder_path);

    AbstractButtonSkin*    m_minimize_button_skin     = nullptr;
    AbstractButtonSkin*    m_maximize_button_skin     = nullptr;
    AbstractButtonSkin*    m_close_button_skin        = nullptr;
    TitleBarSkin*          m_title_bar_skin           = nullptr;
    MainMenuSkin*          m_main_menu_skin           = nullptr;
    WindowSkin*            m_window_skin              = nullptr;
    ToolBarSkin*           m_tool_bar_skin            = nullptr;
    ColorSelectButtonSkin* m_color_select_button_skin = nullptr;
    AbstractButtonSkin*    m_brush_button_skin        = nullptr;
    AbstractButtonSkin*    m_fill_bucket_button_skin  = nullptr;
    CanvasSkin*            m_canvas_skin              = nullptr;
    AbstractButtonSkin*    m_eraser_button_skin       = nullptr;

    glib::Font*            m_san_francisco_font       = nullptr;
   public:
    ~SkinManager();

    static SkinManager&    GetInstance();

    bool                   LoadFromFolder(const char* folder_path);

    void                   LoadSanFranciscoFont();

    char*                  GetPath(const char* folder_path, const char* child_dir);

    char*                  SkipSpaces(char* carriage);
    char*                  SkipComments(char* carriage);
    char*                  SkipTrash(char* carriage);

    char*                  GetVector2iFromText(char* text, glib::Vector2i* vector);
    char*                  GetIntRectFromText(char* text, glib::IntRect* rect);
    char*                  GetButtonTypeFromText(char* text, ButtonType* button_type);

    AbstractButtonSkin*    LoadButtonSkinFromFolder(const char* folder_path);
    TitleBarSkin*          LoadTitleBarSkinFromFolder(const char* folder_path);
    MainMenuSkin*          LoadMainMenuSkinFromFolder(const char* folder_path);
    WindowSkin*            LoadWindowSkinFromFolder(const char* folder_path);
    ToolBarSkin*           LoadToolBarSkinFromFolder(const char* folder_path);
    ColorSelectButtonSkin* LoadSelectButtonSkinFromFolder(const char* folder_path);
    CanvasSkin*            LoadCanvasSkinFromFolder(const char* folder_path);

    AbstractButtonSkin*    GetMinimizeButtonSkin() const;
    AbstractButtonSkin*    GetMaximizeButtonSkin() const;
    AbstractButtonSkin*    GetCloseButtonSkin() const;
    TitleBarSkin*          GetTitleBarSkin() const;
    MainMenuSkin*          GetMainMenuSkin() const;
    WindowSkin*            GetWindowSkin() const;
    ToolBarSkin*           GetToolBarSkin() const;
    ColorSelectButtonSkin* GetColorSelectButtonSkin() const;
    AbstractButtonSkin*    GetBrushButtonSkin() const;
    AbstractButtonSkin*    GetFillBucketButtonSkin() const;
    CanvasSkin*            GetCanvasSkin() const;
    AbstractButtonSkin*    GetEraserButtonSkin() const;

    glib::Font*            GetSanFranciscoFont() const;
  };
}


#endif /* gui_skin_manager.hpp */
