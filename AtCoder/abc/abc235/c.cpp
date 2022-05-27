#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional>
#include<vector>
#include<map>
using namespace std;

int main() {
    long long int N, Q, input;
    long long int x, k;
    // vector<vector<long long int> > a;
    cin >> N >> Q; 
    // long long int a[N][N];
    // int a_count = 0;
    // long long int a_list[200000];
    // vector<long long int> a[200000];
    map<int, vector<long long int> > a;
    // for(int i = 0; i < 200000; i++){
    //     a_list[i] = -1;
    // }
    long long int queue[Q][2];
    for(long long int i = 0; i < N; i++){
        cin >> input;
        a[input].push_back(i+1);
        // long long int pos = distance(a_list, find(a_list, a_list + a_count, input));
        // if (pos == a_count){
        //     // cout << "not found" << endl;
        //     // cout << "n pos: " << a_count;
        //     a_list[a_count] = input;
        //     a_count++;
        //     a[pos].push_back(i+1);
        // } else {
        //     // cout << "found" << endl;
        //     // cout << "y pos:" << pos << endl;
        //     a[pos].push_back(i+1);
        // }
        // // a[input].push_back(i+1);
    }
    for(long long int i = 0; i < Q; i++){
        cin >> x >> k;
        queue[i][0] = x;
        queue[i][1] = k;
    }
    for(long long int j = 0; j < Q; j++){
        // long long int pos = distance(a_list, find(a_list, a_list + a_count, queue[j][0]));
        // cout << "qj1 " << queue[j][1] << endl;
        // cout << "size1  " << queue[j][1] << endl;
        // if (pos != a_count){
            if (queue[j][1] > a[queue[j][0]].size()){
                cout << -1 << endl;
            } else {
                cout << a[queue[j][0]][queue[j][1]-1] << endl;
            }
        // } else {
        //     cout << -1 << endl;
        // }
    }
    // cout << a[1][2] << endl;
    return 0;
}