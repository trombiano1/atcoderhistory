#include<iostream>
#include<string>
#include<math.h>
using namespace std;

int main(){
  unsigned long T;
  cin >> T;

  unsigned long L,R;
  unsigned long a;

  int intL;
  int intR;
 
  for(int i = 0; i < T; i++){
    cin >> L >> R;
    intL = (int)L;
    intR = (int)R;
   

    if(intL == intR){
      if(intL == 0){
        a = R+1;
      } else {
        a = 0;
      }
    } else {
      if(intL > 2 * intR){
        a = (R - 2*L + 1)*(R - 2*L + 2)/2;
      } else {
        a = 0;
      }
    }
    
    cout << a << endl;
  }
  
  return 0;
}
