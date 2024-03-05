/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2023/11/30 19:04:54
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
const ll maxn=80100;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/
ll n,m,s,cnt,minx,maxx,rt;
ll to[maxn],val[maxn],nex[maxn],head[maxn];
ll siz[maxn],maxp[maxn],vis[maxn],sum;
ll dis[maxn],num,rem[maxn],k,ans; 
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

void add(ll x,ll y,ll z){
	cnt++;
	to[cnt]=y;
	val[cnt]=z;
	nex[cnt]=head[x];
	head[x]=cnt;
}

void getrt(ll u,ll pa){
	siz[u]=1;
	maxp[u]=0;
	for(int i=head[u];i;i=nex[i]){
		ll y=to[i];
		if(y==pa||vis[y]){
			continue;
		}
		getrt(y,u);
		siz[u]+=siz[y];
		maxp[u]=max(maxp[u],siz[y]);
	}
	maxp[u]=max(maxp[u],sum-siz[u]);
	if(maxp[u]<maxp[rt]){
		rt=u;
	}
}

void calc(int u,ll fa){
	++num;
	rem[num]=dis[u];
	for(int i=head[u];i;i=nex[i]){
		int v=to[i];
		if(vis[v]||v==fa){
			continue;
		}
		dis[v]=val[i]+dis[u];
		calc(v,u);
	}
}

ll work(){
	if(num==0){
		return 0;
	}
	sort(rem+1,rem+1+num);
	for(int i=1;i<=num;++i){
		cout<<rem[i]<<" ";
	}cout<<endl;
	ll l=1,r=num;
	ll tmp=0;
	while(l<=r){
		if(rem[l]+rem[r]<=k){
			tmp+=r-l;
			l++;
		}
		else{
			r--;
		}
	}
	return tmp;
}

void solve(int u){
	num=0;
	vis[u]=1;
	dis[u]=0;
	calc(u,0);
	ans+=work();
	for(int i=head[u];i;i=nex[i]){
		ll y=to[i];
		if(vis[y]){
			continue;
		}
		num=0;
		dis[y]=val[i];
		calc(y,u);
		ans-=work();
		sum=siz[y];
		maxp[rt=0]=n;
		getrt(y,0);
		solve(y);
	}
}

int main(){
	n=read();
	for(int i=1;i<=n-1;++i){
		ll x,y,z;
		x=read();
		y=read();
		z=read();
		add(x,y,z);
		add(y,x,z);
	} 
	k=read();
	maxp[rt]=sum=n;
	getrt(1,0);
	solve(rt);
	printf("%lld",ans);
	return 0;
}


