#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int,int> > vp;
#define pb push_back
#define mp make_pair
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define MOD 1000000007
#define N 1010
#define C 10010
ll dp[N][C];
ll cost[N],num[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,w,b,x,sumi = 0;
	cin>>n>>w>>b>>x;
	for(int i=0;i<n;i++){
		cin>>num[i];
		sumi += num[i];
	}
	for(int i=0;i<n;i++)
		cin>>cost[i];
	for(int i=0;i<=num[0];i++){
		dp[0][i] = w - (i)*cost[0];
		if(dp[0][i] < 0)
			dp[0][i] = -1*1e18;
	}
	for(int i=num[0]+1;i<=sumi;i++)
		dp[0][i] = -1*1e18;
	for(int i=1;i<n;i++){
		deque<pair<ll,ll> > sld;
		if(dp[i-1][0] >= 0)
			sld.push_back(mp(min(w,dp[i-1][0]+x),0));
		for(int j=0;j<=sumi;j++){
			while(sld.size() && sld.front().second < j - num[i])
				sld.pop_front();
			if(sld.size())
				dp[i][j] = sld.front().first - j*cost[i];
			else
				dp[i][j] = -1*1e18;
			if(dp[i][j] < 0)
				dp[i][j] = -1*1e18;
			if(j + 1 <= sumi){
				while(sld.size() && sld.back().first < min(w + (j+1)*b,dp[i-1][j+1]+x) + (j+1)*cost[i])
					sld.pop_back();
				if(dp[i-1][j+1] >= 0)
					sld.push_back(mp(min(w + (j+1)*b,dp[i-1][j+1]+x) + (j+1)*cost[i],j+1));
			}
		}
	}
	for(int i=sumi;i>=0;i--){
		if(dp[n-1][i] >= 0){
			cout<<i<<'\n';
			break;
		}
	}
	
}
