#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

namespace Gui {
class Observer {
 public:
  virtual void Draw(sf::RenderWindow& window) = 0;

 protected:
  Observer() {}
};
}  // namespace Gui
