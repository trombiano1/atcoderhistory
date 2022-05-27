#include<iostream>
#include<math.h>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
using namespace std;

int nth(int x,int n){
    int a[ 4 ];
    a[0] = (x % 10); x /= 10;
    a[1] = (x % 10); x /= 10;
    a[2] = (x % 10); x /= 10;
    a[3] = (x % 10); x /= 10;
    return(a[n]);
}

int main() {
    int possible[10] = {10};
    int maybe[10] = {10};
    int impossible[10] = {10};
    int possible_num=0;
    int maybe_num=0;
    int impossible_num=0;
    string input;
    cin >> input;
    for(int i = 0; i < 10; i++){
        if(input[i] == 'o'){
            possible[possible_num] = i;
            possible_num++;
        }
        if(input[i] == '?'){
            maybe[maybe_num] = i;
            maybe_num++;
        }
        if(input[i] == 'x'){
            impossible[impossible_num] = i;
            impossible_num++;
        }
    }
    int count = 0;
    int possible_flag = 1;
    //int maybe_flag = 1;
    int impossible_flag = 1;
    for(int i = 0; i < 10000; i++){
        impossible_flag = 1;
        for(int j = 0; j < impossible_num; j++){
            if(nth(i,0)==impossible[j] || nth(i,1)==impossible[j] || nth(i,2)==impossible[j] || nth(i,3)==impossible[j]){
                impossible_flag = 0;
            }
        }
        possible_flag = 1;
        for(int j = 0; j < possible_num; j++){
            if(nth(i,0) != possible[j] && nth(i,1) != possible[j] && nth(i,2) != possible[j] && nth(i,3) != possible[j]){
                possible_flag = 0;
            }
        }
        if (impossible_flag && possible_flag){
           // printf("%d\n",i);
            count++;
        }
    }
    cout << count << endl;
    return 0;
}