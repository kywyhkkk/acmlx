/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2024/2/2 13:50:05
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
const ll maxn=10001000;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/
ll ans,n,m,a[1010],u[1010],v[1010];
//ll a[maxn],n,m,s,cnt,minx,maxx;
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

void dfs(ll z){
	if(z>m){
		ll res=0;
		for(int i=2;i<=n;++i){
			if(a[i]>a[1]){
				res++;
			}
		}
		ans=min(ans,res);
		return;
	}
	ll x=u[z],y=v[z];
	a[x]+=3;
	dfs(z+1);
	a[x]-=3;
	
	a[y]+=3;
	dfs(z+1);
	a[y]-=3;
	
	a[x]+=1;a[y]+=1;
	dfs(z+1);
	a[x]-=1;a[y]-=1;
	
}

int main(){
	ll T=read();
	while(T--){
		n=read();
		m=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		for(int i=1;i<=m;++i){
			u[i]=read();
			v[i]=read();
		}
		ans=101010101;
		dfs(1);
		printf("%lld\n",ans+1);
	} 
	return 0;
}


