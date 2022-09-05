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
    int n;
    cin >> n;
    int N = 1<<n;

    vector<pair<long long, int>> c(N+1);
    for (int i = 1; i < N+1; i++){
        cin >> c[i].first;
        c[i].second = i;
    }

    vector<bool> b(N);
    b[0] = true;

    sort(c.begin(), c.end());

    dump(c);
    long long ans = 0;
    for (int i = 0; i < N; i++){
        long long x = c[i].second;
        if (b[x]){
            continue;
        } else {
            ans += c[i].first;
            for (int j = 0; j < N; j++){
                if (b[j]){
                    b[j^x] = true;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}