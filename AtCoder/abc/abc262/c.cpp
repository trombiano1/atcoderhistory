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
    vector<long long> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
    }
    dump(a);
    long long same = 0;
    long long diff = 0;
    for (int i = 0; i < n; i++){
        if (a[i] == i){
            same++;
        } else if (a[a[i]] == i){
            diff++;
        }
    }
    cout << (diff / 2) + (same * (same-1) / 2) << endl;
    dump(diff, same);
    return 0;
}