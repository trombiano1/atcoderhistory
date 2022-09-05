#include <iostream>
#include <vector>
#include <algorithm>
#define inf 1e18
using namespace std;
typedef long long ll;

ll N, X, Y;
ll A[20], B[20];
ll dp[1<<18];

int f(int S, int x)
{
  int ret = 0;
  for(int p = 1; p <= N; p++){
    if((S & (1<<(p-1))) == 0 && p < x) ret++;
  }
  return ret;
}

int main(void)
{
  cin >> N >> X >> Y;
  for(int i = 1; i <= N; i++) cin >> A[i];
  for(int i = 1; i <= N; i++) cin >> B[i];

  dp[0] = 0;
  for(int S = 1; S < (1<<N); S++) dp[S] = inf;

  for(int S = 0; S < (1<<N); S++){
    int sizeS = 0;
    for(int i = 1; i <= N; i++) if(S & (1<<(i-1))) sizeS++;
    for(int x = 1; x <= N; x++){
      if(S & (1<<(x-1))) continue;
      dp[S|(1<<(x-1))] = min(dp[S|(1<<(x-1))], dp[S] + abs(A[x] - B[sizeS+1]) * X + f(S, x) * Y);
    }
  }
  cout << dp[(1<<N)-1] << endl;

  return 0;
}
