/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2024/2/19 14:25:39
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
#include<map>
using namespace std;
const ll maxn=10001000;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/
map<ll,ll> mp,cun;
ll a[maxn],n,m,s,cnt,minx,maxx,k,sum[maxn];
ll f[maxn];
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
	k=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		sum[i]=sum[i-1]+a[i];
	}
	cun[0]=1;
	for(int i=1;i<=n;++i){
		f[i]=f[i-1];
		ll tmp=sum[i]%k;
//		tmp%=k;
//		f[i]=max(f[i],mp2[tmp]+f[mp1[tmp]]);
		if(cun[tmp]){
			f[i]=max(f[i],mp[tmp]+1);
		}
		
		ll res=sum[i]%k;
		cun[res]=1;
		if(mp[res]<f[i]){
			mp[res]=f[i];
		}
//		cout<<f[i]<<endl;
	}
	printf("%lld\n",f[n]);
	return 0;
}


