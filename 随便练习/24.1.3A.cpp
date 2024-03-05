/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2024/1/3 11:08:54
    $DESCRIPTION$: 
*********************************************************************/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#ifdef Debug
#define D() cerr<<__LINE__<<endl;
#else
#define D()
#endif
#define ll long long
#define ull unsigned long long
#define mod 1000000007
using namespace std;
const ll maxn=10001000;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/
ll a[maxn],n,m,s,cnt,minx,maxx;
ll read(){
	char ch=getchar();ll xx=0,ff=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')ff=-1;ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		xx=xx*10+ch-'0';ch=getchar();
	}
	return xx*ff;
}

ll qpow(ll x,ll y){
	ll res=1;
	while(y){
		if(y&1){
			res*=x%mod;
		}
		x*=x%mod;
		y>>=1;
	}
	return res%mod;
}

int main(){
	ll T=read();
	while(T--){
		n=read();
		ll ans=qpow(3,n-1)*qpow(2,mod-2)%mod*3%mod+1;
		printf("%lld\n",ans%mod);
	} 
	return 0;
}


