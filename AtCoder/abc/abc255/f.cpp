#include <iostream>
using namespace std;

int n;
int P[200005], I[200005], Iinv[200005];
int L[200005], R[200005];

bool solve(int s, int t, int S, int T)
{
  int r = P[s], p = Iinv[r];
  if(p < S || T < p) return false;

  if(p-S > 0){
    L[r] = P[s+1];
    if(!solve(s+1, s+p-S, S, p-1)) return false;
  }
  if(T-p > 0){
    R[r] = P[s+p-S+1];
    if(!solve(s+p-S+1, t, p+1, T)) return false;
  }
  return true;
}

int main(void)
{
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> P[i];
  for(int i = 1; i <= n; i++) cin >> I[i];
  for(int i = 1; i <= n; i++) Iinv[I[i]] = i;

  if(P[1] != 1 || !solve(1, n, 1, n)){
    cout << -1 << endl;
    return 0;
  }
  for(int i = 1; i <= n; i++) cout << L[i] << " " << R[i] << endl;

  return 0;
}
