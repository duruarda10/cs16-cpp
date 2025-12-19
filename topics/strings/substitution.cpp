#include <cctype>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void usage() {
  cout << "USAGE: substitution [-ed] [key]" << endl;
}

string encrypt(string line, string key){
  
  string returnstr = "";
  string alphabet = "abcdefghijklmnopqrstuvwxyz";
  
  for (size_t i=0;i<line.length();i++){
    char c = line[i];
    if (isalpha(c)){
      bool isUpper = isupper(c);
      char lowerc = tolower(c);

      for (int j=0;j<26;j++){
        if (lowerc == alphabet[j]){
	  char encrypted = tolower(key[j]);
	  if(isUpper){
	    encrypted = toupper(encrypted);
	  }
	returnstr += encrypted;
	break;
	}
      }
    
    }
      else{
      returnstr += c;
      }
  }
  return returnstr;
}
 
string decrypt(string line, string key){
  
    string returnstr = "";
    string alphabet = "abcdefghijklmnopqrstuvwxyz";    
    for (size_t i=0;i<line.length();i++){
    char c = line[i];
    if (isalpha(c)){
      bool isUpper = isupper(c);
      char lowerc = tolower(c);

      for (int j=0;j<26;j++){
        if (lowerc == tolower(key[j])){
          char encrypted = alphabet[j];
          if(isUpper){
            encrypted = toupper(encrypted);
          }
        returnstr += encrypted;
        break;
        }
      }
    }
      else{
      returnstr += c;
      }
  }
  return returnstr;
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

  string key = argv[2];
  if (key.length()!=26){
  usage();
  return 1;
  }

  for (int i=0;i<26;i++){
    char c = key[i];
    if (!isalpha(c)){
      usage();
      return 1;
    }
    for (int j=i+1;j<26;j++){
      if (tolower(key[j])==tolower(c)){
      usage();
      return 1;
      }
    }
  }

  string line;
  while (getline(cin,line)){
    if (strcmp(argv[1],"-e")==0){
      cout << encrypt(line,key) << endl;
    }
    else{
      cout << decrypt(line,key) << endl;
    }
  }
  return 0;  
}

