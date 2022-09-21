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
    vector<string> str(n);
    vector<tuple<long long, long long, int>> xy(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        str[i] = s;
        long long x = 0;
        long long y = 0;
        for (int j = 0; j < (int) s.size(); j++) {
            if (s[j] == 'X') {
                x++;
            } else {
                y += s[j] - '0';
            }
        }
        xy[i] = {x, y, i};
    }
    sort(xy.begin(), xy.end(), [&](auto i, auto j) {
        // return get<0>(i) * get<1>(j) > get<0>(j) * get<1>(i);
        // return get<1><(i) / get<0>(i) < get<1>(j) / get<0>(j);
        return get<1>(i) * get<0>(j) < get<1>(j) * get<0>(i);
    });
    long long res = 0;
    long long x_count = 0;
    for (int i = 0; i < n; i++) {
        int now = get<2>(xy[i]);
        dump(str[now]);
        for (int j = 0; j < (int) str[now].size(); j++) {
            if (str[now][j] == 'X') {
                x_count++;
            } else {
                res += x_count * (str[now][j] - '0');
            }
        }
    }
    cout << res << endl;
    return 0;
}