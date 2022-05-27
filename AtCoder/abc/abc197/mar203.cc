#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional>
using namespace std;

int main(){
  int H, W, X, Y;
  cin >> H >> W >> X >> Y;
  char *s;
  string si;
  s = (char*)malloc(H*W * sizeof(char));
  int count = 0;
  for(int i = 0; i < H; i++){
    cin >> si;
    for(int j = 0; j < W; j++){
      if(si[j] == '.'){
        s[i*W+j] = 0;
      } else {
        s[i*W+j] = 1;
      }
    }
  }
  for(int i = X-2; i >= 0; i--){
    if(s[i*W+Y-1] != 0){
      break;
    }
    count++;
  }
  for(int i = X; i < H; i++){
    if(s[i*W+Y-1] != 0){
      break;
    }
    count++;
  }
  for(int i = Y-2; i >= 0; i--){
    if(s[(X-1)*W+i] != 0){
      break;
    }
    /*    cout << "line: " << i << endl;*/
    count++;
  }
  for(int i = Y; i < W; i++){
    if(s[(X-1)*W+i] != 0){
      break;
    }
    count++;
  }
  count++;
  cout << count << endl;
  free(s);
  return 0;
}
