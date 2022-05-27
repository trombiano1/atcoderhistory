#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<vector<ll>> G;
vector<bool> seen;

    void dfs(ll current){
    seen[current] = true;
    if (current != 1){
        cout << " ";
    }
    cout << current;
    for (auto i : G[current]){
        if (seen[i] == false){
            dfs(i);
            cout << " " << current;
        }
    }
}

int main(void) {
    ll n, a, b;
    cin >> n;
    G.resize(n+1);
    seen.resize(n+1);
    for (auto i : seen){
        i = false;
    }
    
    for (auto i = 0; i < n-1; i++){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (auto i = 0; i <= n; i++){
        sort(G[i].begin(),G[i].end());
    }

    dfs(1);
    cout << endl;

    return 0;
}






// #include <bits/stdc++.h>

// using namespace std;

// #define ll long long
// #define rep(i, n) for (int i = 0; i < (int)(n); i++)

// int main(void) {
//     ll n, a, b;
//     cin >> n;
//     vector<deque<ll>> G(n+5);
//     vector<ll> first(n+5);
//     for (unsigned int i = 0; i < first.size(); i++){
//         first[i] = -1;
//     }
//     for (auto i = 0; i < n-1; i++){
//         cin >> a >> b;
//         a--; b--;
//         G[a].push_back(b);
//         G[b].push_back(a);
//     }
//     for (auto i = 0; i <= n; i++){
//         sort(G[i].begin(), G[i].end());
//     }
//     ll current = 0;
//     first[0] = 0;
//     while (1){
//         cout << current + 1;
//         bool found = false;
//         for (auto i : G[current]){
//             // cout << "i" << i << first[i] << endl;
//             if (first[i] != -1){
//                 G[current].pop_front();
//             } else {
//                 first[i] = current;
//                 current = i;
//                 found = true;
//                 cout << " ";
//                 break;
//             }
//         }
//         if (!found){
//             if (current == 0) {
//                 break;                
//             } else {
//                 current = first[current]; cout << " ";
//             }
//         } 
//     }
//     cout << endl;
//     return 0;
// }