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
    string s;
    cin >> s;
    if (n % 2 == 1){
        if (s[n-1] == 'A'){
            cout << "Yes" << endl;
            return 0;
        }
        if (s[0] == 'B'){
            cout << "Yes" << endl;
            return 0;
        }
        cout << "No" << endl;
    }
    if (n % 2 == 0){
        if (n == 2){
            if (s[0] == s[1]){
                cout << "Yes" << endl;
                return 0;
            } else {
                cout << "No" << endl;
                return 0;
            }
        }
        if (s[0] == 'A' && s[n-1] == 'B'){
            cout << "No" << endl;
            return 0;
        }
        cout << "Yes" << endl;
    }
    return 0;
}