/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2024/2/23 13:31:14
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
ll vis1[maxn],p[maxn],num=1;
ll a[maxn],n,m,s,cnt,minx,maxx,N=120,l,r,ans=0;
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

void init(){
	vis1[1]=1;
	for(int i=1;i<=N;++i){
		if(!vis1[i]){
			p[num]=i;
			num++;
		}
		for(int j=1;j<num&&i*p[j]<=N;++j){
			vis1[i*p[j]]=1;
			if(i%p[j]==0){
				break;
			}
		}
	}
}

int main(){
	l=read();
	r=read();
	init();
	for(int i=1;i<=num-1;++i){
		for(int j=1;j<=num-1;++j){
			for(int k=1;k<=num-1;++k){
				ll x=p[i],y=p[j],z=p[k];
				if(x==y||x==z||y==z){
					continue;
				}
				if(x*y*z<=r&&x*y*z>=l){
					ans=x*y*z;
				}
			}
		}
	}
	if(ans==0){
		cout<<-1;
	}else{
		cout<<ans;
	}
	return 0;
}


