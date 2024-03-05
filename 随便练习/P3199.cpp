/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2024/1/25 21:46:18
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
ll u[10010],v[10010],n,m,s,cnt,minx,maxx;
double a[3010][3010],w[10010],ans=1000010;
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
	for(int i=1;i<=m;++i){
		u[i]=read();
		v[i]=read();
		scanf("%lf",&w[i]);
	}
	for(int i=0;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i==0){
				a[i][j]=0;
			}else{
				a[i][j]=inf;
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			a[i][v[j]]=min(a[i][v[j]],a[i-1][u[j]]+w[j]);
		}
	}
	for(int i=1;i<=n;++i){
		if(a[n][i]!=inf){
			double tmp=-inf;
			for(int j=0;j<n;++j){
				tmp=max(tmp,(a[n][i]-a[j][i])/(n-j));
			}
			ans=min(ans,tmp);
		}
	}
	printf("%.8lf",ans);
	return 0;
}


