/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2024/2/17 21:03:43
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
struct P{
	ll l,r,ans,nz;
};
P a[maxn];
ll n,q,b[maxn],c[maxn];
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

void pushup(ll bh){
	a[bh].l=a[bh*2].l;
	a[bh].r=a[bh*2+1].r;
	a[bh].nz=a[bh*2].nz+a[bh*2+1].nz;
	a[bh].ans=a[bh*2].ans+a[bh*2+1].ans;
	if((a[bh*2].r==0||a[bh*2+1].l==0)&&a[bh*2].nz&&a[bh*2+1].nz){
		a[bh].ans++;
	}
}

void modi(ll l,ll r,ll bh,ll x,ll z){
	if(l==r){
		a[bh].ans=0;
		if(z){
			a[bh].l=a[bh].r=a[bh].nz=1;
			
		}else{
			a[bh].l=a[bh].r=a[bh].nz=0;
		}
		return;
	}
	ll mid=(l+r)>>1;
	if(x<=mid){
		modi(l,mid,bh*2,x,z);
	}else{
		modi(mid+1,r,bh*2+1,x,z);
	}
	pushup(bh);
}

ll cal(ll x){
	if(c[x]){
		return b[x]*b[x-1]%10;
	}else{
		return (b[x]+b[x-1])%10;
	}
}
ll cnt=0;
ll ask(ll al,ll ar,ll l,ll r,ll bh){
//	if(al>r||ar<l){
//		return 0;
//	}
//cnt++;
//if(cnt>20){
//	return 0;
//}
//cout<<al<<" "<<ar<<" "<<l<<" "<<r<<endl;
	if(al<=l&&r<=ar){
		return a[bh].ans;
	}
	ll mid=(l+r)>>1;
	if(ar<=mid){
		return ask(al,ar,l,mid,bh*2);
	}else{
		if(al>mid){
			return ask(al,ar,mid+1,r,bh*2+1);
		}else{
			return ask(al,ar,l,mid,bh*2)+ask(al,ar,mid+1,r,bh*2+1);
		}
	}
//	return ask(al,ar,l,mid,bh*2)+ask(al,ar,mid+1,r,bh*2+1);
}

int main(){
	n=read();
	q=read();
	for(int i=1;i<=n;++i){
		b[i]=read();
		b[n+i]=b[i];
		char s[4];
		scanf("%s",s);
		if(s[0]=='*'){
			c[i]=1;
		}
		c[i+n]=c[i];
	}
	for(int i=2;i<=n*2;++i){
		modi(1,n*2,1,i,cal(i));
	}
	
	for(int i=1;i<=q;++i){
		ll op=read();
		if(op==1){
			ll x=read(),y=read();
			x++;
			char s[4];
			scanf("%s",s);
			if(s[0]=='*'){
				c[x]=1;
			}else{
				c[x]=0;
			}
			c[x+n]=c[x];
			b[x]=b[x+n]=y;
			if(x!=1){
				modi(1,n*2,1,x,cal(x));
			}
			modi(1,n*2,1,x+1,cal(x+1));
			modi(1,n*2,1,x+n,cal(x+n));
			if(x!=n){
				modi(1,n*2,1,x+n+1,cal(x+n+1));
			}
		}else{
			ll x=read();
			x++;
			if(!b[x]&&!ask(x+1,x+n-1,1,n*2,1)){
				printf("0\n");
				continue;
			}
			modi(1,n*2,1,x,b[x]);
			modi(1,n*2,1,x+n,b[x+n]);
			ll l=0,r=n/2,ans=-2;
			while(l<=r){
				ll mid=(l+r)>>1;
//				cout<<mid<<endl;
				if(ask(x+mid,x+n-mid,1,n*2,1)){
					ans=mid;
					l=mid+1;
				}else{
					r=mid-1;
				}
			}
			ans++;
			printf("%lld\n",ans);
			if(x>1){
				modi(1,n*2,1,x,cal(x));
			}
			modi(1,n*2,1,x+n,cal(x+n));
		}
	}
	return 0;
}


