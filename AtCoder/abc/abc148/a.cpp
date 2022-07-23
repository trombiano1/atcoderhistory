#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1e9
#define LINF 100000000000000000LL
#define all(x) begin(x), end(x)

#ifdef DEBUG_
#include "../../onlinejudge/dump.cpp"
#else
#define dump(...)
#endif

int main(void) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    vector<int> count(3);
    count[a]++;
    count[b]++;
    for(int i = 0; i < 3; i++){
        if (count[i] == 0){
            cout << i+1 << endl;
        }
    }
    
    return 0;
}