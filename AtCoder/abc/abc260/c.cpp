#include <iostream>
using namespace std;
long long N, X, Y, r[12], b[12];
int main() {
  cin >> N >> X >> Y;
  r[1] = 0, b[1] = 1;
  for (int n = 2; n <= N; n++) {
    b[n] = r[n - 1] + b[n - 1] * Y;
    r[n] = r[n - 1] + b[n] * X;
  }
  cout << r[N] << "\n";
}
