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
    long long l;
    cin >> n >> l;

    priority_queue<long long, vector<long long>, greater<long long>> p_que;
    
    long long res = 0;
    long long sum = 0;
    
    for (int i = 0; i < n; i++){
        long long a;
        cin >> a;
        p_que.push(a);
        sum += a;
    }
    if (l - sum > 0){
        p_que.push(l-sum);
    }

    for (; p_que.size() > 1;){
        long long s1 = p_que.top();
        p_que.pop();
        long long s2 = p_que.top();
        p_que.pop();
        res += s1 + s2;
        p_que.push(s1+s2);

        dump(p_que);
    }
    cout << res << endl;
    return 0;
}