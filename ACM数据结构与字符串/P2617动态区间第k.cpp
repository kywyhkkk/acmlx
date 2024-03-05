/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2023/12/9 22:27:24
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
const ll maxn=1010;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/
struct P{
	ll v,l,r;
};
struct C{
	char op;
	ll x,y,val;
}cao[maxn];

P shu[maxn*200];
ll a[maxn],n,m,s,num[4],minx,maxx,tot;
ll xiu[3][30],rt[maxn],b[maxn*2],len;
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

void modify(ll &cur,int l,int r,int pos,int val){
	if(!cur){
		cur=++tot;
	}
	shu[cur].v+=val;
	if(l==r){
		return;
	}
	ll mid=(l+r)>>1;
	if(pos<=mid){
		modify(shu[cur].l,l,mid,pos,val);
	}else{
		modify(shu[cur].r,mid+1,r,pos,val);
	}
} 

ll query(ll l,ll r,ll val){
	if(l==r){
		return l;
	}
	ll mid=(l+r)>>1,res=0;
	for(int i=1;i<=num[0];++i){
		res-=shu[shu[xiu[0][i]].l].v;
	}
	for(int i=1;i<=num[1];++i){
		res+=shu[shu[xiu[1][i]].l].v; 
	}
	if(val<=res){
		for(int i=1;i<=num[0];++i){
			xiu[0][i]=shu[xiu[0][i]].l;
		}
		for(int i=1;i<=num[1];++i){
			xiu[1][i]=shu[xiu[1][i]].l;
		}
		query(l,mid,val);
	}else{
		for(int i=1;i<=num[0];++i){
			xiu[0][i]=shu[xiu[0][i]].r;
		}
		for(int i=1;i<=num[1];++i){
			xiu[1][i]=shu[xiu[1][i]].r;
		}
		query(mid+1,r,val-res);
	}
}

ll ask(ll l,ll r,ll k){
	memset(xiu,0,sizeof(xiu));
	num[0]=num[1]=0;
	for(int i=r;i;i-=i&-i){
		xiu[1][++num[1]]=rt[i];
	}
	for(int i=l-1;i;i-=i&-i){
		xiu[0][++num[0]]=rt[i];
	}
	return query(1,n,k);
}

int main(){
	n=read();
	m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		b[i]=a[i];
		
	}
	len=n;
	for(int i=1;i<=m;++i){
		char z[2];
		ll x,y,val;
		scanf("%s",z);
		if(z[0]=='Q'){
			cao[i].op=z[0];
			x=read();
			y=read();
			val=read();
			cao[i].x=x;
			cao[i].y=y;
			cao[i].val=val;
			
		}
		if(z[0]=='C'){
			x=read();
			y=read();
			cao[i].op=z[0];
			cao[i].x=x;
			cao[i].y=y;
			n++;
			b[n]=y;
		}
	}
	sort(b+1,b+1+n);
	n=unique(b+1,b+1+n)-b-1;
//	cout<<n<<endl;
	for(int i=1;i<=len;++i){
		int k=lower_bound(b+1,b+1+n,a[i])-b;
		for(int j=i;j<=len;j+=j&-j){
			modify(rt[j],1,n,k,1);
		}
	}
	for(int i=1;i<=m;++i){
		char z[2];
		ll x,y,val;
//		cout<<cao[i].op<<endl;
		if(cao[i].op=='Q'){
			x=cao[i].x;
			y=cao[i].y;
			val=cao[i].val;
			printf("%lld\n",b[ask(x,y,val)]);
		}
		if(cao[i].op=='C'){
			x=cao[i].x;
			y=cao[i].y;
//			cout<<x<<" "<<y<<endl;
			int k=lower_bound(b+1,b+1+n,a[x])-b;
			for(int j=x;j<=len;j+=j&-j){
				modify(rt[j],1,n,k,-1);
			}
			a[x]=y;
			k=lower_bound(b+1,b+1+n,a[x])-b;
			for(int j=x;j<=len;j+=j&-j){
				modify(rt[j],1,n,k,1);
			}
		}
	}
	return 0;
}


