#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1e9
#define LINF 100000000000000000LL
#define all(x) begin(x), end(x)

#ifdef DEBUG_
#include "../../onlinejudge/dump.cpp"
#else
#define dump(...)2
#endif

int main(void) {
    int n, c;
    cin >> n >> c;
    vector<pair<int, ll>> ops(n);
    for(int i = 0; i < n; i++){
        ll t, a;
        cin >> t >> a;
        ops[i] = {t, a};
    }
    vector<vector<int>> b(n+1, vector<int>(2));
    b[0][1] = (1<<30) - 1;
    for(int i = 1; i < n+1; i++){
        for(int j = 0; j < 2; j++){
            int t; ll a;
            t = ops[i-1].first;
            a = ops[i-1].second;

            if (t == 1){
                b[i][j] = b[i-1][j] & a;
            }
            if (t == 2){
                b[i][j] = b[i-1][j] | a;
            }
            if (t == 3){
                b[i][j] = b[i-1][j] ^ a;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        int new_c = 0;
        for(int j = 0; j < 30; j++){
            int k = !!(b[i][(c & (1<<j)) >> j] & (1 << j));
            new_c += k * (1<<j);
        }
        c = new_c;
        cout << c << endl;
    }
    return 0;
}

