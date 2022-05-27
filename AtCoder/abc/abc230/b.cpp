#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;

int main() {
    string S;
    cin >> S;
    int count;
    string T = "oxx";
    if (S[0] == 'o'){
        count = 0;
    } else {
        if (S[1] == 'o'){
            count = 2;
        } else {
            count = 1;
        }
    }
    for(int i = 0; i < S.size(); i++){
        // cout << (count + i) % 3 << S[i] << endl;
        if (S[i] != T[(count+i)%3]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}