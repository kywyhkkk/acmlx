/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2024/2/5 13:12:39
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
ll k,ans,ansx[330][330],ansy[330][330],n,m,s,cnt,minx,maxx;
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
	k=read();
	for(int i=1;i<=k;++i){
		ll x,y;
		x=read();
		y=read();
		ansx[x-1][y]=1;
		ansx[x][y]=1;
		ansy[x][y-1]=1;
		ansy[x][y]=1;
	}
	for(int i=0;i<=n;++i){
		for(int j=0;j<=m;++j){
			ans+=ansx[i][j]+ansy[i][j];
		}
	}
	cout<<ans;
	return 0;
}


