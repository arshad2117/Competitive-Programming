#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int,int> > vp;
#define pb push_back
#define mp make_pair
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define MOD 1000000007
#define N 1000010
vector<pair<int,int> > graph[N];
vector<ll> srt[N];
vector<ll> pref[N];
int L[N], n;
vector<ll> df;
void dfs(int s){
	if(2*s <= n)
		dfs(2*s);
	if(2*s + 1 <= n)
		dfs(2*s+1); 
	srt[s].pb(0);
	if(2*s <= n){
		for(int i=0;i<srt[2*s].size();i++)
			srt[s].pb(srt[2*s][i] + L[2*s-1]);
	}
	if(2*s + 1 <= n){
		for(int i=0;i<srt[2*s+1].size();i++)
			srt[s].pb(srt[2*s+1][i] + L[2*s]);
	}
	sort(srt[s].begin(),srt[s].end());
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int m;
	cin>>n>>m;
	for(int i=1;i<=n-1;i++){
		cin>>L[i];
	}
	dfs(1);
	for(int i=1;i<=n;i++){
		pref[i].pb(srt[i][0]);
		for(int j=1;j<srt[i].size();j++)
			pref[i].pb(srt[i][j] + pref[i][j-1]);
	}	
	while(m--){
		ll a,h;
		cin>>a>>h;
		int x = a;
		ll cur = 0;
		ll ans = 0;
		int id = upper_bound(srt[x].begin(),srt[x].end(),h) - srt[x].begin();
		id--;
		//for(int i=0;i<srt[x].size();i++)cout<<srt[x][i]<<" ";
		//cout<<'\n';
		ans += (id + 1)*h - pref[x][id];
		while(x != 1){
			int p = (x)/2;
			cur += L[x-1];
			int y = x;
			x = p;
			if(cur <= h){
				ans += h - cur;
				int c1 = (2*p == y)?(2*p + 1):2*p;
				int e1 = L[c1-1];
				ll rt = h - cur - e1;
				if(rt < 0)
					continue;
				int ind = upper_bound(srt[c1].begin(), srt[c1].end(), rt) - srt[c1].begin();
				if(!ind)continue;
				else ind--;
				ans += (ind+1)*(h - cur - e1) - (pref[c1][ind]); 
			}
		}
		cout<<ans<<'\n';
	}	
}
