#include <bits/stdc++.h>
using namespace std;

int main() {
    
	int N;
	cin>>N;
	
	vector<int> p(N);
	
	for(int i=0;i<N;i++)cin>>p[i];
	
	vector<long long> iv(N*2),ix(N*2);
	
	for(int i=0;i<N;i++){
		int j = (p[i]-i+N)%N;
		iv[j] -= j;
		iv[j+N/2+1] += j;
		ix[j] += 1;
		ix[j+N/2+1] -= 1;
		iv[N+j-(N-1)/2] += N+j;
		iv[N+j] -= N+j;
		ix[N+j-(N-1)/2] -= 1;
		ix[N+j] += 1;
	}
	
	for(int i=0;i<N*2-1;i++){
		iv[i+1] += iv[i];
		ix[i+1] += ix[i];
	}
	
	long long ans = 1000000000000000000;
	for(int i=0;i<N;i++){
		ans = min(ans,iv[i] + ix[i]*i + iv[i+N] + ix[i+N]*(i+N));
	}
	
	cout<<ans<<endl;
	
	return 0;
}
