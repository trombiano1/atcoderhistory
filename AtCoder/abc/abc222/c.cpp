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

pair<int, int> fight(char a, char b){
    if (a == b){
        return {0, 0};
    }
    if ((a == 'G' && b == 'C')||(a == 'C' && b == 'P')||(a == 'P' && b == 'G')){
        return {1, 0};
    }
    return {0, 1};
}

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(2*n);
    for(int i = 0; i < 2*n; i++){
        a[i].resize(m);
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    dump(a);
    vector<pair<ll, int>> players;
    for(int i = 0; i < 2*n; i++){
        players.push_back({0, i});
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            pair<int, int> res = fight(a[players[2*j].second][i], a[players[2*j+1].second][i]);
            players[2*j].first -= res.first;
            players[2*j+1].first -= res.second;
        }
        sort(all(players));
        dump(players);
    }
    for(int i = 0; i < 2*n; i++){
        cout << players[i].second+1 << endl;
    }
    return 0;
}