#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional>
using namespace std;

int main(){
  string A;
  cin >> A;
  for(int i = 1; i < A.length();i++){
    cout << A[i];
  }
  cout << A.front() << endl; 
  return 0;
}
