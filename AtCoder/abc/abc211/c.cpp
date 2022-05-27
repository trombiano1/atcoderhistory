
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mod 1000000007

int main(void) {
    ll n;
    string s;
    cin >> s;
    string chokudai = "chokudai";
    n = (ll)s.size();
    vector<vector<ll>> dp;
    dp.resize(9);
    for (auto i = 0; i < 9; i++){
        dp[i].resize(n+1);
        for (auto j = 0; j < n+1; j++){
            dp[i][j] = 0;
        }
    }
    for (auto i = 1; i <= n; i++){
        dp[0][i] = 1;
    }
    for (auto j = 1; j <= 8; j++){
        dp[j][0] = 0;
    }
    dp[0][0] = 1;
    for (auto j = 1; j <= 8; j++){
        for (auto i = 1; i <= n; i++){
            if (chokudai[j-1] != s[i-1]){
                dp[j][i] = dp[j][i-1] % mod;
            }
            if (chokudai[j-1] == s[i-1]){
                dp[j][i] = (dp[j][i-1] + dp[j-1][i-1]) % mod;
            }
        }
    }
    cout << dp[8][n] << endl;
    return 0;
}

// #include <bits/stdc++.h>

// using namespace std;

// #define ll long long
// #define rep(i, n) for (int i = 0; i < (int)(n); i++)
// #define ALL(a)  (a).begin(),(a).end()

// int main(void) {
//     string s;
//     cin >> s;

//     vector<ll> ch(s.size());
//     vector<vector<ll>> mp(8);

//     map<char, ll> c_pos;
//     c_pos['c'] = 0;
//     c_pos['h'] = 1;
//     c_pos['o'] = 2;
//     c_pos['k'] = 3;
//     c_pos['u'] = 4;
//     c_pos['d'] = 5;
//     c_pos['a'] = 6;
//     c_pos['i'] = 7;

//     for (unsigned long i = 0; i < s.size(); i++){
//         mp[c_pos[s[i]]].push_back(i);
//     }
//     for (unsigned long i = 0; i < mp[c_pos['i']].size(); i++){
//         ch[mp[c_pos['i']][i]] = 1;
//     }

//     for (ll lett = 6; lett >= 0; lett--){
//         for (unsigned long i = 0; i < mp[lett].size(); i++){
//             auto itr = lower_bound(ALL(mp[lett+1]), mp[lett][i]);
//             // cout << "pos" << ch[mp[lett+1][itr - mp[lett+1].begin()]] << endl;
//             for (unsigned long j = itr - mp[lett+1].begin(); j < mp[lett+1].size();j++){
//                 ch[mp[lett][i]] = (ch[mp[lett][i]] + ch[mp[lett+1][j]]) % 1000000007;
//             }
//         }
//     }

//     ll ans = 0;
//     for (ll c = 0; c < mp[0].size(); c++){
//         ans += ch[mp[0][c]];
//         ans %= 1000000007;
//     }
//     cout << ans << endl;
//     // for (auto i = 0; i < s.size(); i++){
//     //     cout << s[i] << " " << ch[i] << endl;
//     // }
//     return 0;
// }