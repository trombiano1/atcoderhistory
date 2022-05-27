#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;

int main() {
  double N,D,H;
  double d,h;
  double ymax = -1000000;
  double yintercept;
  cin >> N >> D >> H;
  for(int i = 0; i < N; i++){
    cin >> d >> h;
    yintercept = H-((H-h)/(D-d))*D;
    if (ymax < yintercept){
      ymax = yintercept;
    }
  }
  if(ymax < 0){
    ymax = 0;
  }
  cout.precision(17);
  cout << ymax << endl;
  return 0;
}