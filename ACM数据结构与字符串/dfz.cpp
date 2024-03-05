/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2023/2/25 16:10:12
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
const ll maxn=5000100;
const ll inf=100000000;

ll a[maxn],n,m,s,cnt,minx,maxx,siz[maxn],mp[maxn],pd[maxn];
ll head[maxn],nex[maxn],to[maxn],val[maxn],vis[maxn],q[maxn];
ll sum,rt,rem[maxn],res,dis[maxn],qu[maxn],ans[maxn],p;
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

void getsiz(ll x,ll fa){
	siz[x]=1;
	for(int i=head[x];i;i=nex[i]){
		ll y=to[i];
		if(vis[y]||y==fa){
			continue;
		}
		getsiz(y,x);
		siz[x]+=siz[y];
	}
}

void getrt(ll x,ll fa){
	siz[x]=1;mp[x]=0;
	for(int i=head[x];i;i=nex[i]){
		ll y=to[i];
		if(y==fa||vis[y]){
			continue;
		}
		getrt(y,x);
		siz[x]+=siz[y];
		mp[x]=max(mp[x],siz[y]);
	}
	mp[x]=max(mp[x],sum-siz[x]);
	if(mp[x]<mp[rt]){
		rt=x;
	}
}

void getdis(ll x,ll fa){
	rem[++res]=dis[x];
	for(int i=head[x];i;i=nex[i]){
		ll y=to[i];
		if(vis[y]||y==fa){
			continue;
		}
		dis[y]=dis[x]+val[i];
		getdis(y,x);
	}
}

void jis(ll x){
	p=0;
	for(int i=head[x];i;i=nex[i]){
		ll y=to[i];
		if(vis[y]){
			continue;
		}
		res=0;
		dis[y]=val[i];
		getdis(y,x);
		for(int j=1;j<=res;++j){
			for(int k=1;k<=m;++k){
				if(qu[k]>=rem[j]){
					ans[k]|=pd[qu[k]-rem[j]];
				}
			}
		}
		for(int j=1;j<=res;++j){
			q[++p]=rem[j];
			pd[rem[j]]=1;
		}
	}
	for(int i=1;i<=p;++i){
		pd[q[i]]=0;
	}
}

void work(ll x){
	vis[x]=1;
	pd[0]=1;
	jis(x);
	for(int i=head[x];i;i=nex[i]){
		ll y=to[i];
		if(vis[y]){
			continue;
		}
		sum=siz[y];
		rt=0;
		mp[rt]=inf;
		getrt(y,0);
		cout<<"rt"<<rt<<endl;
//		getsiz(rt,0);
		work(rt);
	}
}

int main(){
	n=read();
	m=read();
	for(int i=1;i<=n-1;++i){
		ll x,y,z;
		x=read();
		y=read();
		z=read();
		add(x,y,z);
		add(y,x,z);
	}
	for(int i=1;i<=m;++i){
		qu[i]=read();
	}
	mp[rt]=sum=n;
	getrt(1,0);
	getsiz(rt,0);
	work(rt);
	for(int i=1;i<=m;++i){
		if(ans[i])
		printf("AYE\n");
		else printf("NAY\n");
	}
	return 0;
}

