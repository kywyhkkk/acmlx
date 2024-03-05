/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2024/1/25 21:10:28
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
			res=(res*x)%mod;
		}
		x=(x*x)%mod;
		y>>=1;
	}
	return res;
}

int main(){
	ll T=read();
	while(T--){
		ll x,ans;
		x=read();
		x%=mod-1;
		ans=qpow(3,x)-1;
		if(ans&1){
			printf("%lld\n",(ans+mod)/2);
		}else{
			printf("%lld\n",ans/2);
		}
	} 
	return 0;
}


