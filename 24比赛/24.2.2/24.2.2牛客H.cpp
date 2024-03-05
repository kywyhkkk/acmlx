/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2024/2/2 15:03:52
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
ll m2[101],mw,v2[101],shu[1001000][3],num;
ll sum[1001000],w[100100],siz[1001000];
ll ans,n,m,cnt,v[100100],mt[1010],jis;
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

void insert(int x){
	ll pd=0;
	ll ch=1;
//	for(int i=1;i<=mw;++i){
//		cout<<v2[i];
//	}cout<<endl;
	for(int i=1;i<=mw;++i){
		if(!shu[ch][v2[i]]){
			shu[ch][v2[i]]=++num;
		}
		ch=shu[ch][v2[i]];
	}
	sum[ch]+=w[x];
}

void dfs(ll x)
{
//	jis++;
//	if(jis>50){
//		return;
//	}
//	cout<<x<<endl;
	if(shu[x][0]){
		dfs(shu[x][0]);
	}
	if(shu[x][1]){
		dfs(shu[x][1]);
	}
	siz[x]=sum[x]+siz[shu[x][0]]+siz[shu[x][1]];
//	cout<<siz[x]<<endl;
}
void init(){
	fill(sum,sum+1+num*2,0);
	fill(siz,siz+1+num*2,0);
	for(int i=0;i<=num;++i){
		shu[i][0]=shu[i][1]=0;
	}
	num=1;
	ans=0;
	cnt=0;
}

void solve(ll x,ll i){
	if(i>=mw){
		ans=max(ans,siz[x]);
		return;
	}
	if(m2[i]){
//		cout<<siz[shu[x][0]]<<endl;
		ans=max(ans,siz[shu[x][0]]);
		if(shu[x][1]){
			ll ch=shu[x][1];
//			if(m2[i+1]==0){
//				solve(shu[x][1],)
//			}
			solve(shu[x][1],i+1);
		}
	}else{
		if(shu[x][0]);
		solve(shu[x][0],i+1);
	}
}

int main(){
	ll T=read();
	while(T--){
		init();
		n=read();
		m=read();
		for(int i=1;i<=n;++i){
			ll y=read();
			ll x=read();
			if(x>m){
				continue;
			}
			cnt++;
			v[cnt]=x;
			w[cnt]=y;
		}
		ll tmp=m;
		mw=0;
		while(tmp){
			mt[++mw]=tmp%2;
			tmp/=2;
		}
		
		for(int i=1;i<=mw;++i){
			m2[i]=mt[mw-i+1];
//			cout<<m2[i];
		}
//		cout<<endl;
		
		for(int i=1;i<=cnt;++i){
			ll tmp=v[i];
			ll res[101],j=mw+1;
			while(tmp){
				v2[--j]=tmp%2;
				tmp/=2;
			}
			for(int k=1;k<=j-1;++k){
				v2[k]=0;
			}
			insert(i);
		}
		
		dfs(1);
//		cout<<"ewrg";
		solve(1,1);
		printf("%lld\n",ans);
	}
	return 0;
}
/*
4 11
5 8
1 4
1 5
1 1
*/

