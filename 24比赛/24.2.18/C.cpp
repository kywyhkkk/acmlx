/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2024/2/18 20:26:14
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
ll yuan[maxn],n,m,ans,cnt,minx,maxx;
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
ll exgcd(ll a,ll b,ll &x,ll &y)//扩展欧几里得算法 
{
	if(b==0)
	{
		x=1,y=0;
		return a;
	}
	ll ret=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return ret;
}
ll getInv(int a,int mod)//求a在mod下的逆元，不存在逆元返回-1 
{
	ll x,y;
	ll d=exgcd(a,mod,x,y);
	return d==1?(x%mod+mod)%mod:-1;
}

int main(){
	ll T=read();
	while(T--){
		n=read();
		m=read();
		ans=1;
		ll l=1,r=n;
		for(int i=1;i<=n;++i){
			yuan[i]=read();
			ans*=yuan[i];
			ans%=m;
		}
//		ans=0;

		scanf("%s",s+1);
		ll len=strlen(s+1);
		for(int i=1;i<=len;++i){
			ll tmp;
			printf("%lld ",ans%m);
			if(s[i]=='L'){
				tmp=getInv(yuan[l],m);
				ans=ans*tmp%m;
				l++;
			}else{
				tmp=getInv(yuan[r],m);
				
				ans=ans*tmp%m;
				r--;
			}
			cout<<tmp<<endl;
		}
		printf("\n");
	}
	return 0;
}


