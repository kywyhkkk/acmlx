/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2023/11/16 16:06:31
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
#define minf -1000000000
using namespace std;
const ll maxn=10001000;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/
struct stree{
	ll sum;
	int l,r,maxa,maxb,cnt,se;
	int tg1,tg2,tg3,tg4;
}s[2000005];
ll n,m,op,l,r,k,v;
ll a[500005],ans;
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
void pushup(int x){
	s[x].sum=s[x*2].sum+s[x*2+1].sum;
	s[x].maxa=max(s[x*2].maxa,s[x*2+1].maxa);
	s[x].maxb=max(s[x*2].maxb,s[x*2+1].maxb);
	if(s[x*2].maxa==s[x*2+1].maxa){
		s[x].se=max(s[x*2].se,s[x*2+1].se);
		s[x].cnt=s[x*2].cnt+s[x*2+1].cnt;
	}
	else{
		if(s[x*2].maxa>s[x*2+1].maxa){
			s[x].se=max(s[x*2].se,s[x*2+1].maxa);
			s[x].cnt=s[x*2].cnt;
		}else{
			s[x].se=max(s[x*2+1].se,s[x*2].maxa);
			s[x].cnt=s[x*2+1].cnt;
		}
	}
}

void build(int l,int r,int z){
	s[z].l=l;
	s[z].r=r;
	if(l==r){
		s[z].sum=s[z].maxa=s[z].maxb=a[l];
		s[z].cnt=1;
		s[z].se=minf;
		return ;
	}
	int mid=(l+r)>>1;
	build(l,mid,z*2);
	build(mid+1,r,z*2+1);
	pushup(z);
}

void jia(int k1,int k2,int k3,int k4,int z){
	s[z].sum+=1ll*k1*s[z].cnt+1ll*k2*(s[z].r-s[z].l+1-s[z].cnt);
	s[z].maxb=max(s[z].maxb,s[z].maxa+k3);
	s[z].maxa+=k1;
	if(s[z].se!=minf){
		s[z].se+=k2;
	}
	s[z].tg3=max(s[z].tg3,s[z].tg1+k3);
	s[z].tg4=max(s[z].tg4,s[z].tg2+k4);
	s[z].tg1+=k1;
	s[z].tg2+=k2;
	
}

void pushdown(int z){
	ll ma=max(s[z*2].maxa,s[z*2+1].maxa);
	if(ma==s[z*2].maxa){
		jia(s[z].tg1,s[z].tg2,s[z].tg3,s[z].tg4,z*2);
	}else{
		jia(s[z].tg2,s[z].tg2,s[z].tg4,s[z].tg4,z*2);
	}
	if(ma==s[z*2+1].maxa){
		jia(s[z].tg1,s[z].tg2,s[z].tg3,s[z].tg4,z*2+1);
	}else{
		jia(s[z].tg2,s[z].tg2,s[z].tg4,s[z].tg4,z*2+1);
	}	
	s[z].tg1=s[z].tg2=s[z].tg3=s[z].tg4=0;
	
}

void add(int z){
	if(l>s[z].r||r<s[z].l){
		return;
	}
	if(s[z].l>=l&&s[z].r<=r){
		s[z].maxa+=k;
		s[z].sum+=1ll*(s[z].r-s[z].l+1)*k;
		s[z].maxb=max(s[z].maxb,s[z].maxa);
		if(s[z].se!=minf){
			s[z].se+=k;
		}
		s[z].tg1+=k;
		s[z].tg2+=k;
		s[z].tg3=max(s[z].tg3,s[z].tg1);
		s[z].tg4=max(s[z].tg4,s[z].tg2);
		return ;
	}
	pushdown(z);
	add(z*2);
	add(z*2+1);
	pushup(z);
}

void xiao(int z){
	if(s[z].l>r||s[z].r<l||s[z].maxa<=v){
		return;
	}
	if(s[z].l>=l&&s[z].r<=r&&s[z].se<v){
		ll k=s[z].maxa-v;
		s[z].sum-=1ll*s[z].cnt*k;
		s[z].maxa=v;
		s[z].tg1-=k;
		return;
	}
	pushdown(z);
	xiao(z*2);
	xiao(z*2+1);
	pushup(z);
}

void asksum(int z){
	if(l>s[z].r||r<s[z].l){
		return;
	}
	if(l<=s[z].l&&r>=s[z].r){
		ans+=s[z].sum;
		return;
	}
	pushdown(z);
	asksum(z*2);
	asksum(z*2+1);
}

ll askma(int z){
	if(l>s[z].r||r<s[z].l){
		return minf;
	}
	if(l<=s[z].l&&r>=s[z].r){
	
		return s[z].maxa;
	}
	pushdown(z);
	return max(askma(z*2),askma(z*2+1));
	
}

ll askmb(int z){
	if(l>s[z].r||r<s[z].l){
		return minf;
	}
	if(l<=s[z].l&&r>=s[z].r){
	
		return s[z].maxb;
	}
	pushdown(z);
	return max(askmb(z*2),askmb(z*2+1));
	
}

int main(){
	n=read();
	m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	build(1,n,1);
	for(int i=1;i<=m;++i){
		op=read();
		if(op==1){
			l=read();
			r=read();
			k=read();
			add(1);
		}
		if(op==2){
			l=read();
			r=read();
			v=read();
			xiao(1);
		}
		if(op==3){
			l=read();
			r=read();
			ans=0;
			asksum(1);
			printf("%lld\n",ans);
		}
		if(op==4){
			l=read();
			r=read();
			ans=askma(1);
			printf("%lld\n",ans);
		}
		if(op==5){
			l=read();
			r=read();
			ans=askmb(1);
			printf("%lld\n",ans);
		}
	}
	return 0;
}


