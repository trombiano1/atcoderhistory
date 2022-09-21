#include<bits/stdc++.h>
#define inf 1000000007

using namespace std;
using pi=pair<int,int>;

int main(){
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<pi> seg(n);
    map<int,vector<int>> g;
    set<int> st;
    for(int i=0;i<n;i++){
      cin >> seg[i].first >> seg[i].second;
      g[seg[i].first].push_back(seg[i].second);
      st.insert(seg[i].first);
    }
    st.insert(inf);
    int i=(*st.begin());
    priority_queue<int,vector<int>,greater<int>> pq;
    bool fl=true;
    while(i<=1000000000){
      for(auto &nx : g[i]){pq.push(nx);}
      int od=pq.top();
      pq.pop();
      if(pq.empty()){i=(*st.lower_bound(i+1));}
      else{
        if(pq.top()<=i){fl=false;break;}
        i++;
      }
    }
    if(!pq.empty()){fl=false;}
    if(fl){cout << "Yes\n";}else{cout << "No\n";}
  }
  return 0;
}
