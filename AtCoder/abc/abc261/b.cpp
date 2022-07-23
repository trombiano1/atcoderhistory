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

int main(void) {
    int n;
    cin >> n;
    vector<vector<char>> a(n);
    for(int i = 0; i < n; i++){
        a[i].resize(n);
        string s;
        cin >> s;
        for(int j = 0; j < n; j++){
            dump(s[j]);
            a[i][j] = s[j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (a[i][j] == 'W'){
                if (a[j][i] == 'L'){
                    continue;
                }
            }
            if (a[i][j] == 'L'){
                if (a[j][i] == 'W'){
                    continue;
                }
            }
            if (a[i][j] == 'D'){
                if (a[j][i] == 'D'){
                    continue;
                }
            }
            if (a[i][j] == '-'){
                continue;
            }
            cout << "incorrect" << endl;
            return 0;
        }
    }
    cout << "correct" << endl;
    return 0;
}