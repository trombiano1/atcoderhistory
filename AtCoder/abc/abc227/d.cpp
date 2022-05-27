#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional>
#include<vector>

using namespace std;
#define ll long long

int main() {
    ll N;
    cin >> N;
    ll count = 0;
    for(auto a = 1; a  <= cbrt(N); a++){
        for(auto b = a; b <= sqrt(N/a); b++){
            count += (ll)N/a/b - b + 1;
        }
    }
    cout << count << endl;
    return 0;
}

// ???????????????????????