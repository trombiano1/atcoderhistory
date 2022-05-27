#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    if (N >= 42){
        N++;
    }
    if (N < 10){
        cout << "AGC00" << N << endl;
    } else if (N < 100){
        cout << "AGC0" << N << endl;
    } else {
        cout << "AGC" << N << endl;
    }
    return 0;
}