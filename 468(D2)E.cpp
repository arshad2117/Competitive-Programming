#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int,int> > vp;
#define pb push_back
#define mp make_pair
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define MOD 1000000007
vector<int> pos[26];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin>>s;
	int n = s.length();
	string d = s + s;
	for(int i=0;i<s.length();i++){
		pos[s[i] - 'a'].pb(i);
	}
	double ans = 0;
	for(int i=0;i<26;i++){
		string A[5010];
		int mk[5010] = {0};
		int val[5010] = {0};
		for(int j = 0; j < pos[i].size(); j++){
			for(int k = pos[i][j] + 1;k < pos[i][j] + n;k++)
				A[k-pos[i][j]] += d[k];
		}
		for(int j = 1; j < n; j++){
			int freq[26] = {0};
			for(int k=0;k<A[j].length();k++)
				freq[A[j][k] - 'a']++;
			for(int k=0;k<A[j].length();k++){
				if(freq[A[j][k] - 'a'] == 1){
					val[j]++;
				}
			}
		}  
		int maxi = 0;
		for(int j=1;j<n;j++)
			maxi = max(maxi,val[j]);
		ans = ans + maxi * (1.0 / n);
	}
	printf("%.17lf\n",ans);
}
