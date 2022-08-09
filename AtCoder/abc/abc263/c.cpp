#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include "../../onlinejudge/dump.cpp"
#else
#define dump(...)
#endif

int n, m;

vector<string> rec(int begin, int num){
    vector<string> res;
    if (num == 0){
        res.push_back("");
        return res;
    }
    for (int i = begin + 1; i < (m + 1) - (num - 1); i++){
        for (auto j : rec(i, num-1)){
            res.push_back(to_string(i) + " " + j);
        }
    }
    return res;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (auto j : rec(0, n)){
        cout << j << endl;
    }
    return 0;
}