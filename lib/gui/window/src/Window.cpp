#include "Window.h"

#include <SFML/Window/Event.hpp>

namespace Gui {
Window::Window() { }

void Window::Open(int width, int height, std::string name) {
  _window.create(sf::VideoMode(width, height), name);

  while (_window.isOpen()) {
    sf::Event event;
    while (_window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        _window.close();
      }
    }

    _window.clear();
    Notify(_window);
    _window.display();
  }
}
}  // namespace Gui
