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

vector<pair<long long, long long>> prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数
        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        // その結果を push
        res.push_back({a, ex});
    }
    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}

int main(void) {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> p = prime_factorize(n);
    dump(p);
    ll res = 0;
    for(auto i : p){
        ll num = i.second;
        ll cnt = 0;
        for(int j = 0;;j++){
            if (num < j * (j+1) / 2){
                cnt = j - 1;
                break;
            }
            dump(j*(j+1)/2);
        }
        res += cnt;
    }
    cout << res << endl;
    return 0;
}