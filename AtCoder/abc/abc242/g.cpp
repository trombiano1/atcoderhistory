#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include "../../onlinejudge/dump.cpp"
#else
#define dump(...)
#endif

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
    }
    int q;
    cin >> q;
    vector<tuple<int, int, int>> queries(q); // l, r, #
    for (int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        l--; r--;
        queries[i] = {l, r, i};
    }

    sort(queries.begin(), queries.end());
    // int block_size = n / sqrt(q);
    int block_size = 400;
    
    vector<tuple<int, int, int>> sorted_q;

    sorted_q = queries;
    sort(sorted_q.begin(), sorted_q.end(), [&](auto a, auto b){
        return make_pair(get<0>(a) / block_size, get<1>(a)) < make_pair(get<0>(b) / block_size, get<1>(b));
    });
    // int block = 0;
    // for (int i = 0; i < q; i++){
    //     if (get<0>(queries[i]) >= (block+1) * block_size){
    //         block_size++; // next block;
    //         sort(small_q.begin(), small_q.end(), [&](auto const& a, auto const& b){
    //             return get<1>(a) < get<1>(b);
    //         });
    //         sorted_q.insert(sorted_q.end(), small_q.begin(), small_q.end());
    //         small_q = {};
    //     }
        
    //     small_q.push_back(queries[i]);
    // }
    // sorted_q.insert(sorted_q.end(), small_q.begin(), small_q.end());
    // dump("sort done");

    // dump(sorted_q);
    
    int l = -1, r = -1;
    long long res = 0;
    vector<bool> c(n);
    vector<int> result(q);

    for (auto [nl, nr, pos] : sorted_q){

        while (r < nr){
            r++;
            if (c[a[r]] == 1){
                res++;
                c[a[r]] = 0;
            } else {
                c[a[r]] = 1;
            }
        }

        while (l < nl - 1){
            // dump(l, r, res, c);
            l++;
            if (c[a[l]] == 1){
                c[a[l]] = 0;
            } else {
                res--;
                c[a[l]] = 1;
            }
        }

        while (l >= nl){
            // dump(l, r, res, c);
            if (c[a[l]] == 1){
                res++;
                c[a[l]] = 0;
            } else {
                c[a[l]] = 1;
            }
            l--;
        }

        while (r > nr){
            if (c[a[r]] == 1){
                c[a[r]] = 0;
            } else {
                res--;
                c[a[r]] = 1;
            }
            r--;
        }

        result[pos] = res;
        // dump(c, res, l, r, pos);
    }
    for (int i : result){
        cout << i << endl;
    }
    return 0;
}