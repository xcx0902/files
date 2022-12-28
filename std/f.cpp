#include<bits/stdc++.h>
#define int long long
using namespace std;
void tiaoshi(){cout<<"Florr"<<endl;}
int n, m, ans;
const int mod=1e9+7;
int fpow(int a, int b){
	int ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	} 
	return ans;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int j=2; j<=2*n; j++){
		ans=(ans+(n-abs(j-n-1))*((fpow(j,m+1)-1)%mod*fpow(j-1,mod-2)%mod-1)%mod)%mod;
	}
	cout<<ans<<endl;
	return 0;
}