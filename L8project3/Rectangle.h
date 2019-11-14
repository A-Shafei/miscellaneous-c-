#pragma once

enum Colors {BLACK, BLUE, RED, GREEN, WHITE, MAX_COLOR_SIZE};

class Rectangle{

public:
  Rectangle();
  Rectangle(double);
  Rectangle(double, double, Colors);
  double getArea();
  double getPerimeter();
  string getColorName(Colors);
  string getColor();
  
private:
  double m_len, m_width;
  const Colors m_color;

}
