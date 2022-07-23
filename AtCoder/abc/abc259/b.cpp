#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1e9
#define LINF 100000000000000000LL
#define all(x) begin(x), end(x)

#ifdef DEBUG_
#include "../../onlinejudge/dump.cpp"
#else
#define dump(...)
#endif

#define PI 3.14159265358979

int main(void) {
    double a, b, d;
    cin >> a >> b >> d;
    cout << setprecision(20) << a * cos(d*PI/180.0) - b * sin(d*PI/180.0) << " " << 
    b * cos(d*PI/180.0) + a * sin(d*PI/180.0) << endl;
    return 0;
}