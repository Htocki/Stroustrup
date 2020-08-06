#pragma once

#include <initializer_list>
#include <vector>

#include "Color.h"
#include "Linestyle.h"
#include "Point.h"

class Shape {
public:
  void Draw() const;
  virtual void Move(int dx, int dy);

  void Set_color(Color color);
  Color Color() const;

  void Set_style(LineStyle line_style);
  LineStyle Style() const;

  void Set_fill_color(Color color);
  Color Fill_color() const;

  Point Point(int number) const;
  int Number_of_points() const;

  // Предотвращение копирования
  Shape(const Shape&) = delete;
  Shape& operator=(const Shape&) = delete;

  virtual ~Shape() {}

protected:
  Shape {};
  Shape(std::initializer_list<Point> list);
  virtual void Draw_lines() const;
  void Add(Point point);
  void Set_point(int number, Point point);

private:
  std::vector<Point> _points;
  Color _line_color;  // Также текста
  LineStyle _line_style;
  Color _fill_color { Color::invisible };
};
