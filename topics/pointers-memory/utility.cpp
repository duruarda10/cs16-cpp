#include <cmath>

bool approxEqual(double a, double b, double tolerance){
  return fabs(a-b)<tolerance;
}
