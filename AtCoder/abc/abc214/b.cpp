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
    long long s, t;
    cin >> s >> t;
    long long res = 0;
    for (long long a = 0; a <= s; a++){
        for (long long b = 0; b <= s; b++){
            for (long long c = 0; c <= s; c++){
                if (a + b + c <= s && a * b * c <= t){
                    res++;
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}