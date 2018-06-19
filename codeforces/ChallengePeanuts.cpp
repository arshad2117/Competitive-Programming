#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int,int> > vp;
#define pb push_back
#define mp make_pair
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define MOD 1000000007
ll dp[510][10][10],n;
ll fun(int i,int a,int b){
	if(a < 0 || b < 0)return 0;
	if(i == n && !a && !b)return 1;
	if(i == n)return 0;
	if(dp[i][a][b] != -1)return dp[i][a][b];
	ll ans  = 0;
	for(int p=0;p<=5;p++)
		for(int q=0;q<=3;q++)
			ans += fun(i+1,a-p,b-q);
	return dp[i][a][b] = ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);	
	cin>>n;
	memset(dp,-1,sizeof(dp));
	cout<<fun(0,5,3)<<'\n';

	
}
