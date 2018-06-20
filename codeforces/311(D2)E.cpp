#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int,int> > vp;
#define pb push_back
#define mp make_pair
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define MOD 1000000007
struct node{
	node *left, *right;
	int sumi, val;
};
node * getnode(){
	node* temp = new node;
	temp->left = temp->right = NULL;
	temp->sumi = temp->val = 0;
	return temp;
}
string s, ans;
bool alt[5010][5010];
void insert(node* h,int ind,int st){
	while(1){
		if(ind == s.length())return;
		if(s[ind] == 'a'){
			if(!(h->left))h->left = getnode();
			if(alt[st][ind])h->left->val++;
			h = h->left;
		}
		else{
			if(!(h->right))h->right = getnode();
			if(alt[st][ind])h->right->val++;
			h = h->right;
		}
		ind++;
	}
}
void init(node* h){
	if(!h)
		return;
	init(h->left);
	init(h->right);
	h->sumi = h->val + (h->left ? h->left->sumi: 0) + (h->right ? h->right->sumi : 0);
}
void find_kth(node* h,int k,int ct){
	while(1){
		if(!h || k <= 0){
			cout<<ans.substr(0,ct)<<'\n';
			return;
		}
		if(h->left && h->left->sumi >= k){
			ans[ct] = 'a';
			k -= h->left->val;
			h = h->left;
		}
		else{
			ans[ct] = 'b';
			k -= ((h->left ? h->left->sumi : 0) + (h->right? h->right->val: 0));
			h = h->right;
		}
		ct++;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>s;
	ans = s;
	int k;
	cin>>k;
	node* head = getnode();
	for(int i=0;i<s.length();i++){
		alt[i][i] = true;
		for(int j=0;j<5 && i + j < s.length();j++)
			if(s[i] == s[i+j])
				alt[i][i+j]= true;
	}
	for(int l=5;l<s.length();l++){
		for(int i=0;i<s.length();i++){
			int j = i + l;
			if(i + l >= s.length())break;
			alt[i][j] = (s[i] == s[j]) && alt[i+2][j-2];
		}
	}
	for(int i=0;i<s.length();i++)
		insert(head,i,i);
	init(head);
	find_kth(head, k, 0);
}
