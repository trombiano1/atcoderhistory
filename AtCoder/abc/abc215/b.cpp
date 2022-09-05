#include<bits/stdc++.h>

using namespace std;

int main(){
  long long n;
  cin >> n;
  for(int i=60;i>=0;i--){
    if(n&(1ll<<i)){cout << i << '\n';break;}
  }
  return 0;
}
