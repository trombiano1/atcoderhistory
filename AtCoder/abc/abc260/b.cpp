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
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    vector<tuple<bool, int, int, int, int>> p(n); // 合否, math, english, sum, id
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }
    for (int i = 0; i < n; i++){
        p[i] = {0, a[i], b[i], a[i]+b[i], i};
    }
    sort(p.begin(), p.end(), [&](auto i, auto j){
        return make_tuple(-get<1>(i), get<4>(i)) < make_tuple(-get<1>(j), get<4>(j));
    });
    dump(p);
    for (int i = 0; i < x; i++){
        get<0>(p[i]) = 1;
    }
    sort(p.begin(), p.end(), [&](auto i, auto j){
        return make_tuple(get<0>(i), -get<2>(i), get<4>(i)) < make_tuple(get<0>(j), -get<2>(j), get<4>(j));
    });
    for (int i = 0; i < y; i++){
        get<0>(p[i]) = 1;
    }
    sort(p.begin(), p.end(), [&](auto i, auto j){
        return make_tuple(get<0>(i), -get<3>(i), get<4>(i)) < make_tuple(get<0>(j), -get<3>(j), get<4>(j));
    });
    for (int i = 0 ; i < z; i++){
        get<0>(p[i]) = 1;
    }
    dump(p);
    vector<int> ans;
    for (auto i : p){
        if (get<0>(i)){
            ans.push_back(get<4>(i));
        }
    }
    sort(ans.begin(), ans.end());
    for (auto i : ans){
        cout << i + 1 << endl;
    }
    return -0;
}