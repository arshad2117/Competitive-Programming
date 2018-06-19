#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int,int> > vp;
#define pb push_back
#define mp make_pair
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define MOD 1000000007
map<string,ll> cs,ch;
string s[100010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>s[i];
	for(int i=0;i<n;i++){
		int x = 0;
		for(int j=0;j<s[i].length();j++){
			if(s[i][j] == 's')
				x++;
		}
		cs[s[i]] = x;
		ch[s[i]] = s[i].length() - x;
	}
	vector<pair<double,ll> > df;
	for(int i=0;i<n;i++){
		if(ch[s[i]])
			df.pb(mp(-1.0*cs[s[i]]/ch[s[i]],i));
		else
			df.pb(mp(-1*1e18,i));
	}
	sort(df.begin(),df.end());
	string g = "";
	for(int i=0;i<n;i++){
		g += s[df[i].second];
	}
	ll ans = 0,cur = 0;
	for(int i=0;i<g.length();i++){
		if(g[i] == 's')
			cur++;
		else
			ans += cur;
	}
	cout<<ans<<'\n';
}
