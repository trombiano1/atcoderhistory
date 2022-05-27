#include<iostream>
#include<math.h>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
using namespace std;

int main() {
    int N;
    cin >> N;
    string biggest_name;
    string secondbiggest_name;
    int biggest = 0;
    int secondbiggest = 0;
    int number = 0;
    string name;
    for(int i = 0; i < N; i++){
        cin >> name >> number;
        if(number > biggest){
            secondbiggest = biggest;
            secondbiggest_name = biggest_name;
            biggest = number;
            biggest_name = name;
        } else if (number > secondbiggest){
            secondbiggest = number;
            secondbiggest_name = name;
        }
    }
    cout << secondbiggest_name << endl;
    return 0;
    
}