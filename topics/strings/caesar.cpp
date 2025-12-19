#include <cctype>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void usage() {
  std::cout << "USAGE: caesar [-ed] [key]\n";
}

bool isOnlyDigits (const char* str){
  for (int i=0;str[i]!='\0';i++){
    if (!isdigit(str[i])){
      return false;
    }
  }
  return true;
}

int main(int argc, char** argv) {
  if(argc != 3) {
    usage();
    return 1;
  }

  if (strcmp(argv[1],"-e")!=0 && strcmp(argv[1],"-d")!=0){
    usage();
    return 1;
  }
  
  if (!isOnlyDigits(argv[2])){
    usage();
    return 1;
  }

  int key = stoi(argv[2])%26;
  string alphabetLower = "abcdefghijklmnopqrstuvwxyz"; 
  string alphabetUpper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string line;

  while (getline(cin,line)){
    for (size_t i=0;i<line.size();i++){
      char c = line[i];	    
      if (isalpha(c)){
        bool isUpper = isupper(c);
	string alphabet;
	if (isUpper){
	  alphabet = alphabetUpper;
	}
	else{
	  alphabet = alphabetLower;
	}
        int index = alphabet.find(c);
  
         if (argv[1][1]=='e'){
	     c = alphabet[(index+key)%26];
	 }
	 else{
             c = alphabet[(index-key+26)%26];
	   }
	   line[i] = c;
         }
    }
  cout << line << endl;    
}
return 0;
}
