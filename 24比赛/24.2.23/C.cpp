/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2024/2/23 14:36:42
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
#include<map>
using namespace std;
const ll maxn=10001000;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/
map<ll,ll> pd,ansx,ansy,ansz;
ll a[maxn],n,m,s,cnt,minx,maxx;
ll f[maxn];
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
int main(){
	ll q=read();
	f[1]=0;
	f[2]=1;
	for(int i=3;i<=45;++i){
		f[i]=f[i-1]+f[i-2];
	}
	for(int j=1;j<=45;++j){
			for(int l=1;l<=45;++l){
				for(int r=1;r<=45;++r){
					ll x=f[j],y=f[l],z=f[r];
					ll tmp=x+y+z;
						pd[tmp]=1;
						ansx[tmp]=x;
						ansy[tmp]=y;
						ansz[tmp]=z;
				}
			}
		}
	for(int i=1;i<=q;++i){
		n=read();
		
		if(!pd[n]){
			printf("-1\n");
		}else{
			printf("%lld %lld %lld\n",ansx[n],ansy[n],ansz[n]);
		}
	}
	return 0;
}


