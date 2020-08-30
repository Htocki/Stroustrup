#pragma once

#include <initializer_list>
#include <vector>

#include "Color.h"
#include "Point.h"

namespace Gui {
class Shape {
public:
  void Draw() const;
  virtual void Move(int dx, int dy);

  void SetColor(Color color);
  void SetFillColor(Color color);

  Color GetColor() const;
  Point GetPoint(int number) const;
  int GetPointsCount() const;

  Shape(const Shape&) = delete;
  Shape& operator=(const Shape&) = delete;

  virtual ~Shape() {}

protected:
  Shape();
  Shape(std::initializer_list<Point> list);
  virtual void DrawLines() const;
  void AddPoint(Point point);
  void SetPoint(int number, Point point);

private:
  std::vector<Point> _points;
  Color _fill_color;
  Color _line_color;
  Color _text_color;
};
}  // namespace Gui
