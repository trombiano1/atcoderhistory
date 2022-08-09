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
    vector<int> p(n);
    for(int i = 1; i < n; i++){
        cin >> p[i];
        p[i]--;
    }
    int par = n-1;
    int count = 0;
    dump(p);
    for (;;){
        if (par == 0){
            break;
        }
        par = p[par];
        dump(par);
        count++;
    }
    cout << count << endl;
    return 0;
}