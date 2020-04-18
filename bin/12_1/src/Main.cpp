// Нарисуйте прямоугольник как объект класса Rectangle и как объект класса
// Polygon. Сделайте линии объекта класса Polygon красными, а линии объекта
// класса Rectangle -- синими.

#include <FL/Enumerations.H>
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Window.H>

int main(int argc, char **argv) {
  Fl_Window *window = new Fl_Window(300, 180, "Title");
  window->end();
  window->show(argc, argv);
  return Fl::run();
}
