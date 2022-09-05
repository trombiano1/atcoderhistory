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
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    vector<pair<char, int>> res;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 2; j++) {
            if (p[j] % 2 != p[j + 2] % 2 && p[j]%2 != j % 2) {
                swap(p[j], p[j+2]);
                res.push_back({'B', j});
            }
        }
    }
    dump(p);
    for (int i = 0; i < n - 1; i++){
        if (p[i] % 2 != p[i + 1] && p[i] % 2 == i % 2) {
            swap(p[i], p[i+1]);
            res.push_back({'A', i});
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 2; j++) {
            if (p[j] > p[j + 2]) {
                swap(p[j], p[j + 2]);
                res.push_back({'B', j});
            }
        }
    }
    cout << res.size() << endl;
    for (auto r : res){
        cout << r.first << " " << r.second + 1 << endl;
    }
    return 0;
}