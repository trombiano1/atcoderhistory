#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  int *a;
  int n = N;
  a = (int*)malloc(N * sizeof(int));
  for(int i = 0; i < N; i++){
    cin >> a[i];
  }
  int output = 0;
    // {0, 1, ..., n-1} の部分集合の全探索
    for (int bit = 0; bit < (1<<n); ++bit) {
        vector<int> S;
        for (int i = 0; i < n; ++i) {
            if (bit & (1<<i)) { // 列挙に i が含まれるか
                S.push_back(i);
            }
        }
        
        cout << bit << ": {";
        for (int i = 0; i < (int)S.size(); ++i) {
            cout << S[i] << " ";
        }
        cout << "}" << endl;
    }
    free(a);
    return 0;
}
