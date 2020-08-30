#pragma once

#include <SFML/Graphics/Color.hpp>

namespace Gui {
class Color {
 public:
  enum class Name {
    Red,
    Blue,
    Green,
    Yellow,
    White,
    Black,
    Magenta,
    Cyan
  };

  enum class Visibility { 
    Invisible = 0,
    Visible = 255
  };
  
  Color();
  Color(Name name);
  Color(Visibility visiblity);
  Color(Name name, Visibility visibility);

  void Set_color(Name name);
  void Set_visibility(Visibility visibility);

private:
  Name _name { Name::Black };
  Visibility _visibility { Visibility::Visible };
  sf::Color _color;
};
}  // namespace Gui
