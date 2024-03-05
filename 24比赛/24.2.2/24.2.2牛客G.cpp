/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2024/2/2 13:59:46
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
using namespace std;
const ll maxn=100100;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/
struct P{
	ll a,b,c;
};
P ju[101010];
ll sum[maxn],n,m,s,cnt,minx,maxx;
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

bool cmp(P x,P y){
	return x.a<y.a;
}

bool check(ll x){
	ll tmp=0;
	for(int i=1;i<=n;++i){
		if(ju[i].a<=x){
			tmp+=ju[i].b;
		}
	}
	if(x-tmp<=m){
		return 1;
	}else{
		return 0;
	}
}

int main(){
	ll T=read();
	while(T--){
		n=read();
		m=read();
		for(int i=1;i<=n;++i){
			ju[i].a=read();
			ju[i].b=read();
			ju[i].c=ju[i].a-ju[i].b;
		}
		sort(ju+1,ju+1+n,cmp);
		
		for(int i=1;i<=n;++i){
			sum[i]=sum[i-1]+ju[i].b;
			ju[i].c=ju[i].a-sum[i];
		}
		ll ans=m;
		for(int i=1;i<=n;++i){
			if(m>=ju[i].c){
				ans=max(ans,ju[i].a+m-ju[i].c);
			}
		}
		
	
		printf("%lld\n",ans);
	}
	return 0;
}


