/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2024/2/23 13:38:29
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
	ll x,y;
};
P a[maxn],b[maxn];
ll n,m,s,cnt,minx,maxx;
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

bool cmp(P x,P y){
	return x.x<y.x;
}
bool cmp2(P x,P y){
	return x.y<y.y;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i].x=read();
		a[i].y=i;
	}
	for(int i=1;i<=n;++i){
		b[i].x=read();
		b[i].y=i;
	}
	sort(a+1,a+1+n,cmp);
	sort(b+1,b+1+n,cmp);
	for(int i=1;i<=n;++i){
		a[i].y=b[i].y;
	}
	sort(a+1,a+1+n,cmp2);
	for(int i=1;i<=n;++i){
		printf("%lld ",a[i].x);
	}
	return 0;
}


