#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;

int main() {
    int X, Y;
    // cin >> X >> Y;
    X = 5; Y = 10;
    if (X < Y){
        cout << ((int)(Y-X-1)/10)+1 << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}