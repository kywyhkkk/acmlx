/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2024/1/29 16:42:54
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
		char s[1010],f[1010];
		ll a[101],b[101];
		for(int i='A';i<='D';++i){
			a[i]=0;
			b[i]=0;
		}
		scanf("%s%s",s+1,f+1);
		ll len1=strlen(s+1),len2=strlen(f+1);
		for(int i=1;i<=len1;++i){
			a[s[i]]=1;
		}
		ll pd=10;
		for(int i=1;i<=len2;++i){
			b[f[i]]=1;
		}
		for(int i='A';i<='D';++i){
			if(b[i]==0&&a[i]==1){
				pd=0;
			}
		}
		printf("%lld\n",pd);
	}
	return 0;
}


