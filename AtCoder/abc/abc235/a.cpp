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
    int a,b,c;
    a = (int)N/100;
    b = (int)(N-a*100)/10;
    c = (int)(N-a*100-b*10);
    cout << a*100+b*10+c + b*100+c*10+a + c*100+a*10+b << endl;
    return 0;
}