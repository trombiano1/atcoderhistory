#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;

int main() {
    int a,b,c;
    cin >> a >> b >> c;
 int i, j, tmp;
 
  /* 数値を格納する配列 */
  int number[3];
 
  /* 数値の総数を入力 */
  int total;
  number[0] = a;
  number[1] = b;
  number[2] = c;
 
  /* 数値を昇順にソート */
  for (i=0; i<3; ++i) {
    for (j=i+1; j<3; ++j) {
      if (number[i] > number[j]) {
        tmp =  number[i];
        number[i] = number[j];
        number[j] = tmp;
      }
    }
  }
 
  /* 昇順ソートした数値を出力 */

    if (number[2] - number[1] == number[1] - number[0]){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
    
}