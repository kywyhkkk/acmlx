/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2024/2/2 12:53:32
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
		ll pd1=0,pd2=0;
		char s1[10]="dfs",s2[10]="DFS";
		char s[100];
		n=read();
		scanf("%s",s);
		for(int i=0;i<n;++i){
			if(s[i]==s1[pd1]){
				pd1++;
			}
			if(s[i]==s2[pd2]){
				pd2++;
			}
		}
		if(pd2>=3){
			printf("1 ");
		}else{
			printf("0 ");
		}
		if(pd1>=3){
			printf("1\n");
		}else{
			printf("0\n");
		}
	} 
	return 0;
}


