#pragma once

class Point3d{

 private:
  int m_x, m_y, m_z;

 public:
  Point3d();
  Point3d(int a, int b, int c);
  void setValues(int newX, int newY, int newZ);
  void printer();
  bool isEqual(Point3d point2);
  double distanceTo(Point3d point2);

};
