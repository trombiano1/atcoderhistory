#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void) {
    ll h, w, input;
    cin >> h >> w;
    vector<vector<ll>> A;
    A.resize(h);
    for(auto i = 0; i < h; i++){
        A[i].resize(w);
        for(auto j = 0; j < w; j++){
            cin >> input;
            A[i][j] = input;
        }
    }
    for(auto j = 0; j < w; j++){
        for(auto i = 0; i < h; i++){
            cout << A[i][j];
            if (i != h-1){
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}