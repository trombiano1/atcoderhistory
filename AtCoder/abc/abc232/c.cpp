#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional>
#include<vector>

using namespace std;

vector<int> A;
vector<int> B;
vector<int> C;
vector<int> D;
vector<int> nums;

int main() {
    int N, M, in;
    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> in;
        A.push_back(in);
        cin >> in;
        B.push_back(in);
    }
    for(int i=0; i<M; i++){
        cin >> in;
        C.push_back(in);
        cin >> in;
        D.push_back(in);
    }
    for(int i = 0; i < N; i++){
        nums.push_back(i);
    }
    vector<int> values;
    for(int i = 0; i < M; i++){
        if (nums.at(A.at(i)-1)+1 < nums.at(B.at(i)-1)+1){
            values.push_back((nums.at(A.at(i)-1)+1) * 10 + nums.at(B.at(i)-1)+1);
        } else {
            values.push_back((nums.at(B.at(i)-1)+1) * 10 + nums.at(A.at(i)-1)+1);
        }
    }
    sort(values.begin(), values.end());
    do {
        vector<int> values_new;
        for(int i = 0; i < M; i++){
            if (nums.at(C.at(i)-1)+1 < nums.at(D.at(i)-1)+1){
                values_new.push_back((nums.at(C.at(i)-1)+1) * 10 + nums.at(D.at(i)-1)+1);
            } else {
                values_new.push_back((nums.at(D.at(i)-1)+1) * 10 + nums.at(C.at(i)-1)+1);
            }
        }
        sort(values_new.begin(), values_new.end());
        if (values == values_new){
            cout << "Yes" << endl;
            return 0;
        }
    } while (next_permutation(nums.begin(), nums.end()));
    cout << "No" << endl;
    return 0;
}