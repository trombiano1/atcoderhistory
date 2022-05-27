#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void) {
    string s;
    cin >> s;
    ll y = s[s.size()-1]-'0';
    
    ll x = stoi(s);
    cout << x;
    if (0 <= y && y <= 2){
        cout << "-" << endl;
    } else if (3 <= y && y <= 6){
        cout << endl;
    } else{
        cout << "+" << endl;
    }
    return 0;
}