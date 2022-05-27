#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional>
using namespace std;

int main(){
  string thenumber;
  cin >> thenumber;
  int numbersize;
  numbersize = thenumber.size();
  int amount = 0;
  for(int i = 0; i < (numbersize-1)/2; i++){
    amount += 9 * pow(10,i);
  }
  int firsthalf,secondhalf;
  if(numbersize % 2 == 0){
    firsthalf = stoi(thenumber.substr(0,(numbersize/2)));
    secondhalf = stoi(thenumber.substr((numbersize/2), numbersize));
    if(firsthalf > secondhalf){
      amount += firsthalf - pow(10,numbersize/2-1);
      /*      cout << firsthalf - pow(10,numbersize/2-1);*/
    } else {
      amount += firsthalf - pow(10,numbersize/2-1)+1;
      /*      cout << firsthalf - pow(10,numbersize/2-1) + 1;*/
    }
  }
  cout << amount << endl;
  return 0;
}
