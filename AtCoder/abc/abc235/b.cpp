#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;

int main() {
    long long int N, H, H_;
    cin >> N;
    H = 0;
    for(long long int i = 0; i < N; i++){
        cin >> H_;
        if (H_ > H){
            H = H_;
        } else {
            break;
        }
    }
    cout << H << endl;
    return 0;
}