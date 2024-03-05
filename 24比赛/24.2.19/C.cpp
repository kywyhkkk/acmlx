/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2024/2/19 13:28:28
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
ll n,m,q,p,x,y,op[10101],z[10101];
char a[110][110],s1[1010];
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
	m=read();
	x=read();
	y=read();
	for(int i=1;i<=n;++i){
		scanf("%s",s1+1);
		ll len=strlen(s1+1);
		for(int j=1;j<=len;++j){
			a[i][j]=s1[j];
		}
	}
	p=read();
	q=read();
//	for(int i=1;i<=p;++i){
		for(int j=1;j<=q;++j){
			op[j]=read();
			z[j]=read();
			if(op[j]==1){
				char tmp=a[z[j]][m];
				for(int k=m;k>=2;--k){
					a[z[j]][k]=a[z[j]][k-1];
				}
				a[z[j]][1]=tmp;
			}
			if(op[j]==2){
				char tmp=a[n][z[j]];
				for(int k=n;k>=2;--k){
					a[k][z[j]]=a[k-1][z[j]];
				}
				a[1][z[j]]=tmp;
			}
		}
//	}
	for(int i=1;i<=p-1;++i){
		for(int j=1;j<=q;++j){
			if(op[j]==1){
				char tmp=a[z[j]][m];
				for(int k=m;k>=2;--k){
					a[z[j]][k]=a[z[j]][k-1];
				}
				a[z[j]][1]=tmp;
			}
			if(op[j]==2){
				char tmp=a[n][z[j]];
				for(int k=n;k>=2;--k){
					a[k][z[j]]=a[k-1][z[j]];
				}
				a[1][z[j]]=tmp;
			}
		}
	}
	cout<<a[x][y];
	return 0;
}


