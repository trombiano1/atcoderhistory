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
    string s;
    cin >> s;
    vector<string> dow = { "SUN","MON","TUE","WED","THU","FRI","SAT" };
    for(int i = 0; i < 7; i++){
        if (s == dow[i]){
            cout << 7-i << endl;
            return 0;
        }
    }
    return 0;
}