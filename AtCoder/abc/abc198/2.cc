#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;

int main() {
  int n;
  int q;
  string s;
  int t, a, b;
  int s_n[400000];
  int flag = 1;
  int temp;
  cin >> n;
  cin >> s;
  cin >> q;
  for(int i = 0; i < 2*n; i++){
    s_n[i] = i;
  }
  for(int i = 0; i < q; i++){
    cin >> t >> a >> b;
    a -= 1;
    b -= 1;
    if(t == 2){
      flag *= -1;
    } else {
      if(flag == -1){
        if(a >= n){ a -= n; } else {a += n;}
        if(b >= n){ b -= n; } else {b += n;}
      }
      temp = s_n[a];
      s_n[a] = s_n[b];
      s_n[b] = temp;
    }
  }
  if(flag == 1){
    for(int i = 0; i < 2*n; i ++){
      cout << s[s_n[i]];
    }
  } else {
    for(int i = 0; i < n; i ++){
      cout << s[s_n[i+n]];
    }
    for(int i = n; i < 2*n; i ++){
      cout << s[s_n[i-n]];
    }
  }
  cout << endl;
  return 0;
}
