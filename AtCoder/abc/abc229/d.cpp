#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;
#define ll long long 

int main() {
    ll K, s=0, t=-1, res=0, k_count = 0;
    string S;
    cin >> S;
    cin >> K;
    // int count = 0;
    // cout << S << endl;
    // for(int i = 0; i < S.length(); i++){
    //     cout << (i+1)%10;
    // }
    // cout << endl;
    // cout << t << " " << S.length();
    // if (S[0] == '.'){
    //     k_count++;
    // }
    while(t+1 < S.length()){// && count < 15){
        
        // do{
        //     if (S[t] == '.'){
        //         k_count++;
        //         t++;
        //     } else {
        //         t++;
        //     }
        //     cout << " s " << s+1 << " t " << t+1 << " k_count " << k_count << " res " << res << endl;
        // } while (k_count < K && t < S.length());
        
        while (t+1 < S.length()){
            if (S[t+1] != '.'){
                t++;
            }
            if (S[t+1] == '.'){
                if (k_count == K){
                    break;
                } else {
                    k_count++;
                    t++;
                }
            }
        }
        res = max(res, t-s+1);
        // cout << "s " << s+1 << " t " << t+1 << " k_count " << k_count << " res " << res << endl;
        //cout << S[s] << endl;
        if (S[s] == '.') k_count--;
        s++;
        // count++;
    }
    cout << res << endl;
    return 0;
}