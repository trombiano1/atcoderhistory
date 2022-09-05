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
    if (s == "Sunny"){
        cout << "Cloudy" << endl;
    } else if (s == "Cloudy"){
        cout << "Rainy" << endl;
    } else {
        cout << "Sunny" << endl;
    }
    return 0;
}