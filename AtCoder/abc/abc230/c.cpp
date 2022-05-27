#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;

int main() {
    long long int N, A, B, P, Q, R, S;
    cin >> N >> A >> B;
    cin >> P >> Q >> R >> S;
    for(long long int i = P; i <= Q; i++){
        for(long long int j = R; j <= S; j++){
            if (j == i - A + B || j == -i + A + B){
                cout << "#";
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }
    // cout << N << endl;
    return 0;
}