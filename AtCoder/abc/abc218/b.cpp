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
    vector<int> a(26);
    for (int i = 0; i < 26; i++){
        cin >> a[i];
        cout << (char)(a[i]-1+'a');
    }
    cout << endl;
    return 0;
}