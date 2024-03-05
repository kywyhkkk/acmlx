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
//inline void Build(int &rt,int l,int r)//��ʼ�Ľ�����һ��ʼÿ���ڵ��fa���Ǳ������ǲ��鼯�Ļ���˼��
//{
//	rt=++tot;
//	int mid=l+r>>1;
//	if(!(l^r)) {node[rt].fa=l;return;}
//	Build(node[rt].Son[0],l,mid),Build(node[rt].Son[1],mid+1,r);
//}
//inline void NewPoint(int &rt,int lst,int l,int r,int x,int fa)//�²���һ���ڵ�
//{
//	rt=++tot;
//	int mid=l+r>>1;
//	if(!(l^r)) {node[rt].fa=fa,node[rt].level=node[lst].level;return;}//����fa����������ǰ�汾������ڵ��level
//	node[rt].Son[0]=node[lst].Son[0],node[rt].Son[1]=node[lst].Son[1];
//	if(x<=mid) NewPoint(node[rt].Son[0],node[lst].Son[0],l,mid,x,fa);
//	else NewPoint(node[rt].Son[1],node[lst].Son[1],mid+1,r,x,fa);
//}
//inline void Add_level(int rt,int l,int r,int x)//����һ���ڵ���ڰ��Ⱥϲ�ʱ�����ȼ�
//{
//	int mid=l+r>>1;
//	if(!(l^r)) {++node[rt].level;return;}
//	if(x<=mid) Add_level(node[rt].Son[0],l,mid,x);
//	else Add_level(node[rt].Son[1],mid+1,r,x);
//}
//inline int Query(int rt,int l,int r,int x)//ѯ��x�ڵ���ĳһ�汾�µ�λ��
//{
//	int mid=l+r>>1;
//	if(!(l^r)) return rt;
//	if(x<=mid) return Query(node[rt].Son[0],l,mid,x);
//	else return Query(node[rt].Son[1],mid+1,r,x);
//}
//inline int getfa(int rt,int x)//ѯ��x�ڵ���ĳһ�汾�µ�����
//{
//	int fa=Query(rt,1,n,x);
//	return node[fa].fa^x?getfa(rt,node[fa].fa):fa;//���x�ڵ��ڸð汾�µĸ��׵����������ͷ���x�����򷵻�x�ĸ���������汾�µ����ȣ��;����getfa()�������
//}
//inline void connect(int v,int x,int y)//�ڰ汾v������x��y�������Ƿ���һ��������
//{
//	int fx=getfa(rt[v],x),fy=getfa(rt[v],y);//������汾v�����ǵ�����
//	if(!(fx^fy)) return;//���������ͬ�����˳�����
//	if(node[fx].level<node[fy].level) swap(fx,fy);//���x�����ȼ�С��y�����ȼ����ͽ���x��y
//	NewPoint(rt[v],rt[v-1],1,n,node[fy].fa,node[fx].fa);//�����ȼ�С�Ľڵ�ĸ����������ȼ���Ľڵ�ĸ���
//	if(!(node[fx].level^node[fy].level)) Add_level(rt[v],1,n,node[fx].fa);//������ǵ����ȼ���ͬ���ͽ����Ǻϲ�������ڵ����ȼ���1
//}
//int main()
//{
//	freopen("bing.in","r",stdin);
//    register int i;
//    for(read(n),read(Q),Build(rt[0],i=1,n);i<=Q;++i)//�Ƚ�һ������Ȼ����в���
//    {
//    	int op,x,y;read(op),read(x);
//    	if(op^2) read(y),rt[i]=rt[i-1];
//    	switch(op)
//    	{
//    		case 1:connect(i,x,y);break;//�ڵ�ǰ�汾������x��y
//    		case 2:rt[i]=rt[x];break;//����ǰ�汾��ԭ�������İ汾x
//    		case 3:pc(getfa(rt[i],x)^getfa(rt[i],y)?'0':'1'),pc('\n');break;//����ǰ�汾��x��y�ĸ�����ͬ�����1���������0
//		}
//    }
//    return fwrite(pp,1,pp_,stdout),0;
//}

