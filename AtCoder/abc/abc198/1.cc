#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;

int main() {
  int n;
  int input = 0;
  int a_big = 0;
  int b_small = 1000;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> input;
    if(input > a_big){
      a_big = input;
    }
  }
  for(int i = 0; i < n; i++){
    cin >> input;
    if(input < b_small){
      b_small = input;
    }
  }
  if(b_small >= a_big){
    cout << b_small - a_big + 1 << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}
