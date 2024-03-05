/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2024/1/29 17:00:08
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
ll xw[6]={0,-1,0,1},yw[6]={-1,0,1,0};
ll n,m,s,cnt,minx,maxx,pd,vis[1010][1010],ans,cntx,cnty;
char a[1010][1010];
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

void dfs(ll x,ll y){
	if(x<=0||y<=0||x>n||y>m||vis[x][y]){
		return;
	}
	vis[x][y]=1;
	if(a[x][y]!='.'){
		return;
	}
//	cnt++;
	ll res=0;
	for(int i=0;i<=3;++i){
		ll u,v;
		u=x+xw[i];
		v=y+yw[i];
		if(a[u][v]!='.'){
			res++;
		}else{
			if(u!=x){
				cntx=0;
			}
			if(v!=y){
				cnty=0;
			}
			dfs(u,v);
		}
	}
	if(res>=3){
		pd=0;
	}
}

int main(){
	n=read();
	m=read();
	for(int i=1;i<=n;++i){
		char s[1010];
		scanf("%s",s+1);
		for(int j=1;j<=m;++j){
			a[i][j]=s[j];
		}
	}
//	for(int i=1;i<=n;++i){
//		for(int j=1;j<=m;++j){
//			cout<<a[i][j];
//		}cout<<endl;
//	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(!vis[i][j]&&a[i][j]=='.'){
				cntx=1;
				cnty=1;
				pd=1;
				dfs(i,j);
				if(pd==1||cntx==1||cnty==1){
					ans++;
				}
				
			}
		}
	}
	printf("%lld",ans);
	return 0;
}


