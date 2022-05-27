#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;

int main() {
  int occurrences = 0;

  std::string::size_type pos = 0;
  std::string s;
  cin >> s;
  std::string target = "ZONe";
  while ((pos = s.find(target, pos )) != std::string::npos) { 
          ++ occurrences;
          pos += target.length();
  } 
  cout << occurrences << endl;
  return 0;
}