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
    multiset<long long> s;
    for (int i = 0; i < n; i++){
        long long a;
        cin >> a;
        s.insert(a);
    }
    long long ans = 0;
    while (s.size() > 1){
        ans++;
        long long la = *(s.rbegin());
        long long sm = *prev(s.rend());
        dump(la, sm, s);
        auto itr = s.find(la);
        if(itr!=s.end()){
            s.erase(itr);
        }
        if (la % sm == 0){
            continue;
        } else {
            s.insert(la % sm);
        }
    }
    cout << ans << endl;
    return 0;
}