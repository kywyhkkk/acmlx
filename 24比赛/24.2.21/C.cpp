/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2024/2/21 13:14:38
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
const ll inf=1010101010000;
/*
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/
ll a[maxn],n,m,s,cnt,minx,maxx,r[maxn],l[maxn];
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
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	r[0]=inf;
	a[n+1]=inf;
	ll ans=0;
	for(int i=1;i<=n+1;++i){
		l[i]=a[i]-1;
		if(r[i-1]<=l[i]){
			ans+=r[i-1];
			r[i]=l[i]-r[i-1];
		}else{
			ans+=l[i];
			r[i]=0;
		}
	}
//	for(int i=1;i<=n;++i){
//		cout<<l[i]<<" ";
//	}cout<<endl;
//	for(int i=1;i<=n;++i){
//		cout<<r[i]<<" ";
//	}cout<<endl;
	cout<<ans;
	return 0;
}


