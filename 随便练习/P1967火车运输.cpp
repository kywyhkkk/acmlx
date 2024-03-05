/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2024/2/14 19:00:34
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
const ll maxn=100010;
const ll maxm=100010;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/

struct Node{
	ll u,v,l;
}e[maxm];

struct edge{
	ll v,next;
}tr[maxm<<1];

ll fa[maxn],cntx,cnt,first[maxn];
ll dep[maxn],f[maxn][23],n,m,p[maxn],q;

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

bool cmp(Node x,Node y){
	return x.l>y.l;
}

ll find(ll x){
	return x==fa[x]?fa[x]:fa[x]=find(fa[x]);
}

void add(ll u,ll v){
	tr[++cntx].v=v;
	tr[cntx].next=first[u];
	first[u]=cntx;
}

void dfs(ll u,ll pa){
	dep[u]=dep[pa]+1,f[u][0]=pa;
	for(int i=1;i<=19;++i){
		f[u][i]=f[f[u][i-1]][i-1];
	}
	for(int i=first[u];i;i=tr[i].next){
		ll v=tr[i].v;
		dfs(v,u);
//		p[u]=min(p[u])
	}
}

ll query(ll x,ll y){
	ll da=dep[x],db=dep[y];
	if(da!=db){
		if(da<db){
			swap(x,y);
			swap(da,db);
		}
		ll d=da-db;
		for(int i=0;i<=19;++i){
			if((1<<i)&d){
				x=f[x][i];
			}
		}
	}
	if(x==y){
		return x;
	}
	ll i=0;
	for(i=19;i>=0;--i){
		if(dep[f[x][i]] < 0){
			continue;
		}
		if(f[x][i]==f[y][i]){
			continue;
		}
		else{
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}

int main(){
	n=read();
	m=read();
	for(int i=1;i<=m;++i){
		e[i].u=read();
		e[i].v=read();
		e[i].l=read();
	} 
	sort(e+1,e+1+m,cmp);
	
	cnt=n;
	ll tot=0;
	for(int i=1;i<=(n<<1);++i){
		fa[i]=i;
	}
	for(int i=1;i<=m;++i){
		ll u=e[i].u,v=e[i].v;
		ll fx=find(u),fy=find(v);
		if(fx!=fy){
			add(++cnt,fx);
			add(cnt,fy);
			fa[fx]=cnt;
			fa[fy]=cnt;
			p[cnt]=e[i].l;
			++tot;
		}
		if(tot==n-1){
			break;
		}
	}
	for(int i=1;i<=cnt;++i){
		if(find(i)==i){
			dfs(i,0);
		}
	}
//	dfs(cnt,0);
	q=read();
	for(int i=1;i<=q;++i){
		ll x,y;
		x=read();
		y=read();
		ll ans=query(x,y); 
//		cout<<ans<<endl;
		printf("%lld\n",p[ans]==0?-1:p[ans]);
	}
	return 0;
}


