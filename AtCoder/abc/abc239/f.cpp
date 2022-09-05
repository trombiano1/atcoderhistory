#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,l,r)for(int i=(l);i<(r);i++)

int main(){
	int n,m;
	cin >> n >> m;
	vector<int>d(n);
	rep(i,0,n)cin >> d[i];

	dsu dsu(n);
	rep(i,0,m){
		int x,y;
		cin >> x >> y;
		x--,y--;
		d[x]--,d[y]--;
		dsu.merge(x,y);
	}

	vector<vector<int>>temp(n);
	rep(i,0,n){
		if(d[i]<0){
			cout << -1;
			return 0;
		}
		rep(_,0,d[i])temp[dsu.leader(i)].push_back(i);
	}
	
	vector<vector<int>>c2;
	vector<int>c1;
	rep(i,0,n){
		if(temp[i].size()==1)c1.push_back(temp[i][0]);
		else if(temp[i].size()>1) c2.push_back(temp[i]);
	}
	
	vector<pair<int,int>>ans;
	for(auto v:c2){
		for(int i=0;i<(int)v.size()-1;i++){
			if(c1.empty()){
				cout << -1;
				return 0;
			}
			dsu.merge(v[i],c1.back());
			ans.push_back({v[i],c1.back()});
			c1.pop_back();
		}
		c1.push_back(v.back());
	}
	
	if(c1.size()!=2){
		cout << -1;
		return 0;
	}
	dsu.merge(c1[0],c1[1]);
	ans.push_back({c1[0],c1[1]});
	
	if(dsu.size(0)!=n){
		cout << -1;
		return 0;
	}
	
	for(auto[p,q]:ans){
		cout << p+1 << ' ' << q+1 << endl;
	}
}
