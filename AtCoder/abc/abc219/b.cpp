#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void) {
    string s[3];
    cin >> s[0] >> s[1] >> s[2];
    string t;
    cin >> t;
    for (int i = 0; i < (int)t.size(); i++){
        cout << s[t[i]-'1'];
    }
    cout << endl;
    return 0;
}