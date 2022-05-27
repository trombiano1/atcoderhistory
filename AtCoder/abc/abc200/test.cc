#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;

int main(){
  int n;
  long long ans=0,r=0;
  cin>>n;
  vector <long> A(n+1);
  vector <long> B(n+1);
  for(int i=1;i<=n;i++){
    cin>>B[i];
    A[i]=B[i]%200;
  }
  std::sort(A.begin(),A.end());
  for(int i=1;i<=n;i++){
    //printf("A[%d]=%d\n",i,A[i]);
    if(A[i]==A[i+1]) r++;
    else {
      if(r>0) ans+=(r*(r+1)/2);
      r=0;
    }
  }
  cout<<ans<<"\n";
  return 0;
}