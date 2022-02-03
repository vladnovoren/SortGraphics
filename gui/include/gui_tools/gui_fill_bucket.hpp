#ifndef GUI_FILL_BUCKET_HPP
#define GUI_FILL_BUCKET_HPP


#include "gui_abstract_tool.hpp"
#include "gui_color_picker.hpp"


namespace gui {
  class FillBucket: public AbstractTool {
    FillBucket() = default;
   public:
    ~FillBucket() = default;

    static FillBucket* GetInstance();

    void Apply(Canvas* canvas) override;
  };
}


#endif /* gui_fill_bucket.hpp */
