#ifndef CIRCLE_H
#define CIRCLE_H
#include "BasicShape.h"

class Circle : public BasicShape
{
 private:
  long centerX;
  long centerY;
  double radius;

 public:
  Circle(long sCenterX, long sCenterY, double sRadius)
    {
      centerX = sCenterX;
      centerY = sCenterY;
      radius = sRadius;
      calcArea();
    }
  long getCenterX()
  {
    return centerX;
  }
  long getCenterY()
  {
    return centerY;
  }
  void calcArea()
  {
    setArea(3.14159 * radius * radius);
  }
};
      


#endif
