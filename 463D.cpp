#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int,int> > vp;
#define pb push_back
#define mp make_pair
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define MOD 1000000007
#define N 400010
#define lg 20
int par[N],dp[N][lg],nexti[N][lg];
ll sumi[N][lg],maxi[N][lg],val[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin>>q;
	ll last = 0,ct = 1;
	memset(dp,-1,sizeof(dp));
	memset(nexti,-1,sizeof(nexti));
	memset(maxi,-1,sizeof(maxi));
	memset(sumi,-1,sizeof(sumi));
	while(q--){
		ll t,p,q;
		cin>>t>>p>>q;
		par[0] = -1;
		if(t == 1){
			ll r = p ^ last;
			ll w = q ^ last;
			val[ct] = w;
			par[ct] = r - 1;
			dp[ct][0] = par[ct];
			maxi[ct][0] = val[par[ct]];
			for(int i=1;i<lg;i++)
				if(dp[ct][i-1] != -1){
					dp[ct][i] = dp[dp[ct][i-1]][i-1];
					maxi[ct][i] = max(maxi[dp[ct][i-1]][i-1],maxi[ct][i-1]);
				}
			int cur = ct,mk = 0;
			for(int i=lg-1;i>=0;i--)
				if(dp[cur][i] != -1 && maxi[cur][i] < w)
						cur = dp[cur][i];
			if(dp[cur][0] != -1){
				nexti[ct][0] = dp[cur][0];
				sumi[ct][0] = val[par[cur]];
			}
			for(int i=1;i<lg;i++)
				if(nexti[ct][i-1] != -1){
					nexti[ct][i] = nexti[nexti[ct][i-1]][i-1];
					sumi[ct][i] = sumi[nexti[ct][i-1]][i-1] + sumi[ct][i-1];
				}
			ct++;
		}
		else{
			ll r = p ^ last;
			ll x = q ^ last;
			r--;
			x = x + 1 - val[r];
			if(x <= 0){
				cout<<0<<'\n';
				last = 0;
				continue;
			}
			ll cur = r,ans = 1;
			for(int i=lg-1;i>=0;i--)
				if(nexti[cur][i] != -1 && sumi[cur][i] < x){
					x -= sumi[cur][i];
					ans += (1 << i);
					cur = nexti[cur][i];
				}
			cout<<ans<<'\n';
			last = ans;
		}
	}
}
