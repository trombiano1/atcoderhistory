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
    vector<string> s(n);
    map<string, int> count;
    for(int i = 0; i < n; i++){
        cin >> s[i];
        if (count[s[i]] == 0){
            cout << s[i] << endl;
        } else {
            cout << s[i] << '(' << count[s[i]] << ')' << endl;
        }
        count[s[i]]++;
    }
    return 0;
}