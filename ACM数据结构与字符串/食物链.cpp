/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2023/11/13 22:25:17
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
ll f[maxn],n,m,s,cnt,minx,maxx;
ll val[maxn],k,ans;
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

ll find(ll x){
	if(f[x]!=x){
		ll t=f[x];
		f[x]=find(f[x]);
		val[x]+=val[t];
		val[x]%=3;
	}
	return f[x];
}

int main(){
	n=read();
	k=read();
	for(int i=1;i<=n;++i){
		f[i]=i;
	}
	for(int i=1;i<=k;++i){
		ll x,y,z;
		z=read();
		x=read();
		y=read();
		if(x>n||y>n||(z==2&&x==y)){
			ans++;
			continue;
		}
		z--;
		ll fx,fy;
		fx=find(x);
		fy=find(y);
		if(fx==fy){
			ll tmp=val[x]-val[y]+3;
			tmp%=3;
			if(tmp!=z){
				ans++;
			}
		}else{
			f[fx]=fy;
			val[fx]=val[y]-val[x]+z;
			val[fx]%=3;
		}
	}
	cout<<ans;
	return 0;
}


