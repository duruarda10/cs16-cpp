bool isOdd(int x) { 
  return (x%2!=0);
}

bool isEven(int x) { 
  return !isOdd(x);
}

bool isPrime(int x) { 
 if (x==2){
   return true;
 }

 if ((x<=1)||(isEven(x))){
   return false;
 }

 for (int i=2; i<x;i++){
   if (x%i==0){
     return false;
   }
 }
 return true;
}
