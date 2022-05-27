#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional>
using namespace std;

int main(){
  int N;
  int *a;
  int *t;
  cin >> N;
  a = (int*) malloc(N*sizeof(int));
  t = (int*) malloc(N*sizeof(int));
  for(int i = 0; i < N; i++){
    cin >> a[i] >> t[i];
  }
  int Q;
  cin >> Q;
  int answer = 0;
  for(int j = 0; j < Q; j++){
    cin >> answer;
    for(int i = 0; i < N; i++){
      if(t[i] == 1){
        answer = answer + a[i];
      } else if (t[i] == 2){
        answer =  std::max(answer, a[i]);
      } else if (t[i] == 3){
        answer =  std::min(answer, a[i]);
      }
    }
    cout << answer << endl;
  }
  return 0;
}
