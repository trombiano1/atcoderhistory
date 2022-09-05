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
    int n, k;
    cin >> n >> k;
    vector<int> t(n+1);
    vector<long long> y(n+1);
    t[0] = 1;
    y[0] = 0;
    for (int i = 1; i < n+1; i++){
        cin >> t[i] >> y[i];
    }
    priority_queue<long long> deleted; // 削除するリスト
    int replace_count = 0;
    long long not_que_sum = 0;
    long long pos_sum = 0;
    long long res = -1e18;
    for (int j = n; j >= 0; j--){
        if (t[j] == 1){
            // before replace
            if (k >= replace_count){
                res = max(res, y[j] + pos_sum + not_que_sum);
            }
            // next
            replace_count++;
            if ((int)deleted.size() >= k - (replace_count) && (int)deleted.size() >= 1){
                long long dltd = deleted.top();
                deleted.pop();
                not_que_sum += dltd;
            }
        } else {
            // add
            if (y[j] >= 0){
                pos_sum += y[j];
            } else {
                if ((int)deleted.size() < k - (replace_count)){ // まだ消せる
                    deleted.push(y[j]);
                } else { // もう消せない. 消しても被害が小さいやつ(大きいやつ)を戻す.
                    deleted.push(y[j]);
                    long long dltd = deleted.top();
                    deleted.pop();
                    not_que_sum += dltd;
                }
            }
        }
    }
    assert(res != -1e18);
    cout << res << endl;
    return 0;
}