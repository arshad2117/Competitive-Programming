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
int dp[N][N][2],n;
string A;
int fun(int a,int b,int x){
	if(b < 0)
		return 0;
	if(a == n){
		return b == 0?1:0;
	}
	if(dp[a][b][x] != -1)
		return dp[a][b][x];
	if(x == 0){
		if(A[a] == '0')
			return dp[a][b][x] = fun(a+1,b,x);
		else
			return dp[a][b][x] = (fun(a+1,b,1) + fun(a+1,b-1,x))%MOD;
	}
	else
		return dp[a][b][x] = (fun(a+1,b,1) + fun(a+1,b-1,1))%MOD;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>A;
	int t;
	cin>>t;
	n =  A.length();
	t--;
	ll res = 0;
	if(t == -1){
		if(A == "0")cout<<0<<'\n';
		else cout<<1<<'\n';
		return 0;
	}
	if(t == 0){
		if(A == "1"){
			cout<<0<<'\n';
			return 0;
		}	
	}
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<=n;i++){
		int j = t;
		int cur = i,bs = 0;
		for(int k=0;k<10;k++)
			if(cur & (1 << k))
				bs++;
			while(j--){
			if(cur == 1){
				cur = 100;
				break;
			}
			int df = 0;
			for(int k=0;k<10;k++)
				if(cur & (1 << k))
					df++;
			cur = df;
		}
		if(cur == 1){
			res = (res + fun(0,i,0))%MOD;
			if(i == 1)
				res = (res - 1 + MOD)%MOD;
		}
	}
	cout<<res<<'\n';
}
