#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int,int> > vp;
#define pb push_back
#define mp make_pair
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
ll MOD;
ll raise(ll a, ll b){
	ll ans = 1;
	while(b){
		if(b & 1)
			ans = (a * ans) % MOD;
		a = (a * a)%MOD;
		b /= 2;
	}		
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll a,b,p,x;
	cin>>a>>b>>p>>x;
	MOD = p;
	ll ans = 0;
	for(ll i=1;i<=p-1;i++){
		ll cur = ((b)*(raise(raise(a,i),MOD-2)))%MOD;
		ll d = i,u = x;
		if(i > x)continue;
		ll g = cur;
		cur = (cur - i%MOD + MOD)%MOD;
		cur = (cur*raise(p-1,MOD-2))%MOD;
		ll low = 0,high = x/p + 1;
		while(low < high){
			ll mid = (low + high)/2;
			if(i + (cur + p*mid)*(p-1) >= d)
				high = mid;
			else low = mid + 1;
		}
		if(i + (cur + p*low)*(p-1) < d || i + (cur + p*low)*(p-1) > u)continue;
		ll val1 = low;
		low = 0,high = x/p + 1;
		while(low < high){
			ll mid = (low + high)/2;
			if(i + (cur + p*mid)*(p-1) > u)
				high = mid;
			else low = mid + 1;
		}
		ll val =i + (cur + p*(low-1))*(p-1);
		if(val < d || val > u)continue;
		val = low-1;
		ans += val - val1 + 1;
	}
	cout<<ans<<'\n';
	
}
