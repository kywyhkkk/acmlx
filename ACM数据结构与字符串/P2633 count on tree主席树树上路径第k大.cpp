/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2023/12/7 22:44:02
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
#define ll int
#define ull unsigned long long
using namespace std;
const ll maxn=200010;
/*
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/
struct P{
	ll sum,l,r;
};
P node[maxn*100];
ll a[maxn],n,m,s,cnt,minx,maxx,root[maxn];
ll to[maxn*2],nex[maxn*2],head[maxn*2],tot,N;
ll w[maxn],f[maxn],dep[maxn],siz[maxn];
ll son[maxn],top[maxn],b[maxn],ans;
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

void add(ll x,ll y){
	cnt++;
	to[cnt]=y;
	nex[cnt]=head[x];
	head[x]=cnt;
}

void build(P &x,ll l,ll r){
x.sum=0;
	if(l==r){
		return;
	}
	ll mid=(l+r)>>1;
	x.l=++tot;
	
	build(node[x.l],l,mid);
	x.r=++tot;
	build(node[x.r],mid+1,r);
}

void insert(P pas,P &x,ll l,ll r,ll z){
	x.sum=pas.sum+1;
	if(l==r){
		return;
	}
	ll mid=(l+r)>>1;
	if(z<=mid){
		x.l=++tot;
		insert(node[pas.l],node[x.l],l,mid,z);
		x.r=pas.r;
	}
	if(z>mid){
		x.r=++tot;
		insert(node[pas.r],node[x.r],mid+1,r,z);
		x.l=pas.l;
	}
}

void dfs(ll x,ll fa){
	root[x]=++tot;
	insert(node[root[fa]],node[root[x]],1,N,w[x]);
	f[x]=fa;
	dep[x]=dep[fa]+1;
	siz[x]=1;
	ll maxson=-1;
	for(int i=head[x];i;i=nex[i]){
		int y=to[i];
		if(y==fa){
			continue;
		}
		dfs(y,x);
		siz[x]+=siz[y];
		if(siz[y]>maxson){
			son[x]=y;
			maxson=siz[y];
		}
	}
}

void dfs2(ll x,ll topf){
	top[x]=topf;
	if(!son[x]){
		return;
	}
	dfs2(son[x],topf);
	for(int i=head[x];i;i=nex[i]){
		ll y=to[i];
		if(y==f[x]||y==son[x]){
			continue;
		}
		dfs2(y,y);
	}
}

ll LCA(ll x,ll y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]){
			swap(x,y);
		}
		x=f[top[x]];
	}
	if(dep[x]>dep[y]){
		swap(x,y);
	}
	return x;
}

ll ask(P x,P y,P z,P d,ll l,ll r,ll k){
	if(l==r){
		return l;
	}
	ll res=node[x.l].sum+node[y.l].sum-node[z.l].sum-node[d.l].sum;
	ll mid=(l+r)>>1;
	if(res>=k){
		return ask(node[x.l],node[y.l],node[z.l],node[d.l],l,mid,k);
	}else{
		return ask(node[x.r],node[y.r],node[z.r],node[d.r],mid+1,r,k-res);
	}
}

int main(){
	n=read();
	m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		b[i]=a[i];
	}
	for(int i=1;i<=n-1;++i){
		ll x,y;
		x=read();
		y=read();
		add(x,y);
		add(y,x);
	}
	sort(b+1,b+1+n);
	N = unique(b+1,b+1+n)-(b+1);
	for(int i=1;i<=n;++i){
		w[i]=lower_bound(b+1,b+1+N,a[i])-b;
	}
	root[0]=++tot;
	build(node[tot],1,N);dfs(1,0);dfs2(1,1);
	for(int i=1;i<=m;++i){
		ll u,v,k,lc;
		u=read();
		v=read();
		k=read();
		u=u^ans;
		lc=LCA(u,v);
		ll tmp = ask(node[root[u]],node[root[v]],node[root[lc]],node[root[f[lc]]],1,N,k);
		ans=b[tmp];
		printf("%lld\n",ans);
	}
	return 0;
}


