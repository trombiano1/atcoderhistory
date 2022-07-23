#include <iostream>
#include <vector>
#include <algorithm>
#include <atcoder/modint>
using namespace std;
using m32 = atcoder::modint998244353;
 
 
 
 
int main(){
    int N; cin >> N;
    vector<m32> pow2table(N*2+1,1);
    for(int i=1; i<=N*2; i++) pow2table[i] = pow2table[i-1] * 2;
 
    int D; cin >> D;
 
    m32 ans = 0;
    
    for(int d=0; d<=N-1; d++){
        m32 f1d;
        if(d+D <= N-1) f1d = pow2table[D+1];
        else f1d = 0;
        
        m32 f2d;
        if(2*(N-1-d) < D || D == 1) f2d = 0;
        else if(d+D <= N-1) f2d = pow2table[D-1] * (D-1);
        else f2d = pow2table[D-1] * (2*N-2*d-D-1);
        
        ans += pow2table[d] * (f1d + f2d);
    }
 
    cout << ans.val() << endl;
    return 0;
}