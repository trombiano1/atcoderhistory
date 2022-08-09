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
    long long n, l, r;
    cin >> n >> l >> r;
    vector<long long> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<long long> diff(n);
    vector<long long> diff_sum(n);
    long long sum = 0;
    for (int i = 0; i < n; i++){
        diff[i] = l - a[i];
        sum += a[i];
    }
    diff_sum[0] = diff[0];
    for (int i = 1; i < n; i++){
        diff_sum[i] = diff[i] + diff_sum[i-1];
    }
    dump(diff_sum);
    vector<long long> diff_sum_min(n);
    diff_sum_min[0] = min(diff_sum[0], (long long)0);
    for (int i = 1; i < n; i++){
        diff_sum_min[i] = min(diff_sum[i], diff_sum_min[i-1]);
    }
    dump(diff_sum_min);
    long long result = 0;
    long long right_diff = 0;
    result = min(diff_sum_min[n-1], (long long)0);
    for (int i = 0; i < n; i++){
        right_diff += r - a[n-i-1];
        if (i != n-1){
            result = min(result, right_diff + diff_sum_min[n-i-2]);
        } else {
            result = min(result, right_diff);
        }
    }
    cout << sum + result << endl;
    return 0;
}