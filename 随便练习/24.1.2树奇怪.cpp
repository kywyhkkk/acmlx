/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2024/1/2 19:49:54
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
const ll maxn=10000010;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/
ll a[maxn],n,m,s,cnt,minx,maxx,len;
ll shu[maxn],b[maxn],da[maxn],wei[maxn];
ll l,r,ans,answ,ji,jil[maxn];
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

void inser(ll xl,ll xr,ll z,ll val,ll tt,ll w){
	if(xl==xr&&xl==val){
//		cout<<xl<<' ';
		shu[z]=tt;
//		cout<<shu[z]<<endl;
		wei[z]=w;
		return;
	}
	ll mid=(xl+xr)>>1;
	if(mid>=val){
		inser(xl,mid,z*2,val,tt,w);
	}else{
		inser(mid+1,xr,z*2+1,val,tt,w);
	}
	shu[z]=max(shu[z*2],shu[z*2+1]);
	if(shu[z*2]>=shu[z*2+1]){
		wei[z]=wei[z*2];
	}else{
		wei[z]=wei[z*2+1];
	}
	
}

void ask(ll xl,ll xr,ll z){
	if(xl>=l&&xr<=r){
		if(ans<shu[z]){
			ans=shu[z];
			answ=wei[z];
		}
		return;
	}
	ll mid=(xl+xr)>>1;
	if(l<=mid){
		ask(xl,mid,z*2);
	} 
	if(r>mid){
		ask(mid+1,xr,z*2+1);
	}
}

int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	len=unique(b+1,b+1+n)-b-1;
	for(int i=1;i<=n;++i){
		a[i]=lower_bound(b+1,b+1+len,a[i])-b;
	}
//	build(1,n,1);
	r=n;
//	for(int i=1;i<=n;++i){
//		cout<<a[i]<<endl;
//	}
	for(int i=1;i<=n;++i){
		l=a[i]+1;
		ans=0;
		ask(1,n,1);
		da[i]=ans+1;
//		cout<<ans<<endl;
		inser(1,n,1,a[i],ans+1,i);
		ji+=ans+1;
		if(ans==0){
			jil[i]=0;
		}else{
			jil[i]=answ;
		}
	}
	printf("%lld\n",ji);
	for(int i=1;i<=n;++i){
		printf("%lld ",jil[i]);
	}
	return 0;
}


