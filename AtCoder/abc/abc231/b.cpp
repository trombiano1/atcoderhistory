#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional>
#include<vector>
#include<map>
using namespace std;

int main() {
    int N;
    cin >> N;
    string input;
    map<string, int> mp;
    map<string, int>::iterator it;
    for(int i = 0; i < N; i++){
        cin >> input;
        if (mp.find(input) == mp.end()){
            mp[input] = 1;
        } else {
            mp[input]++;
        }
    }
    int max_count = 0;
    string winner;
    for (it = mp.begin(); it != mp.end(); it++){
        if(it->second > max_count){
            winner = it->first;
            max_count = it->second;
        }
    }
    cout << winner << endl;
    return 0;
}