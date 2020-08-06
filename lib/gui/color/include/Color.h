#pragma once

#include <SFML/Graphics/Color.hpp>

struct Color {
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
    Invisible,
    Visible
  };
  
  Color(Name name);
  Color(Name name, Visibility visibility);
  Color(Visibility visiblity);

  Name Get_name() const { return _name; }
  Visibility Get_visibility() const { return _visibility; }

  void Set_visibility(Visibility visibility) {
    _visibility = visibility;
  }

private:
  Visibility _visibility = { Visibility::Visible };
  Name _name = { Name::Black };
  // sf::Color _sfml_color;
};