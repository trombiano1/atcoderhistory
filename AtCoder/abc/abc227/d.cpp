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
    vector<pair<long long, long long>> c(n);
    for (int i = 0; i < n; i++){
        cin >> c[i].first >> c[i].second;
    }
    sort(c.begin(), c.end(), [&](auto i, auto j){
        return i.first + i.second > j.first + j.second;
    });
    set<double> slopes;
    const double inf = numeric_limits<double>::max();
    slopes.insert(0);
    slopes.insert(inf);
    for (auto pr : c){
        double x = (double)(pr.first), y = (double)(pr.second);
        double slope_s = (y - 1) / x;
        double slope_l = y / (x - 1);
        
        double lb = *(slopes.lower_bound(slope_s));
        dump(lb);
        
        slopes.insert(slope_s);
        slopes.insert(slope_l);
        dump(slopes);
    }
    dump(c);
    return 0;
}