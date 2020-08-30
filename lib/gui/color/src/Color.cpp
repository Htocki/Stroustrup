#include "Color.h"

namespace Gui {
namespace {
int ToInt(Color::Visibility visibility) {
  return static_cast<int> (visibility);
}

sf::Color ToSFML(Color::Name name, Color::Visibility visibility) {
  switch (name) {
    case Color::Name::Red:
      return sf::Color(255,   0,   0, ToInt(visibility));
    case Color::Name::Blue:
      return sf::Color(  0,   0, 255, ToInt(visibility));
    case Color::Name::Green:
      return sf::Color(  0, 255,   0, ToInt(visibility));
    case Color::Name::Yellow:
      return sf::Color(255, 255,   0, ToInt(visibility));
    case Color::Name::White:
      return sf::Color(255, 255, 255, ToInt(visibility));
    case Color::Name::Black:
      return sf::Color(  0,   0,   0, ToInt(visibility));
    case Color::Name::Magenta:
      return sf::Color(255,   0, 255, ToInt(visibility));
    case Color::Name::Cyan:
      return sf::Color(  0, 255, 255, ToInt(visibility));
    default:
      return sf::Color(  0,   0,   0, ToInt(visibility));
  }
}
}

Color::Color() {
  _color = ToSFML(_name, _visibility);
}

Color::Color(Name name) {
  _color = ToSFML(name, _visibility);
}

Color::Color(Visibility visibility) {
  _color = ToSFML(_name, visibility);
}

Color::Color(Name name, Visibility visibility) {
  _color = ToSFML(name, visibility);
}

void Color::Set_color(Name name) {
  _color = ToSFML(name, _visibility);
}

void Color::Set_visibility(Visibility visibility) {
  _color = ToSFML(_name, visibility);
}
}  // namespace Gui
