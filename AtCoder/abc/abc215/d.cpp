#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

bool isPrime(int num){
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false;
    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2){
        if (num % i == 0){
            return false;
        }
    }
    return true;
}

ll nextPrime(ll p){
    p++;
    while (!isPrime(p)){
        p++;
    }
    return p;
}

vector<ll> factorize(ll n){
    vector<ll> factors;
    ll p = 1;
    ll _ = p;
    while (n > 1){
        p = nextPrime(p);
        while (n % p == 0){
            if (_ != p){
                factors.push_back(p);
                _ = p;
            }
            n /= p;
        }
    }
    return factors;
}

int main(void) {
    ll m, n, in;
    cin >> n >> m;
    vector<ll> primes;
    set<ll> factors;
    vector<bool> fl(m+1,true);
    ll count = 0;
    for (auto i = 2; i <= m; i++){
        if (isPrime(i)){
            primes.push_back(i);
        }
    }
    cout << "a" << endl;
    for (auto i = 0; i < n; i++){
        cin >> in;
        for (auto i : factorize(in)){
            // factors.insert(i);
        }
    }
    cout << "factorized" << endl;
    for (auto i:factors){
        ll c = 1;
        while (c * i <= m+1){
            fl[c*i] = false;
            c++;
        }
    }
    cout << "calced" << endl;
    for (auto i = 1; i < m+1; i++){
        if (fl[i]){
            count++;
        }
    }
    cout << count << endl;
    for (auto i = 1; i < m+1; i++){
        if (fl[i]){
            cout << i << endl;
        }
    }
    return 0;
}

// #include <bits/stdc++.h>

// using namespace std;

// #define ll long long
// #define rep(i, n) for (int i = 0; i < (int)(n); i++)

// #define SIZE 100005

// int main(void) {
//     ll n, m, in;
//     cin >> n >> m;
//     set<ll> factors;
//     vector<ll> output;
//     for (ll i = 0; i < n; i++){
//         cin >> in;
//         for (ll j = 1; j <= (ll)sqrt(in); j++){
//             if (in % j == 0) {
//                 factors.insert(j);
//                 factors.insert(in/j);
//             }
//         }
//     }
//     factors.erase(1);
//     cout << factors.size() << endl;
//     cout << "done" << endl;
//     for (ll i = 2; i <= m; i++){
//         bool found = false;
//         for (auto j : factors){
//             if (i%j == 0){
//                 found = true;
//                 break;
//             }
//         }
//         // cout << i << endl;
//         if (!found) output.push_back(i);
//     }
//     cout << output.size()+1 << endl << 1 << endl;
//     for (auto i : output){
//         cout << i << endl;
//     }
//     return 0;
// }