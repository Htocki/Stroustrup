#include "Shape.h"

namespace Gui {
void Shape::Draw() const {}

void Shape::Move(int dx, int dy) {}

void Shape::SetColor(Color color) {}

void Shape::SetFillColor(Color color) {}

Color Shape::GetColor() const {
  return Color {};
}

Point Shape::GetPoint(int number) const {
  return Point {};
}

int Shape::GetPointsCount() const {
  return 1;
}

Shape::Shape() {}

Shape::Shape(std::initializer_list<Point> list) {}

void Shape::DrawLines() const {}

void Shape::AddPoint(Point point) {}

void Shape::SetPoint(int number, Point point) {}
}  // namespace Gui
