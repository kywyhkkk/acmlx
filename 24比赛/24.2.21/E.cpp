/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2024/2/21 15:04:55
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
ll a[maxn],n,m,s,cnt,minx,maxx,f[maxn];
ll shu[maxn],tsum[maxn],cha[maxn];
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

void down(ll bh,ll xl,ll xr){
	ll mid=(xl+xr)>>1;
	shu[bh*2]=shu[bh*2]+(mid-xl+1)*tsum[bh];
	tsum[bh*2]=tsum[bh*2]+tsum[bh];
	shu[bh*2+1]=shu[bh*2+1]+(xr-mid)*tsum[bh];
	tsum[bh*2+1]=tsum[bh*2+1]+tsum[bh];
	tsum[bh]=0;
}

void jian(ll l,ll r,ll bh){
	tsum[bh]=0;
	if(l==r){
		shu[bh]=cha[l];
		return;
	}
	ll mid=(l+r)>>1;
	jian(l,mid,bh*2);
	jian(mid+1,r,bh*2+1);
	shu[bh]=shu[bh*2]+shu[bh*2+1];
}

void add(ll l,ll r,ll xl,ll xr,ll bh,ll z){
	if(l<=xl&&xr<=r){
		tsum[bh]=tsum[bh]+z;
		shu[bh]=shu[bh]+z*(xr-xl+1);
		return;
	}
	down(bh,xl,xr);
	if(xl>r||xr<l){
		return;
	}
	ll mid=(xl+xr)>>1;
	add(l,r,xl,mid,bh*2,z);
	add(l,r,mid+1,xr,bh*2+1,z);
	shu[bh]=shu[bh*2]+shu[bh*2+1];
}

ll ask(ll l,ll r,ll xl,ll xr,ll bh){
	if(l<=xl&&xr<=r){
		return shu[bh];
//		return;
	}
	if(xl>r||xr<l){
		return 0;
	}
	down(bh,xl,xr);
	ll mid=(xl+xr)>>1;
	return ask(l,r,xl,mid,bh*2)+ask(l,r,mid+1,xr,bh*2+1);
}

void solve(){
	for(int i=1;i<=n-1;++i){
		ll tmp=(a[n]-a[i]);
		if(tmp<0){
			printf("NO\n");
			return;
		}
		f[i]=tmp/i;
	}
	for(int i=1;i<=n;++i){
		cha[i]=a[i]-a[i-1];
	}
	jian(1,n,1);
	for(int i=2;i<=n-1;++i){
		f[i]=min(f[i],f[i-1]);
	}
	ll res=0;
//	for(int i=1;i<=n;++i){
//		cout<<f[i]<<endl;
//	}
//	for(int i=1;i<=n;++i){
//		cout<<ask(i,i,1,n,1)<<" ";
//	}cout<<endl;
	for(int i=n-1;i>=1;i-=2){
		ll tmp=ask(i+1,i+1,1,n,1);
		ll lin=tmp/i;
		f[i]-=res;
		res+=f[i];
		add(1,i,1,n,1,min(lin,f[i]));
	}
	ll pd=1;
	for(int i=1;i<=n;++i){
		ll tmp=ask(i,i,1,n,1);
//		cout<<tmp<<endl;
		if(tmp<0){
			pd=0;
		}
	}
	if(pd==0){
		printf("NO\n");
	}else{
		printf("YES\n");
	}
}

int main(){
	ll T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		if(n%2==0){
			printf("YES\n");
		}else{
			solve();
		}
		
	}
	return 0;
}
/*
1
7
3 2 9 4 5 10 100
*/
