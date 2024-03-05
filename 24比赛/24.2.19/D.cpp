/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2024/2/19 13:45:52
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
const ll N=1000000;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/
ll a[maxn],n,m,s,cnt,minx,maxx;
ll num=1,sum,da[maxn],ans;
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
	for(int i=1;i<=n;++i){
		a[i]=read();
		sum+=a[i];
	}
	if(n==1){
		cout<<1;
		return 0;
	}
//	init();
	ll tmp=sqrt(sum);
	for(int i=1;i<tmp;++i){
		if(sum%i==0){
			cnt++;
			da[cnt]=i;
			cnt++;
			da[cnt]=sum/i;
		}
	}
	if(sum%tmp==0){
		cnt++;
		da[cnt]=tmp;
	}
	for(int i=1;i<=cnt;++i){
		if(sum/da[i]>=n)ans++;
	}
	cout<<ans;
	return 0;
}


