#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int,int> > vp;
#define pb push_back
#define mp make_pair
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define MOD 1000000007
#define N 21
int dp[1<<N];
string A[N];
int mask[N][N], sumi[N][N], c[N][N], maxi[N][N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>A[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>c[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			for(int k=0;k<n;k++)
				if(A[i][j] == A[k][j]){
					sumi[i][j] += c[k][j];
					maxi[i][j] = max(maxi[i][j],c[k][j]);
					mask[i][j] |= (1<<k);
				}
		}
	for(int mk=0;mk<(1<<n);mk++)
		dp[mk] = 1e9;
	dp[0] = 0;
	for(int mk=0;mk<(1<<n);mk++)
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				if(!(mk & (1<<i))){
					dp[mk|mask[i][j]] = min(dp[mk|mask[i][j]], dp[mk] + sumi[i][j] - maxi[i][j]);
					dp[mk|(1<<i)] = min(dp[mk|(1<<i)], dp[mk] + c[i][j]);
				}
			}
	cout<<dp[(1<<n) - 1]<<'\n';
}
