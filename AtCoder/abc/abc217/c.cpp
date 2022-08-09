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
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        int p;
        cin >> p;
        a[p-1] = i+1;
    }
    for (auto v: a){
        cout << v << " ";
    }
    cout << endl;
    return 0;
}