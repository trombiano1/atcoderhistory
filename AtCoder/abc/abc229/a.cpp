#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void) {
    string s1, s2;
    cin >> s1 >> s2;
    if ((s1 == ".#" && s2 == "#.") || (s1 == "#." && s2 == ".#")){
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}