#include<bits/stdc++.h>
#define mod 998244353

using namespace std;

long long power(long long a,long long b){
  long long x=1,y=a;
  while(b>0){
    if(b&1ll){
      x=(x*y)%mod;
    }
    y=(y*y)%mod;
    b>>=1;
  }
  return x%mod;
}

int main(){
  string s;
  cin >> s;
  if(s.size()==1){cout << s << '\n';return 0;}
  long long res=0,del=1,cur=0;
  for(int i=s.size()-1;i>=0;i--){
    cur+=del;cur%=mod;
    long long ce=(cur+del)%mod;
    res+=(s[i]-'0')*ce;res%=mod;
    del*=5;del%=mod;
  }
  res*=power(2,s.size()-2);res%=mod;
  cout << res << '\n';
  return 0;
}
