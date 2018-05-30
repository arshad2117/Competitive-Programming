#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int,int> > vp;
#define pb push_back
#define mp make_pair
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define MOD 1000000007
#define N 500010
int tree[4*N], A[N], mk = 0;
int gcd(int a,int b){
	return b == 0 ? a : gcd(b, a % b);
}
void build(int low,int high,int node){
	if(low == high){
		tree[node] = A[low];
		return;
	}
	int mid = (low + high)/2;
	build(low,mid,2*node);
	build(mid+1,high,2*node+1);
	tree[node] = gcd(tree[2*node], tree[2*node+1]);
}
void checkit(int low,int high,int val,int node){
	if(low == high){
		mk++;
		return;
	}
	int mid = (low + high)/2;
	int x = tree[2*node];
	int y = tree[2*node+1];;
	if(x % val && y % val){
		mk += 2;
		return;
	}
	if(x % val)checkit(low,mid,val,2*node);
	else if(y % val)checkit(mid+1,high,val,2*node+1);
}
void query(int low,int high,int begin,int end,int val,int node){
	if(low > end || high < begin || begin > end)return;
	if(low >= begin && high <= end){
		if(tree[node] % val)
			checkit(low,high,val,node);
		return;
	}
	int mid = (low + high)/2;
	query(low,mid,begin,end,val,2*node);
	query(mid+1,high,begin,end,val,2*node+1);
}
void update(int low,int high,int ind,int val,int node){
	if(low == high){
		tree[node] = val;
		return;
	}	
	int mid = (low + high)/2;
	if(ind <= mid)
		update(low,mid,ind,val,2*node);
	else
		update(mid+1,high,ind,val,2*node+1);
	tree[node] = gcd(tree[2*node], tree[2*node+1]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>A[i];
	int q;
	cin>>q;
	build(0,n-1,1);
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			int l,r,x;
			cin>>l>>r>>x;
			l--;
			r--;
			mk = 0;
			query(0,n-1,l,r,x,1);
			if(mk > 1)cout<<"NO\n";
			else cout<<"YES\n";
		}
		else{
			int x,y;
			cin>>x>>y;
			x--;
			update(0,n-1,x,y,1);
		}
	}

	
}
