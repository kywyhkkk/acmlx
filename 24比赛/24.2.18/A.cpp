/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2024/2/18 20:08:34
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
const ll maxn=100010;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/
ll f[maxn],n,m,s,cnt,minx,maxx,ans;
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
		char s[60];
		scanf("%s",s+1);
		f[0]=0;
		if(s[1]=='.'){
			f[1]=0;
		}
		if(s[1]=='@'){
			f[1]=1;
		}
		if(s[1]=='*'){
			f[1]=0;
		}
		ans=f[1];
		for(int i=2;i<=n;++i){
			f[i]=0;
			if(s[i-1]=='*'&&s[i-2]=='*'){
				break;
			}
			if(s[i]=='*'){
				continue;
			}
//			if(f[i])
			if(s[i-2]!='*'){
				if(s[i]=='@'){
					f[i]=max(f[i-2]+1,f[i]);
				}else{
					f[i]=max(f[i-2],f[i]);
				}
			}
			if(s[i-1]!='*'){
				if(s[i]=='@'){
					f[i]=max(f[i-1]+1,f[i]);
				}else{
					f[i]=max(f[i-1],f[i]);
				}
			}
			ans=max(ans,f[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}


