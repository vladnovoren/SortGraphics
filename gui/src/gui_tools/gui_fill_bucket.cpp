#include "gui_fill_bucket.hpp"


void gui::FillBucket::Apply(Canvas* canvas) {
  assert(canvas != nullptr);

  canvas->Clear(ColorPicker::GetInstance().GetColor());
}


gui::FillBucket* gui::FillBucket::GetInstance() {
  static FillBucket* instance = new FillBucket;
  return instance;
}

