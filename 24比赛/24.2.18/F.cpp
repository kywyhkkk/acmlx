/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2024/2/18 22:09:17
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
	ll l,r;
};
P seg[maxn];
ll a[maxn],n,m,s,cnt,minx,maxx;
ll shu[maxn],f[maxn];
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

void jian(ll xl,ll xr,ll bh){
	if(xl==xr){
		shu[bh]=0;
//		shu[bh]%=m;
		return;
	}
	ll mid=(xl+xr)>>1;
	jian(xl,mid,bh*2);
	jian(mid+1,xr,bh*2+1);
	shu[bh]=0;
}

void inser(ll l,ll r,ll xl,ll xr,ll bh){
	if(l<=xl&&xr<=r){
//		ans=ans%m*shu[bh]%m;
		shu[l]++;
		return;
	}
	if(xl>r||xr<l){
		return;
	}
	ll mid=(xl+xr)>>1;
	inser(l,r,xl,mid,bh*2);
	inser(l,r,mid+1,xr,bh*2+1);
}

ll ask(ll l,ll r,ll xl,ll xr,ll bh){
	if(l<=xl&&xr<=r){
//		ans=ans%m*shu[bh]%m;
		return shu[bh];
	}
	if(xl>r||xr<l){
		return 0;
	}
	ll mid=(xl+xr)>>1;
	return ask(l,r,xl,mid,bh*2)+ask(l,r,mid+1,xr,bh*2+1);
}

bool cmp(P x,P y){
	if(x.l==y.l){
		return x.r<y.r;
	}
	return x.l<y.l;
}

int main(){
	ll T=read();
	while(T--){
		n=read();
		m=read();
		jian(1,n,1);
		for(int i=1;i<=m;++i){
			seg[i].l=read();
			seg[i].r=read();
		}
		sort(seg+1,seg+1+m,cmp);
		fill(f,f+1+n,0);
		for(int i=1;i<=m;++i){
			f[seg[i].l]++;
		}
		ll ans=0;
		ll you=0;
		for(int i=1;i<=m;++i){
			you=max(you,seg[i].r);
			inser(seg[i].r,seg[i].r,1,n,1);
			if(seg[i].l!=seg[i-1].l){
				if(seg[i].l>you){
					zuo=seg[i].l;
					ans=ans+f[seg[i].l];
				}else{
					ans=max(ans,ans-ask(you,seg[i].l-1,1,n,1)+f[seg[i].l]);
				}
				
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}


