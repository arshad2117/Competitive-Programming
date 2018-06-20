#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int,int> > vp;
#define pb push_back
#define mp make_pair
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define MOD 1000000007
#define N 510
#define INF 1e9
int dist[N][N], visited[N], ans[N][N], edg[N][N];
vector<pair<int,int> > graph[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		graph[a-1].pb(mp(b-1,c));
		graph[b-1].pb(mp(a-1,c));
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			dist[i][j] = INF;
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<graph[i].size();j++){
			dist[i][graph[i][j].first] = min(dist[i][graph[i][j].first], graph[i][j].second);
		}
	for(int i=0;i<n;i++)dist[i][i] = 0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++){
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
			}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<graph[j].size();k++){
				int x = graph[j][k].first;
				if(dist[i][x] + graph[j][k].second  == dist[i][j])
					edg[i][j]++;
			}
		}
	}
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++){
			int ans = 0;
			for(int k=0;k<n;k++)
				if(dist[i][j] == dist[i][k] + dist[k][j]){
					ans += edg[i][k];
				}
			cout<<ans<<" ";
		}
}
