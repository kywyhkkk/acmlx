/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2023/11/14 23:18:21
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
#define pc(ch) (pp_<100000?pp[pp_++]=(ch):(fwrite(pp,1,100000,stdout),pp[(pp_=0)++]=(ch)))
using namespace std;
const ll maxn=200000;
const ll inf=0x3f3f3fll;
/*
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/
struct P{
	ll son[2],fa,lev;
}node[maxn*20];

int pp_=0,pp[100000];
ll tot,n,m,s,cnt,minx,maxx,rt[maxn+5];
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

inline void write(int x)
{
    if(x<0) pc('-'),x=-x;
    if(x>9) write(x/10);
    pc(x%10+'0');
}

inline void build(ll &rt,int l,int r){
	rt=++tot;
	ll mid=(l+r)>>1;
	if(l==r){
		node[rt].fa=l;
		return;
	}
	build(node[rt].son[0],l,mid);
	build(node[rt].son[1],mid+1,r);
}

inline void addlev(ll ro,ll l,ll r,ll x){
	ll mid=(l+r)>>1;
	if(l==r){
		node[ro].lev++;
		return;
	}
	if(x<=mid){
		addlev(node[ro].son[0],l,mid,x);
	}else{
		addlev(node[ro].son[1],mid+1,r,x);
	}
}

inline void newpoi(ll &rt,ll lst,ll l,ll r,ll x,ll fa){
	rt=++tot;
	ll mid=(l+r)>>1;
	if(l==r){
		node[rt].fa=fa;
		node[rt].lev=node[lst].lev;
		return;
	}
//	node[rt].son[0]=node[lst].son[0]
	if(x<=mid){
		node[rt].son[1]=node[lst].son[1];
		newpoi(node[rt].son[0],node[lst].son[0],l,mid,x,fa);
	}else{
		node[rt].son[0]=node[lst].son[0];
		newpoi(node[rt].son[1],node[lst].son[1],mid+1,r,x,fa);
	}
}

inline ll quer(ll ro,ll l,ll r,ll x){
	ll mid=(l+r)>>1;
	if(l==r){
		return ro;
	}
	if(x<=mid){
		return quer(node[ro].son[0],l,mid,x);
	}
	else{
		return quer(node[ro].son[1],mid+1,r,x);
	}
}

inline ll getf(ll ro,ll x){
	ll fa=quer(ro,1,n,x);
	if(node[fa].fa==x){
		return fa;
	}else{
		return getf(ro,node[fa].fa);
	}
}

inline void con(ll v,ll x,ll y){
	ll fx=getf(rt[v],x),fy=getf(rt[v],y);
	if(fx==fy){
		return;
	}
	if(node[fx].lev<node[fy].lev){
		swap(fx,fy);
	}
	newpoi(rt[v],rt[v-1],1,n,node[fy].fa,node[fx].fa);
	if(node[fx].lev==node[fy].lev){
		addlev(rt[v],1,n,node[fx].fa);
	}
}

int main(){
//	freopen("bing.in","r",stdin); 
	n=read();
	m=read();
	build(rt[0],1,n);
	for(int i=1;i<=m;++i){
		ll op,x,y;
		op=read();
		if(op==1){
			rt[i]=rt[i-1];
			x=read();
			y=read();
			con(i,x,y);
		}
		
		if(op==2){
			x=read();
			rt[i]=rt[x];
		}
		
		
		if(op==3){
			rt[i]=rt[i-1];
			x=read();
			y=read();
			ll fx=getf(rt[i],x);
			ll fy=getf(rt[i],y);
			if(fx==fy){
//				printf("1\n");
				pc('1');
				pc('\n');
			}else{
//				printf("0\n");
				pc('0');
				pc('\n');
			}
		}
	}
	return fwrite(pp,1,pp_,stdout),0;
}

//#include<bits/stdc++.h>
//#define max(x,y) ((x)>(y)?(x):(y))
//#define min(x,y) ((x)<(y)?(x):(y))
//#define LL long long
//#define swap(x,y) (x^y?(x^=y,y^=x,x^=y):0)
//#define tc() (A==B&&(B=(A=ff)+fread(ff,1,100000,stdin),A==B)?EOF:*A++)
//#define pc(ch) (pp_<100000?pp[pp_++]=(ch):(fwrite(pp,1,100000,stdout),pp[(pp_=0)++]=(ch)))
//#define N 200000 
//int pp_=0;char ff[100000],*A=ff,*B=ff,pp[100000];
//using namespace std;
//int n,Q,tot=0,rt[N+5],a[N+5];
//struct Chairman_Tree
//{
//    int Son[2],fa,level;
//}node[N*20];
//inline void read(int &x)
//{
//    x=0;int f=1;char ch;
//    while(!isdigit(ch=tc())) f=ch^'-'?1:-1;
//    while(x=(x<<3)+(x<<1)+ch-'0',isdigit(ch=tc()));
//    x*=f;
//}
//inline void write(int x)
//{
//    if(x<0) pc('-'),x=-x;
//    if(x>9) write(x/10);
//    pc(x%10+'0');
//}
//inline void Build(int &rt,int l,int r)//初始的建树，一开始每个节点的fa都是本身，这是并查集的基础思想
//{
//	rt=++tot;
//	int mid=l+r>>1;
//	if(!(l^r)) {node[rt].fa=l;return;}
//	Build(node[rt].Son[0],l,mid),Build(node[rt].Son[1],mid+1,r);
//}
//inline void NewPoint(int &rt,int lst,int l,int r,int x,int fa)//新插入一个节点
//{
//	rt=++tot;
//	int mid=l+r>>1;
//	if(!(l^r)) {node[rt].fa=fa,node[rt].level=node[lst].level;return;}//更新fa，并复制以前版本的这个节点的level
//	node[rt].Son[0]=node[lst].Son[0],node[rt].Son[1]=node[lst].Son[1];
//	if(x<=mid) NewPoint(node[rt].Son[0],node[lst].Son[0],l,mid,x,fa);
//	else NewPoint(node[rt].Son[1],node[lst].Son[1],mid+1,r,x,fa);
//}
//inline void Add_level(int rt,int l,int r,int x)//增加一个节点的在按秩合并时的优先级
//{
//	int mid=l+r>>1;
//	if(!(l^r)) {++node[rt].level;return;}
//	if(x<=mid) Add_level(node[rt].Son[0],l,mid,x);
//	else Add_level(node[rt].Son[1],mid+1,r,x);
//}
//inline int Query(int rt,int l,int r,int x)//询问x节点在某一版本下的位置
//{
//	int mid=l+r>>1;
//	if(!(l^r)) return rt;
//	if(x<=mid) return Query(node[rt].Son[0],l,mid,x);
//	else return Query(node[rt].Son[1],mid+1,r,x);
//}
//inline int getfa(int rt,int x)//询问x节点在某一版本下的祖先
//{
//	int fa=Query(rt,1,n,x);
//	return node[fa].fa^x?getfa(rt,node[fa].fa):fa;//如果x节点在该版本下的父亲等于它本身，就返回x，否则返回x的父亲在这个版本下的祖先，和经典的getfa()函数差不多
//}
//inline void connect(int v,int x,int y)//在版本v中连接x和y，将他们放入一个集合中
//{
//	int fx=getfa(rt[v],x),fy=getfa(rt[v],y);//先求出版本v中它们的祖先
//	if(!(fx^fy)) return;//如果祖先相同，就退出函数
//	if(node[fx].level<node[fy].level) swap(fx,fy);//如果x的优先级小于y的优先级，就交换x和y
//	NewPoint(rt[v],rt[v-1],1,n,node[fy].fa,node[fx].fa);//将优先级小的节点的父亲连向优先级大的节点的父亲
//	if(!(node[fx].level^node[fy].level)) Add_level(rt[v],1,n,node[fx].fa);//如果它们的优先级相同，就将它们合并后的祖宗的优先级加1
//}
//int main()
//{
//	freopen("bing.in","r",stdin);
//    register int i;
//    for(read(n),read(Q),Build(rt[0],i=1,n);i<=Q;++i)//先建一棵树，然后进行操作
//    {
//    	int op,x,y;read(op),read(x);
//    	if(op^2) read(y),rt[i]=rt[i-1];
//    	switch(op)
//    	{
//    		case 1:connect(i,x,y);break;//在当前版本下连接x和y
//    		case 2:rt[i]=rt[x];break;//将当前版本还原回曾经的版本x
//    		case 3:pc(getfa(rt[i],x)^getfa(rt[i],y)?'0':'1'),pc('\n');break;//若当前版本下x和y的父亲相同，输出1，否则输出0
//		}
//    }
//    return fwrite(pp,1,pp_,stdout),0;
//}

