#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1e9
#define LINF 100000000000000000LL
#define all(x) begin(x), end(x)

#ifdef DEBUG_
#include "../../onlinejudge/dump.cpp"
#else
#define dump(...)
#endif

bool nthdigit(int x, int n)
{
    while (n--) {
        x /= 2;
    }
    return (x % 2);
}

int main(void) {
    int n, c;
    cin >> n >> c;
    vector<pair<int, ll>> ops(n);
    for(int i = 0; i < n; i++){
        ll t, a;
        cin >> t >> a;
        ops[i] = {t, a};
    }
    vector<vector<bool>> res0(30);
    for(int i = 0; i < 30; i++){
        res0[i].resize(n+1);
        res0[i][0] = 0;
        for(int j = 1; j < n+1; j++){
            int t; ll a;
            t = ops[j-1].first;
            a = ops[j-1].second;

            if (t == 1){
                res0[i][j] = res0[i][j-1] & (a & ( 1 <<  i)) >> i;
            }
            if (t == 2){
                res0[i][j] = res0[i][j-1] | (a & ( 1 <<  i)) >> i;
            }
            if (t == 3){
                res0[i][j] = res0[i][j-1] ^ (a & ( 1 <<  i)) >> i;
            }
        }
    }

    vector<vector<bool>> res1(30);
    for(int i = 0; i < 30; i++){
        res1[i].resize(n+1);
        res1[i][0] = 1;
        for(int j = 1; j < n+1; j++){
            int t; ll a;
            t = ops[j-1].first;
            a = ops[j-1].second;

            if (t == 1){
                res1[i][j] = res1[i][j-1] & (a & ( 1 <<  i)) >> i;
            }
            if (t == 2){
                res1[i][j] = res1[i][j-1] | (a & ( 1 <<  i)) >> i;
            }
            if (t == 3){
                res1[i][j] = res1[i][j-1] ^ (a & ( 1 <<  i)) >> i;
                dump(i, j, res1[i][j-1], (a & ( 1 <<  i)) >> i, res1[i][j]);
            }
        }
    }
    dump(res0, res1);
    vector<ll> x(30);
    for(int i = 0; i < 30; i++){
        x[i] = nthdigit(c, i);
    }
    dump(x);
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 30; j++){
            if (x[j] == 0){
                x[j] = res0[j][i];
            } else {
                x[j] = res1[j][i];
            }
        }
        dump(x);
        ll res = 0;
        for(int j = 29; j >= 0; j--){
            res *= 2;
            res += x[j];

        }
        cout << res << endl;
    }
    return 0;
}