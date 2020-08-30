#pragma once

#include <vector>

#include <SFML/Graphics/RenderWindow.hpp>

#include "Observer.h"

namespace Gui {
class Window;

class Subject {
 public:
  virtual void Attach(Observer* observer);
  virtual void Detach(Observer* observer);
  virtual void Notify(sf::RenderWindow& window);

 protected:
  Subject() {}

 private:
  std::vector<Observer*> m_observers;
};
}  // namespace Gui
