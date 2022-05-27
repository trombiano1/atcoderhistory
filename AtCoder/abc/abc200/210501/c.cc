#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;

int main() {
  std::string s;
  std::string t = "";
  std::string target = "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyyzz";
  int place = 0;
  cin >> s;
  int flag = 1;
  int endf = 1;
  for(int i = 0; i < s.size(); i++){
    if(s[i] == 'R'){
      flag *= -1;
    } else {
      if(flag == 1){
        if(t[t.size()-1] == s[i]){
          t = t.substr(0,t.size()-1);
        } else {
          t += s[i];
        }
      } else {
        if(t[0] == s[i]){
          t = t.substr(1, t.size()-1);
        } else {
          t = s[i] + t;
        }
      }
    }
  }
  // while(endf){
  //   for(int i = 0; i < 26; i++){
  //     place = t.find(target.substr(2*i,2),0);
  //     if(place != std::string::npos){
  //       t = t.substr(0,place) + t.substr(place+2,t.size());
  //       break;
  //     }
  //     if(i == 25){
  //       endf = 0;
  //     }
  //   } 
  // }
  if(flag == -1){
    for(int i = 0; i < t.size(); i++){
      cout << t[t.size()-i-1];
    }
    cout << endl;
  } else {
    cout << t << endl;  
  }
  return 0;
}

//s.find(target, pos )