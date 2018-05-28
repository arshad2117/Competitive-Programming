#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int,int> > vp;
#define pb push_back
#define mp make_pair
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define MOD 1000000007
#define N 100010
#define INF 2*1e6
int start[N], val[N], endi[N], tree[4*N], dp1[N], dp2[N];
vector<pair<int,int> > pts;
void update(int low,int high,int ind,int val, int node){
	if(low == high){
		tree[node] = max(val,tree[node]);
		return;
	}
	int mid = (low + high)/2;
	if(ind <= mid)
		update(low,mid,ind,val,2*node);
	else 
		update(mid+1,high,ind,val,2*node+1);
	tree[node] = max(tree[2*node], tree[2*node+1]);
}
int query(int low,int high,int begin,int end,int node){
	if(low > end || high < begin || begin > end)
		return -1*INF;
	if(low >= begin && high <= end)
		return tree[node];
	int mid = (low + high)/2;
	return max(query(low,mid,begin,end,2*node),query(mid+1,high,begin,end,2*node+1));
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		start[x]++;
		endi[y]++;
	}
	int cur = 0;
	for(int i=1;i<=m;i++){
		cur += start[i];
		val[i] = cur;
		cur -= endi[i];
	}
	int maxi = 0;
	for(int i=1;i<=m;i++){
		dp1[i] = max(query(0,n,0,val[i],1),0) + 1;
		update(0,n,val[i],dp1[i],1);
	}
	memset(tree,0,sizeof(tree));
	for(int i=m;i>=1;i--){
		dp2[i] = max(query(0,n,0,val[i],1),0) + 1;
		update(0,n,val[i],dp2[i],1);
	}
	for(int i=1;i<=m;i++){
		maxi = max(maxi,dp1[i] + dp2[i] - 1);

	}
	cout<<maxi<<'\n';
}
