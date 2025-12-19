#include "arrayFuncs.h"
#include "tddFuncs.h"
using namespace std;

int main() {

  int empty[]={};
  cerr << "ERROR: maxOfArray called with size < 1" << endl;
  maxOfArray(empty,0);
  return 1;

}
