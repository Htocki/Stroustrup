#pragma once

#include <string>

#include <SFML/Graphics/RenderWindow.hpp>

#include "Subject.h"

namespace Gui {
class Window : public Subject {
public:
  Window();
  void Open(int width, int height, std::string name);

private:
  sf::RenderWindow _window;
};
}  // namespace Gui
