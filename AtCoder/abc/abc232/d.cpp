#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector c(n, vector<char>(m));
    for(auto& v : c){
        for(char& x : v){
            cin >> x;
        }
    }
    vector f(n+1, vector<int>(m+1));
    for(int i = n-1; i >= 0; --i){
        for(int j = m-1; j >= 0; --j){
            if (c[i][j] == '#') continue;
            f[i][j] = max(f[i+1][j], f[i][j+1]) + 1;
        }
    }
    cout << f[0][0] << '\n';
}