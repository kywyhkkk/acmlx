/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2024/2/21 14:40:07
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
ll a,t,n,m,s,cnt,minx,maxx;
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
	t=read();
	a=read();
	ll k=read();
	ll ans=0;
	if(a*t>=0){
		a=abs(a);
		t=abs(t);
		if(a>t){
			ans=t+a-t+a-t;
		}else{
			ans=t;
		}
	}else{
		a=abs(a);
		t=abs(t);
		if(k>=a){
			ans=a+t+a;
		}else{
			ans=t+t+a+t+a;
		}
	}
	cout<<ans;
	return 0;
}


