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
    string s;
    string t;
    cin >> s >> t;
    vector<pair<char, ll>> s_list;
    char last = '0';
    for(int i = 0; i < s.size(); i++){
        if (s[i] != last){
            last = s[i];
            s_list.push_back({s[i], 1});
        } else {
            s_list[s_list.size()-1].second++;
        }
    }
    vector<pair<char, ll>> t_list;
    last = '0';
    for(int i = 0; i < t.size(); i++){
        if (t[i] != last){
            last = t[i];
            t_list.push_back({t[i], 1});
        } else {
            t_list[t_list.size()-1].second++;
        }
    }
    dump(s_list, t_list);
    if (s_list.size() != t_list.size()){
        cout << "No" << endl;
        return 0;
    }
    for(int i = 0; i < s_list.size(); i++){
        if (s_list[i].first != t_list[i].first){
            cout << "No" << endl;
            return 0;
        }
        if (s_list[i].second > t_list[i].second){
            cout << "No" << endl;
            return 0;
        }
        if (s_list[i].second < t_list[i].second && s_list[i].second == 1){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}