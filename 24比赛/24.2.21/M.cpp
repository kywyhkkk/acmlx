/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2024/2/21 14:47:31
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
ll a[maxn],n,m,s,cnt,minx,maxx;
ll b[maxn];
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
	ll T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		for(int i=1;i<=n;++i){
			b[i]=read();
		}
		if(n==1){
			printf("-1\n");
			continue;
		}
		if(n==2){
			if(a[1]==b[1]){
				printf("-1\n");
			}else{
				printf("1\n");
			}
			continue;
		}
		ll pd=0;
		for(int i=2;i<=n-1;++i){
			if(a[i]==b[i]){
				pd=1;
				break;
			}
		}
		if(pd==1){
			printf("1\n");
			continue;
		}
		for(int i=1;i<=n-1;++i){
			if(a[i]==b[i+1]||b[i]==a[i+1]){
				pd=1;
				break;
			}
		}
		if(pd==1){
			printf("1\n");
			continue;
		}
		printf("2\n");
	}
	return 0;
}


