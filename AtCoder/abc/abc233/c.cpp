#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;

long long int N;
vector<vector<long long int> > the_data;
vector<long long int> lengths;

long long int dfs(int i, long long int quot){
    // cout << i << endl;
    long long int count = 0;
    // cout << i << " " << quot << endl;

    if (i == N){
        // cout << quot << endl;
        if(quot == 1){ 
            return 1;
        } else {
            return 0;
        }
    }
    
    for (int itr = 0; itr < lengths.at(i); itr++){
        if (quot % the_data.at(i).at(itr) == 0 && quot >= the_data.at(i).at(itr)){
            count += dfs(i+1, quot/the_data.at(i).at(itr));
        }
    }
    return count;
}

int main() {
    long long int X, l, in;
    cin >> N >> X;
    for(int j = 0; j < N; j++){
        cin >> l;
        lengths.push_back(l);
        vector<long long int> in_data;
        for(int i = 0; i < l; i++){
            cin >> in;
            in_data.push_back(in);
        }
        the_data.push_back(in_data);
    }
    // cout << the_data.at(0).at(1) << endl;
    // cout << lengths.at(1) << endl;
    cout << dfs(0,X) << endl;
    return 0;
}