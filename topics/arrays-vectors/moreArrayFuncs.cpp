#include <cassert>
#include "moreArrayFuncs.h"
#include <climits>

int indexOfMax(int *a, int size) {
  assert(size >= 1);
  int maxVal = INT_MIN;
  int index = 0;
  for (int i=0;i<size;i++){
    if (a[i]>maxVal){
      maxVal = a[i];
      index = i;
    }
  }
  return index;
}

int indexOfMin(int *a, int size) {
  assert(size >= 1);
  int minVal = INT_MAX;
  int index = 0;
  for (int i=0;i<size;i++){
    if (a[i]<minVal){
      minVal = a[i];
      index = i;
    }
  }
  return index;
}

int largestValue(int *a, int size) {
  assert(size >= 1);
  int maxVal = INT_MIN;
  for (int i=0;i<size;i++){
    if (a[i]>maxVal){
      maxVal = a[i];
    }
  }
  return maxVal;
}

int smallestValue(int *a, int size) {
  assert(size >= 1);
  int minVal = INT_MAX;
  for (int i=0;i<size;i++){
    if (a[i]<minVal){
      minVal = a[i];
    }
  }
  return minVal;
}

int sum(int *a, int size) {
  int sum = 0;
  if (size<1){
    return 0;
  }
  for (int i=0;i<size;i++){
    sum += a[i];
  }
  return sum;
}

void copyElements(int *dest, int *src, int n) {
  for (int i=0;i<n;i++){
    dest[i]=src[i];
  }
}

int copyOddOnly(int *dest, int *src, int n) {
  int count = 0;
  for (int i=0;i<n;i++){
    if (src[i]%2!=0){
      dest[count]=src[i];
      count++;
    }
  }
 return count; 
}

void multiplyPairwise(int *a, int *b, int *product, int n) {
  for (int i=0;i<n;i++){
    product[i]=(a[i]*b[i]);
  }
}

// len is the number of elements the array you create should contain
// you should return a pointer to the new integer array of size len
// with all of the elements in it set to 0
int* createArray(int len) {
  int* newArr = new int[len];
  for (int i=0;i<len;i++){
    newArr[i]=0;
  }
  return newArr;
}
