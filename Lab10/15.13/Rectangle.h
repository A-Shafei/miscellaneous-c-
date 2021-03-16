#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "BasicShape.h"

class Rectangle : public BasicShape
{
 private:
  long width;
  long length;

 public:
  Rectangle(long sWidth, long sLength)
    {
      width = sWidth;
      length = sLength;
      calcArea();
    }
  void calcArea()
    {
      setArea(length*width);
    }
};

#endif
