#ifndef COLOR_HPP
#define COLOR_HPP


#include "SFML/Graphics.hpp"
#include "glib_color.hpp"


namespace glib {
  struct ColorRGBA {
    double r = 0;
    double g = 0;
    double b = 0;
    double a = 1;

    ColorRGBA() = default;
    ColorRGBA(double r, double g, double b);
    ColorRGBA(int r, int g, int b);
    ColorRGBA(double r, double g, double b, double a);

    ColorRGBA& operator *= (const double mul);
    ColorRGBA& operator *= (const ColorRGBA& right);
    ColorRGBA& operator += (const ColorRGBA& right);
    ColorRGBA operator + (const ColorRGBA& right) const;
    ColorRGBA operator * (const ColorRGBA& right) const;
    ColorRGBA operator * (const double scalar) const;
    friend ColorRGBA operator * (const double scalar, const ColorRGBA& color);
  };

  ColorRGBA operator * (const double scalar, const ColorRGBA& color);

  sf::Color GLibToSFMLColor(const ColorRGBA& color);

  static const ColorRGBA BLACK  = ColorRGBA(0.0, 0.0, 0.0);
  static const ColorRGBA WHITE  = ColorRGBA(1.0, 1.0, 1.0);
  static const ColorRGBA RED    = ColorRGBA(1.0, 0.0, 0.0);
  static const ColorRGBA GREEN  = ColorRGBA(0.0, 1.0, 0.0);
  static const ColorRGBA BLUE   = ColorRGBA(0.0, 0.0, 1.0);
  static const ColorRGBA YELLOW = ColorRGBA(1.0, 1.0, 0.0);
  static const ColorRGBA PINK   = ColorRGBA(0xE7, 0x54, 0x80);
  static const ColorRGBA PURPLE = ColorRGBA(0x42, 0x31, 0x89);
}


#endif /* glib_color.hpp */
