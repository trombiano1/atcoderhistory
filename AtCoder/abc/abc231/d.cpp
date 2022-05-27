#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
#include<algorithm>
#include<functional>
#include<vector>
#include<map>
using namespace std;

map<long long, int> mp;
vector<bool> seen;

bool dfs(const vector<vector<long long>> &G, int v){
    // cout << "dfs" << v+1 << endl;
    seen[v] = true;
    // cout << "v " << v << endl;
    int seencount = 0;
    for(auto next_v : G[v]){
        // cout << "v " << next_v << endl;
        if (seen[next_v]) seencount++;
        // cout << v+1 << next_v+1 << " s " << seencount << endl;
        if (seencount >= 2){
            // cout << "END" << endl;
            return false;
        }
        if (seen[next_v]) continue;
        if (!dfs(G,next_v)){
            return false;
        }
    }
    return true;
}

int main() {
    long long N, M, a, b;
    cin >> N >> M;
    vector<vector<long long>> G(N);
    for(auto i = 0; i < M; i++){
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
        mp[a]++;
        mp[b]++;
        if(mp[a] >= 3 || mp[b] >= 3){
            cout << "No" << endl;
            return 0;
        }
    }
    seen.assign(N,false);
    for(auto i = 0; i < N; i++){
        // cout << i << endl;
        if (G[i].size() == 0) continue;
        if (seen[i]) continue;
        // cout << "i " << i << " " << dfs(G, i) << endl;
        if (!dfs(G, i)){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}