/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2024/2/2 16:37:04
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
ll n,x[maxn],y[maxn],r[maxn],sum,cntx,cnty; 
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
		x[i]=read();
		y[i]=read();
		r[i]=read();
		sum+=r[i];
		if(abs(x[i])>50){
			cntx++;
		}
		if(abs(y[i])>50){
			cnty++;
		}
	}
	ll res1,res2;
	res1=abs(n/2-cntx);
	res2=abs(n/2-cnty);
	if(res1>=n/100||res2>=n/100){
		printf("buaa-noob");
	}else{
		printf("bit-noob");
	}
//	ll tmp=sum/n;
//	if(tmp<=45){
//		printf("bit-noob");
//	}else{
//		printf("buaa-noob");
//	}
	return 0;
}


