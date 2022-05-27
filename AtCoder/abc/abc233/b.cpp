#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;

int main() {
    int L, R;
    string S;
    cin >> L >> R >> S;
    L -= 1;
    R -= 1;
    for (int i = 0; i < S.length(); i++){
        if (i < L || i > R) {
            cout << S[i];
        } else {
            cout << S[R-(i - L)];
        }
    }
    cout << endl;
    return 0;
}