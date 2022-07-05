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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int index = 0;
    for(int i = 0; i < q; i++){
        int t, x;
        cin >> t >> x;
        if (t == 1){
            index -= x;
            index %= n;
            if (index < 0) index += n;
        } else {
            int n_i = (index + x - 1) % n;
            if (n_i < 0) n_i += n;
            cout << s[n_i] << endl;
        }
        dump(index);
    }
    return 0;
}