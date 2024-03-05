/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2024/2/18 21:22:02
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
ll sum[maxn],ans[maxn];
char s[maxn];
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
		scanf("%s",s+1);
		ll len=strlen(s+1);
		ll pd=0,cnta=0;
		for(int i=1;i<=len;++i){
			if(pd==0){
				if(s[i]=='0'){
					continue;
				}else{
					pd=1;
				}
			}
			cnta++;
			a[cnta]=s[i]-'0';
		}
		len=cnta;
		for(int i=1;i<=len;++i){
			sum[i]=sum[i-1]+a[i];
		}
		for(int i=2;i<=len;++i){
			a[i]=a[i]+sum[i-1];
		}
//		ll tmp=0;
//		for(int i=1;i<=len-1;++i){
//			tmp++;
//			jia[tmp]=a[i];
//			for(int j=1;j<=tmp;++j){
//				a[len-tmp+j]+=jia[j];
//			}
//		}
		ans[len]=0;
		for(int i=len;i>=1;--i){
			a[i-1]+=a[i]/10;
			ans[i]=a[i]%10;
		}
		ans[0]=a[1]/10;
		if(ans[0]==0){
			for(int i=1;i<=len;++i){
				printf("%lld",ans[i]);
			}
		}else{
			for(int i=0;i<=len;++i){
				printf("%lld",ans[i]);
			}
		}
		printf("\n");
	}
	return 0;
}


