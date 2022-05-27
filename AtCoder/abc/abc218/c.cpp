#include <bits/stdc++.h>

using namespace std;
#define dump(x)  cout << #x << " = " << (x) << endl;
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define VECCOUT(x) for(auto&y: (x) )cout<<y<<" ";cout<<endl

int main(void) {
    ll n;
    cin >> n;
    string str;
    vector<vector<bool>> s(n);
    vector<int> s_cv(n);
    vector<int> s_ch(n);
    vector<vector<bool>> t(n);
    vector<int> t_cv(n);
    vector<int> t_ch(n);
    for (auto i = 0; i < n; i++){
        s[i].resize(n);
        ll c = 0;
        cin >> str;
        for (auto j = 0; j < n; j++){
            if (str[j] == '.'){
                s[i][j] = false;
            } else {
                s[i][j] = true;
                c++;
            }
        }
        s_cv[i] = c;
    }

    for (auto j = 0; j < n; j++){
        ll c = 0;
        for (auto i = 0; i < n; i++){
            if (s[i][j] == true){
                c++;
            }
        }
        s_ch[j] = c;
    }
    for (auto i = 0; i < n; i++){
        t[i].resize(n);
        ll c = 0;
        cin >> str;
        for (auto j = 0; j < n; j++){
            if (str[j] == '.'){
                t[i][j] = false;
            } else {
                t[i][j] = true;
                c++;
            }
        }
        t_cv[i] = c;
    }

    for (auto q = 0; q < 4; q++){
        vector<vector<bool>> t_new(n);
        for (auto i = 0; i < n; i++){
            t_new[i].resize(n);
            for (auto j = 0; j < n; j++){
                t_new[i][j] = t[j][n-i-1];
            }
        }
        swap(t,t_new);

        for (auto i = 0; i < n; i++){
            ll c = 0;
            for (auto j = 0; j < n; j++){
                if (t[i][j] == true){
                    c++;
                }
            }
            t_cv[i] = c;
        }

        for (auto j = 0; j < n; j++){
            ll c = 0;
            for (auto i = 0; i < n; i++){
                if (t[i][j] == true){
                    c++;
                }
            }
            t_ch[j] = c;
        }
        // VECCOUT(t_cv);
        // VECCOUT(t_ch);
        vector<ll> match_v;

        for (int i = -n+1; i < n; i++){
            bool sameflag = true;
            for (int j = min(i,0); j < max(n+i,n); j++){
                ll a = false, b = false;
                if (j + i >= 0 && j + i < n){
                    a = s_cv[j+i];
                }
                if (j >= 0 && j < n){
                    b = t_cv[j];
                }
                if (a != b){
                    sameflag = false;
                    break;
                }
                // s_cv[j+i] == t_cv[j]; 同じなら
            }
            if (sameflag) match_v.push_back(i);
        }
        // VECCOUT(match_v);

        vector<ll> match_h;
        for (int i = -n+1; i < n; i++){
            bool sameflag = true;
            for (int j = min(i,0); j < max(n+i,n); j++){
                ll a = false, b = false;
                if (j + i >= 0 && j + i < n){
                    a = s_ch[j+i];
                }
                if (j >= 0 && j < n){
                    b = t_ch[j];
                }
                if (a != b){
                    sameflag = false;
                    break;
                }
                // s_cv[j+i] == t_cv[j]; 同じなら
            }
            if (sameflag) match_h.push_back(i);
        }
        // VECCOUT(match_h);

        for (auto x_offset : match_v){
            for (auto y_offset : match_h){
                bool nope = false;
                for (int i = 0; i < n; i++){
                    for (int j = 0; j < n; j++){
                        if (i-x_offset >= 0 && i-x_offset < n & j-y_offset >= 0 && j-y_offset < n){
                            if (s[i][j] != t[i-x_offset][j-y_offset]){
                                nope = true;
                                break;
                            }
                        }
                    }
                    if (nope) break;
                }
                if (!nope){
                    // cout << "Yes" << x_offset << " " << y_offset << endl;
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}