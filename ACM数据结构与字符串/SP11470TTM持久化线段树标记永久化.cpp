/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2023/11/19 22:15:00
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
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/
struct CT{
	ll sum,l,r,tg;
	int son[2];
	ll mid;
}s[maxn*20];
ll a[maxn],n,m,cnt,minx,maxx,t;
ll tot,rt[maxn],l,r,d,cur,now,w[maxn]; 
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

void build(int l,int r,int v){
//	++tot;
	s[v].l=l;
	s[v].r=r;
	int mid=(l+r)>>1;
	s[v].mid=mid;
	if(l==r){
		s[v].sum=a[l];
		s[v].tg=0;
		return;
	}
	++tot;
	s[v].son[0]=tot;
	build(l,mid,tot);
	++tot;
	s[v].son[1]=tot;
	build(mid+1,r,tot);
	s[v].sum=s[s[v].son[0]].sum+s[s[v].son[1]].sum;
}


void add(ll xz,ll las){
	
	s[xz].l=s[las].l;
	s[xz].r=s[las].r;
	s[xz].mid=s[las].mid;
	s[xz].sum=s[las].sum+1ll*(min(r,s[las].r)-max(l,s[las].l)+1)*d;
	s[xz].tg=s[las].tg;
//	cout<<xz<<" "<<s[xz].l<<" "<<s[xz].r<<endl;
	
	if(s[xz].l>=l&&s[xz].r<=r){
		s[xz].tg+=d;
		s[xz].son[0]=s[las].son[0];
		s[xz].son[1]=s[las].son[1];
		return;
	}
	if(l<=s[las].mid){
		s[xz].son[0]=++tot;
		add(tot,s[las].son[0]);
	}else{
		s[xz].son[0]=s[las].son[0];
	}
	if(r>s[las].mid){
		s[xz].son[1]=++tot;
		add(tot,s[las].son[1]);
	}else{
		s[xz].son[1]=s[las].son[1];
	}
}

ll ask(ll xz){
	if(xz!=0)
//	cout<<xz<<" "<<s[xz].l<<" "<<s[xz].r<<endl;

	if(s[xz].l>=l&&s[xz].r<=r){
		return s[xz].sum;
	}
	ll tmp=0;
	if(l<=s[xz].mid)tmp+=ask(s[xz].son[0]);
	if(r>s[xz].mid)tmp+=ask(s[xz].son[1]);
	return tmp+1ll*(min(r,s[xz].r)-max(l,s[xz].l)+1)*s[xz].tg;
}

int main(){
	n=read();
	m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	} 
	rt[0]=1;
	tot=1;
	build(1,n,1);
	cur=0;
	for(int i=1;i<=m;++i){
		char op[2];
		scanf("%s",op);
		if(op[0]=='C'){
			l=read();
			r=read();
			d=read();
			cur++;
//			now++;
//			w[now]=cur;
			rt[cur]=++tot;
			add(tot,rt[cur-1]);
		}
		if(op[0]=='Q'){
			l=read();
			r=read();
//			cout<<w[now]<<endl;
			printf("%lld\n",ask(rt[cur]));
		}
		if(op[0]=='H'){
			l=read();
			r=read();
			t=read();
			printf("%lld\n",ask(rt[t]));
		}
		if(op[0]=='B'){
			t=read();
//			now=t;
//			++cur;
//			w[now]=cur;
//			rt[cur]=rt[cur-1];
			cur=t;
		}
	}
	return 0;
}


