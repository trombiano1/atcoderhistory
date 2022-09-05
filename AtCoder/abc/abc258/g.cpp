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
    vector<string> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    dump(a);
    vector<bitset<3000>> bits(n);
    for (int i = 0; i < n; i++){
        bits[i] = bitset<3000>(a[i]);
    }
    dump(bits);
    long long res = 0;
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            if (i == j) continue;
            if (a[i][j] != '1') continue;
            res += (bits[i] & bits[j]).count();
        }
    }
    cout << res / 3 << endl;
    return 0;
}