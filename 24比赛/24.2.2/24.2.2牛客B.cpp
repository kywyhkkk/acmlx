/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2024/2/2 13:08:51
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
struct P{
	ll r,c;
};
P a[101001];
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
	return x.c<y.c;
}

int main(){
	ll T=read();
	while(T--){
		ll n=read();
		ll pd1=0,pd2=0,pd0=0;
		for(int i=1;i<=n;++i){
			a[i].r=read();
			a[i].c=read();
			if(a[i].c==0){
				pd0=1;
			}
		}
		sort(a+1,a+1+n,cmp);
		ll ans=3;
		if(pd0==1){
			ans--;
		}
		ll res=2,tmp=2;
//		if(pd0==1){
//			res=1;
//			tmp=1;
//		}
		for(int i=1;i<=n;++i){
				if(a[i].c==-1&&a[i].r==1){
					ans--;
					if(pd0==1){
						res=0;
					}
				}
				if(a[i].c==1&&a[i].r==1){
					ans--;
					if(pd0==1){
						tmp=0;
					}
				}
			if(a[i].c<0){
				if(i>1)
				if(a[i-1].c==a[i].c||(a[i-1].c==a[i].c-1&&a[i-1].r!=a[i].r)){
					res=0;
				}
				if(res==2){
					res=1;
				}
			}
			if(a[i].c>0){
				if(i>1)
				if(a[i-1].c==a[i].c||(a[i-1].c==a[i].c-1&&a[i-1].r!=a[i].r)){
					tmp=0;
				}
				if(tmp==2){
					tmp=1;
				}
			}
		}
		if(pd0==1){
			res=min(1ll,res);
			tmp=min(1ll,tmp);
		}
		ans=min(ans,res+tmp);
		printf("%lld\n",ans);
	}
	return 0;
}


