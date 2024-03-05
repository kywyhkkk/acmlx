/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2024/2/2 14:32:34
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
ll Q,tc,t[maxn],n,sum[maxn],m ;
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
	Q=read();
	tc=read();
	for(int i=1;i<=n;++i){
		t[i]=read();
	}
	sort(t+1,t+1+n);
	for(int i=1;i<=n;++i){
		sum[i]=sum[i-1]+t[i];
	}
	for(int i=1;i<=Q;++i){
		m=read();
		ll tmp=m/tc;
		ll res=max(0ll,n-tmp);
		printf("%lld\n",sum[res]+tc);
	}
	return 0;
}


