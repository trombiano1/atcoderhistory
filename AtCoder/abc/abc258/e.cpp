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

struct IntDefaultedToMinusOne
{
    int i = -1;
};

int main(void) {
    int n, q, x;
    cin >> n >> q >> x;
    vector<ll> w(n);
    ll all_sum = 0;
    for(int i = 0; i < n; i++){
        cin >> w[i];
        all_sum += w[i];
    }
    dump(w);
    vector<ll> c(n);
    for(int i = 0; i < n; i++){
        c[i] = n * (x/all_sum);
    }
    x %= all_sum;
    dump(c);
    ll right = 0, sum = 0;
    for(int left = 0; left < n; left++){
        if (right < left){
            right = left;
            sum = 0;
        }
        while (sum < x){
            sum += w[right%n];
            right++;
        }
        dump(left, right, sum);
        c[left] += right - left;
        
        sum -= w[left];
    }
    dump(c);
    vector<ll> p;
    map<int, IntDefaultedToMinusOne> used;
    int p_c = 0;
    p.push_back(p_c);
    int first;
    for(int count = 1;;count++){
        int p_n = (p_c + c[p_c]) % n;
        dump(p_n);
        if (used[p_n].i != -1){
            first = used[p_n].i;
            break;
        }
        p.push_back(p_n);
        used[p_n].i = count;
        p_c = p_n;
    }
    dump(p, first);
    for(int i = 0; i < q; i++){
        ll k;
        cin >> k;
        k--;
        if (k < first){
            cout << c[p[k]] << endl;
        } else {
            cout << c[p[first+(k-first)%(p.size()-first)]] << endl;
        }
    }
    return 0;
}