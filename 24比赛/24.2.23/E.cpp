/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2024/2/23 13:53:36
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
ll a[maxn],n,m,cnt,minx,maxx;
char s[maxn],t[maxn];
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
	scanf("%s",s+1);
	scanf("%s",t+1);
	ll len=strlen(s+1);
	ll len2=strlen(t+1);
	if(len>=10){
		printf("to be continued.\n");
		printf("%lld",len2);
		return 0;
	}
	ll tmp=0;
	for(int i=3;i<=len;++i){
		tmp=tmp*10+s[i]-'0';
	}
	tmp=tmp/2+1;
	
	ll ji1=0,ji2=0;
	for(int i=1;i<=len2;++i){
		if(t[i]=='R'){
			ji1++;
		}
		if(t[i]=='P'){
			ji2++;
		}
		if(ji1==tmp){
			printf("kou!\n");
			printf("%d",i);
			return 0;
		}
		if(ji2==tmp){
			printf("yukari!\n");
			printf("%d",i);
			return 0;
		}
	}
	printf("to be continued.");
	printf("%lld",len2);
	return 0;
}


