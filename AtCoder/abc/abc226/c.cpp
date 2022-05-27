#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<bool> seen(200000,false);
vector<ll> k;
vector<ll> t;
vector<vector<ll>> a;

void dfs(ll n){
    seen[n] = true;
    for(auto j: a[n]){
        if (!seen[j]){
            dfs(j);
        }
    }
}

int main() {
    ll n, input;
    cin >> n;
    seen.resize(n);
    k.resize(n);
    a.resize(n);
    t.resize(n);
    for(auto i = 0; i < n; i++){
        cin >> t[i];
        cin >> k[i];
        for(auto j = 0; j < k[i]; j++){
            cin >> input;
            a[i].push_back(input-1);
        }
    }
    dfs(n-1);
    unsigned long long total = 0;
    for(auto i = 0; i < n; i++){
        if(seen[i]){
            total += t[i];
        }
        // cout << "i:" << i << " seen:" << seen[i] << endl;
    }
    cout << total << endl;

    return 0;
}