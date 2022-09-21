#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG_
#include "../../onlinejudge/dump.cpp"
#else
#define dump(...)
#endif

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    int m;
    cin >> n >> m;
    vector<pair<long long, int>> e(m);
    for (int i = 0; i < m; i++) {
        cin >> e[i].first >> e[i].second;
    }
    sort(e.begin(), e.end(), [](auto i, auto j){
        return i.second < j.second;
    });
    dump(e);
    long long current = n;
    long long ans = 0;
    for (int i = 0; i < m; i++) {
        long long a, c;
        long long old = current;
        a = e[i].first;
        c = e[i].second;
        current = gcd(current, a);
        ans += c * (old - current);
        dump(current);
    }
    cout << (current == 1 ? ans : -1) << endl;
    return 0;
}