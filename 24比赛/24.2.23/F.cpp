/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2024/2/23 15:23:56
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
ll a[maxn],n,m,s,cnt,minx,maxx,N=1000000;
ll num=1,p[maxn],b[maxn],c[maxn];
ll cntb,cntc,ansb[maxn],ansc[maxn];
ll vis1[maxn];
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

void solve(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	maxx=0;
	for(int i=1;i<=n;++i){
		ll fb=1,fc=1;
		for(int j=1;j<=num-1;++j){
			if(p[j]>a[i]){
				break;
			}
			if(a[i]%p[j]==0){
				
				if(b[j]){
					fc=0;
				}
				if(c[j]){
					fb=0;
				}
			}
		}
		if(fb==0&&fc==0){
			printf("-1 -1\n");
			return;
		}
		cout<<"zheshi "<<a[i]<<" "<<fb<<" "<<fc<<endl;
		if(fb){
			for(int j=1;j<=num-1;++j){
				if(p[j]>a[i]){
					break;
				}
				if(a[i]%p[j]==0){
					maxx=max(maxx,(ll)j);
					b[j]=1;
				}
			}
			cntb++;
			ansb[cntb]=a[i];
		}else{
			for(int j=1;j<=num-1;++j){
				if(p[j]>a[i]){
					break;
				}
				if(a[i]%p[j]==0){
					maxx=max(maxx,(ll)j);
					c[j]=1;
				}
			}
			cntc++;
			ansc[cntc]=a[i];
		}
	}
	printf("%lld %lld\n",cntb,cntc);
	for(int i=1;i<=cntb;++i){
		printf("%lld ",ansb[i]);
	}
	printf("\n");
	for(int i=1;i<=cntc;++i){
		printf("%lld ",ansc[i]);
		
	}
	printf("\n");
}
void init(){
	vis1[1]=1;
	for(int i=1;i<=N;++i){
		if(!vis1[i]){
			p[num]=i;
			num++;
		}
		for(int j=1;j<num&&i*p[j]<=N;++j){
			vis1[i*p[j]]=1;
			if(i%p[j]==0){
				break;
			}
		}
	}
}
void chus(){
	cntb=0;
	cntc=0;
	fill(b,b+1+maxx+3,0);
	fill(c,c+1+maxx+3,0);
}
int main(){
	ll q=read();
	init();
	for(int i=1;i<=q;++i){
		chus();
		solve();
	}
	return 0;
}


