#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MAX 101

vector<int>lvals={0,0,1,1,2,3,3,3,4,5,6,7,7,7,7,7,8,9,10,11,12,13,14,15,15,15,15,15,15,15,15,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,63,63,63,63,63};
vector<int>fact(MAX);
vector<int>ifact(MAX);

inlint int mul(int a, int b){return (int)((a*1LL*b)%MOD);}
inlint int ncr(int n, int r){return (r<0)?0:((r>n)?0:mul(fact[n],mul(ifact[n-r],ifact[r])));}

int modinv(int n){
	int p=mod-2;
	int res=1;
	while(p){
		if(p&1)res=mul(res,n);
		n=mul(n,n);
		p>>=1;
	}
	return res;
}

void init(){
	fact[0]=1;
	for(int i=1;i<MAX;i++)fact[i]=mul(fact[i-1],i);
	ifact[MAX-1]=modinv(fact.back());
	for(int i=MAX-2;i>=0;i--)ifact[i]=mul(ifact[i+1],i+1);
}

int solve(int n){
	if(n<3)return 1;
	return mul(ncr(n-1,lvals[n]),mul(solve(lvals[n]),solve(n-1-lvals[n])));
}

void fastIO(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int main(){
	fastIO();
	int x;
	cin>>x; // 1<=x<=100;
	init();
	cout<<solve(x)<<endl;
	return 0;
}
