/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2024/1/29 16:50:55
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
const ll maxn=1000100;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/
ll f[maxn];
ll a[maxn],n,m,s,cnt,minx,maxx;
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
int main(){
	n=read();
	m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=1;i<=n;++i){
		f[i]=f[i-1];
		if(a[i]!=a[i-1]){
			f[i]=f[i-1]+1;
		}
//		cout<<f[i]<<endl;
	}
	
	for(int i=1;i<=m;++i){
		ll l,r;
		l=read();
		r=read();
		if(a[l]==a[l-1]){
			printf("%lld\n",f[r]-f[l-1]+1);
		}else{
			printf("%lld\n",f[r]-f[l-1]);
		}
	}
	return 0;
}


