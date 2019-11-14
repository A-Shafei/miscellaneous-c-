#include "Point3d.h"
#include <iostream>
#include <math.h>
using namespace std;

  // Point3d();
  // point3d(int a, int b, int c);
  // void setValues(int newX, int newY, int newZ);
  // void printer();
  // bool isEqual(Point3d point2);
  // double distanceTo(Point3d point2);

Point3d::Point3d(){
  m_x = 1;
  m_y = 1;
  m_z = 1;
}

Point3d::Point3d(int a, int b, int c){
  m_x = a;
  m_y = b;
  m_z = c;
}

void Point3d::setValues(int newX, int newY, int newZ){
  m_x = newX;
  m_y = newY;
  m_z = newZ;
}

void Point3d::printer(){
  cout << "<" << m_x << ", " << m_y << ", " << m_z << ">" << endl;
}

double Point3d::distanceTo(Point3d point2){
  double dist = pow(pow(point2.m_x - m_x , 2) + pow(point2.m_y - m_y , 2) + pow(point2.m_z - m_z , 2) , 0.5);
  return dist;
}
