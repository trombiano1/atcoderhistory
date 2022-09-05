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
    string x_;
    cin >> x_;
    vector<int> x(26);
    vector<int> x_inv(26);
    for (int i = 0; i < 26; i++){
        x[i] = x_[i]-'a';
        x_inv[x[i]] = i;
    }
    int n;
    cin >> n;
    vector<string> strings(n);
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        for (int j = 0; j < (int)s.size(); j++){
            s[j] = (char)(x_inv[s[j]-'a']+'a');
        }
        strings[i] = s;
    }
    sort(strings.begin(), strings.end());
    for (int i = 0; i < n; i++){
        for (int j = 0; j < (int)strings[i].size(); j++){
            cout << (char)(x[strings[i][j]-'a']+'a');
        }
        cout << endl;
    }
    return 0;
}