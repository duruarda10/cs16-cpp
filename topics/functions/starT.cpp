#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void assertEquals(string expected, string actual, string message);
string starT(int width, int height);
void runTests(void);

string starT(int width, int height){

if ((width<3)||(height<2)||(width%2==0)){
 return "";
}

 string result = "";
 int halfPoint = width/2;

  for (int i=0;i<width;i++){
  result += '*';
  }
  result += '\n';

  for (int j=1;j<height;j++){
    for (int k=0;k<halfPoint;k++){
      result += ' ';
    }
   result += '*';

   for (int l=halfPoint+1;l<width;l++){
     result += ' ';
   }
  result += '\n';  
  }
  return result;
}

void runTests(void)
{

  string starT34Expected =
      "***\n"
      " * \n"
      " * \n"
      " * \n";

  assertEquals(starT34Expected, starT(3, 4), "starT(3,4)");

  string starT53Expected =
      "*****\n"
      "  *  \n"
      "  *  \n";

  assertEquals(starT53Expected, starT(5, 3), "starT(5,3)");

  string starT72Expected =
      "*******\n"
      "   *   \n";

  assertEquals(starT72Expected, starT(7, 2), "starT(7,2)");

  assertEquals("", starT(1, 2), "starT(1,2)");
  assertEquals("", starT(5, 1), "starT(5,1)");
  assertEquals("", starT(4, 2), "starT(4,2)");
  assertEquals("", starT(6, 2), "starT(6,2)");
}

void assertEquals(string expected, string actual, string message = "")
{
  if (expected == actual)
  {
    cout << "PASSED: " << message << endl;
  }
  else
  {
    cout << "   FAILED: " << message << endl
         << "   Expected:[\n"
         << expected << "] actual = [\n"
         << actual << "]\n"
         << endl;
  }
}

int main(int argc, char* argv[]){

if (argc!=3){
cerr << "Usage: ./starT width height\n";
return 1;
}

int width = atoi(argv[1]);
int height = atoi(argv[2]);

if ((width==-1)&&(height==-1)){
  runTests();
  return 0;
}

cout << starT(width,height);
return 0;
}

