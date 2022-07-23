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
    string s, t;
    cin >> s >> t;
    int pos = -1;
    int c = 0;
    for(int i = 0; i < (int)s.size(); i++){
        if (s[i] == t[i]) continue;
        c++;
        if (c == 2){
            if (pos + 1 != i){
                cout << "No" << endl;
                return 0;
            }
            if (!(s[i - 1] == t[i] && s[i] == t[i-1])){
                cout << "No" << endl;
                return 0;
            }
        }
        if (c > 2){
            cout << "No" << endl;
            return 0;
        }
        pos = i;
        dump(pos);
    }
    if (c == 1){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}