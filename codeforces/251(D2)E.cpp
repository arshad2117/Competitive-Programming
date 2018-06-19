/*
G.Arshad
Indian Institute of Information Technology, Sricity
arshad2117@gmail.com
*/
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define pb push_back
#define N 100010
int fact[100100], rev[100010];
vector<int> divs[N];
int moduloexp(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=(1LL*res*a)%MOD;
		b/=2;
		a=(1LL*a*a)%MOD;
	}
	return res;
}
int comb(int n,int r){
	if(n<r)
		return 0;  
	return (1LL*fact[n]*((1LL*rev[n-r]*rev[r])%MOD))%MOD;
}
void init(){
	fact[0]=1;
	rev[0]=1;
	for(int i=1;i<100010;i++){
		fact[i]=(1LL*fact[i-1]*i)%MOD;
		rev[i] = moduloexp(fact[i], MOD - 2);
	}
	for(int i=2;i<N;i++)
		for(int j=i; j < N; j += i)
			divs[j].pb(i);
}
int mk[1000010];
vector<int> fd;
int fun(int n, int f){
	if(n < f)
		return 0;
	if(mk[n] != -1)
		return mk[n];
	fd.pb(n);
	int ans = comb(n-1,f-1);
	for(int i=0;i<divs[n].size();i++){
		ans = (ans - fun(n/divs[n][i], f));
		if(ans < 0)ans += MOD;
	}
	return mk[n] = ans;
}
int main(){
	ios::sync_with_stdio(false);
	init();
	int q;
	cin>>q;
	memset(mk, -1, sizeof(mk));
	while(q--){
		int n,f;
		cin>>n>>f;
		fun(n, f);
		cout<<mk[n]<<'\n';
		for(int i=0;i<fd.size();i++)
			mk[fd[i]] = -1;
		fd.clear();
	}
}