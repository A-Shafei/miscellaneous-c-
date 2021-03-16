#ifndef BASICSHAPE_H
#define BASICSHAPE_H

class BasicShape
{
 private:
  double area;

 public:
  BasicShape()
    {
      area = 0.0;
    }
  void setArea(double sArea)
  {
    area = sArea;
  }
  double getArea()
  {
    return area;
  }
  virtual void calcArea() = 0;
};

#endif
