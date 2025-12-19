#include <iostream>
#include <string>
#include <sstream> 
#include <iomanip> 
#include <cmath>
#include "shapes.h"
#include "shapeFuncs.h"
#include "utility.h"
using namespace std;

double distanceBetween(Point p, Point q) {
  double dx = p.x-q.x;
  double dy = p.y-q.y;
  return sqrt(dx*dx+dy*dy);
}

void initPoint(struct Point *p, double xVal, double yVal) {
 (*p).x = xVal;
 (*p).y = yVal; 
}


string pointToString(Point p, int precision) {
  ostringstream oss;
  oss << setprecision(precision); 
  oss << "(" << p.x << "," << p.y << ")";
  return oss.str();
}

string boxToString(Box b, int precision) {
  ostringstream oss;
  oss << setprecision(precision);
  oss << "ul=(" << b.ul.x << "," << b.ul.y << ")," << "w=" << b.width << "," << "h=" << b.height;
  return oss.str();
}
 


bool pointsApproxEqual(Point p1,Point p2,double tolerance) {
    return distanceBetween(p1,p2) < tolerance;
}

bool boxesApproxEqual(Box b1, Box b2, double tolerance) {
  return approxEqual(b1.width, b2.width, tolerance) && approxEqual(b1.height, b2.height, tolerance) && pointsApproxEqual(b1.ul,b2.ul,tolerance);
}

void initBox(struct Box *b, double ulx, double uly, double w, double h)
{
  (*b).ul.x=ulx;
  (*b).ul.y=uly;
  (*b).width=w;
  (*b).height=h;
}

double areaOfBox(Box b) {
  return b.height*b.width;
}
