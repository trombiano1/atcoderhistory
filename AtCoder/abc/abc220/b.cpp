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

struct NAry {
    map<ll, char> dict_d2n;
    map<char, ll> dict_n2d;
    int base;

    // init
    NAry(int base_){
        base = base_;
        // 0 ~ 9
        for(int i = 0; i < 10; i++){
            dict_d2n[i] = (char)('0' + i);
            dict_n2d[(char)('0' + i)] = i;
        }
        // a ~ f (16進法)
        for(int i = 10; i < 16; i++){
            dict_d2n[i] = (char)('a' + i - 10);
            dict_n2d[(char)('a' + i - 10)] = i;
        }
    }

    // decimal to n-ary
    string d2n(ll n){
        if (n == 0) return "0";
        string res = "";
        while (n > 0){
            res = dict_d2n[n % base] + res;
            n /= base;
        }
        return res;
    }

    // n-ary to decmial
    ll n2d(string n){
        ll res = 0;
        for(size_t i = 0; i < n.size(); i++){
            res *= base;
            res += dict_n2d[n[i]];
        }
        return res;
    }
};

int main(void) {
    int k;
    cin >> k;
    string a, b;
    cin >> a >> b;
    NAry nary(k);
    cout << nary.n2d(a) * nary.n2d(b) << endl;
    return 0;
}