/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2024/1/29 17:26:44
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
ll w[maxn],n,m,s,cnt,minx,maxx,d[maxn],ans;
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
	ll W=read();
	for(int i=1;i<=n;++i){
		w[i]=read();
	}
	for(int i=1;i<=n;++i){
		d[i]=read();
	}
	ll j=1,res=w[1],tmp=d[1];
	if(res>=W){
		ans=tmp;
	}
	for(int i=2;i<=n;++i){
		res+=w[i];
		tmp+=d[i];
		if(res>=W){
			ans=max(ans,tmp);
		}
		while(res-w[j]>=W&&j<=i){
			res-=w[j];
			tmp-=d[j];
			ans=max(ans,tmp);
			j++;
		}
	}
	
	printf("%lld",ans);
	return 0;
}


