#include<bits/stdc++.h>

using namespace std;

int main(){
  string x;
  cin >> x;
  int s=0,c=0;
  for(auto &nx : x){s+=(nx-'0');}
  string res;
  for(int i=x.size()-1;;i--){
    c+=s;
    res.push_back('0'+(c%10));
    c/=10;
    if(i>=0){s-=(x[i]-'0');}
    if(i<=0 && c==0){break;}
  }
  reverse(res.begin(),res.end());
  cout << res << '\n';
  return 0;
}



// #include <bits/stdc++.h>

// using namespace std;

// #define ll long long
// #define rep(i, n) for (int i = 0; i < (int)(n); i++)

// string add2(string s, ll n){
//     ll todig = (ll)log10(n);
//     ll ssize = s.size();
//     if (todig+1 > s.size()){
//         for (ll i = 0; i < todig+1-ssize; i++){
//             s = '0' + s;
//         }
//     }
//     // cout << "asdf" << s << endl;
//     string out = s;
//     ll carry = 0;
//     ll dig = 0;
//     while (dig <= todig){
//         cout << "out " << out << " " << n << endl;
//         int sum = (s[s.size()-dig-1] - '0') + (ll)(n/pow(10, dig))%10 + carry;
//         out[out.size()-1-dig] = (char)(sum % 10 + '0');
//         carry = (int)(sum/10);
//         dig++;
//     }
//     if (carry != 0){
//         out = (char)(carry+'0') + out;
//     }
//     return out;
// }

// string add(string s, ll n){
//     string out = s;
//     ll carry = 0;
//     ll dig = 0;
//     ll ndig = (ll)log10(n) + 1;
//     while (dig < ndig || carry != 0){
//         ll nth_s;
//         if (s.size() < 1+dig){
//             nth_s = '0';
//         } else {
//             nth_s = s[dig];
//         }
//         ll sum = (nth_s - '0') + (ll)(n/pow(10,dig))%10 + carry;
//         if (out.size() < 1+dig){
//             out += '0';
//         }
//         out[dig] = (char)(sum % 10 + '0');
//         carry = (int)(sum/10);
//         dig++;
//         // cout << out << " " << carry << endl;
//     }
//     return out;
// }

// int main(void) {
//     string s;
//     reverse(s.begin(),s.end());
//     string out = "";
//     cin >> s;
//     ll sum = 0;
//     add("1",25);
//     for (unsigned long i = 0; i < s.size(); i++){
//         sum += s[i] - '0';
//         out = add('0'+out, sum);
//     }
//     reverse(out.begin(),out.end());
//     cout << out << endl;
//     return 0;
// }
