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
map<int, vector<int> > freq;
set<int> df;
int A[N];
pair<int, int> B[N];
int lg[N],rg[N],ans[N],tree[4*N];
void update(int low,int high,int ind,int val,int node){
	if(low == high){
		tree[node] = val;
		return;
	}
	int mid = (low + high)/2;
	if(ind <= mid)
		update(low, mid, ind, val, 2*node);
	else
		update(mid+1,high,ind,val,2*node+1);
	tree[node] = max(tree[2*node], tree[2*node+1]);
}
int query(int low,int high,int begin,int end,int node){
	if(low > end || high < begin || begin > end)
		return -1;
	if(low >= begin && high <= end)
		return tree[node];
	int mid = (low + high)/2;
	return max(query(low,mid,begin,end,2*node),query(mid+1,high,begin,end,2*node+1));
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		freq.clear();
		df.clear();
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			update(0,n-1,i,0,1);
		for(int i=0;i<n;i++){
			cin>>A[i];
			B[i] = mp(A[i],i);
			freq[A[i]].pb(i);
		}
		stack<int> lft;
		for(int i=0;i<n;i++){
			while(lft.size() && A[lft.top()] <= A[i])
				lft.pop();
			lg[i] = -1;
			if(lft.size())
				lg[i] = lft.top();
			lft.push(i);
		}
		stack<int> rt;
		for(int i=n-1;i>=0;i--){
			while(rt.size() && A[rt.top()] <= A[i])
				rt.pop();
			rg[i] = -1;
			if(rt.size())
				rg[i] = rt.top();
			rt.push(i);
		}
		sort(B,B + n);
		for(int i=0;i<n;i++){
			int mk = 0;
			if(lg[B[i].second] != -1 && rg[B[i].second] != -1){
				int x = lg[B[i].second], y = rg[B[i].second];
				auto it1 = df.lower_bound(x + 1);
				auto it2 = df.lower_bound(B[i].second + 1);
				if((it1 != df.end() && *it1 < B[i].second) || (it2 != df.end() && *it2 < y))
					mk = 1;
				auto it3 = lower_bound(freq[B[i].first].begin(),freq[B[i].first].end(),x + 1);
				auto it4 = lower_bound(freq[B[i].first].begin(),freq[B[i].first].end(),B[i].second + 1);
				if((it3 != freq[B[i].first].end() && *it3 < B[i].second) || (it4 != freq[B[i].first].end() && *it4 < y))
					mk = 1;
				if(mk){
					ans[B[i].second] = 0;
					df.insert(B[i].second);
				}
				else{
					ans[B[i].second] = 1 + query(0,n-1,x+1,y-1,1);
					update(0,n-1,B[i].second,ans[B[i].second],1);
				}
			}
			else{
				ans[B[i].second] = 0;
				df.insert(B[i].second);
			}
		}
		for(int i=0;i<n;i++){
			cout<<ans[i]<<" ";
		}
		cout<<'\n';
	}
} 
