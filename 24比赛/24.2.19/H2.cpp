/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2024/2/19 14:04:30
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
ll n,m,s,cnt,minx,maxx,f[3010][3010],ans,youx[3010][3010],zuox[3010][3010];
char a[3010][3010],s1[3010];
ll f2[3010][3010];
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

ll solve(ll x,ll y,ll z,ll h){
	ll pd=1;
	ll j1=y+1,j2=y+z-2;
	for(int i=x-1;i>=x-h+1;i=i-1,j1=j1+1,j2=j2-1){
		if(a[i][j1]!='*'||a[i][j2]!='*'){
			pd=0;
			break;
		}
	}
	return pd;
}

void check(ll x){
	ll h=x/2+1;
	for(int i=h;i<=n;++i){
		for(int j=1;j<=m-x+1;++j){
			if(f[i][j]>=x&&youx[i][j]>=h&&zuox[i][j+x-1]>=h){
				ans++;
			}
		}
	}
}

int main(){
	n=read();
	m=read();
	for(int i=1;i<=n;++i){
		scanf("%s",s1+1);
		ll len=strlen(s1+1);
		for(int j=1;j<=len;++j){
			a[i][j]=s1[j];
		}
		for(int j=len;j>=1;--j){
			if(a[i][j]=='*'){
				f[i][j]=f[i][j+1]+1;
			}
		}
		for(int j=1;j<=len;++j){
			if(a[i][j]=='*'){
				f2[i][j]=f2[i][j-1]+1;
			}
		}
	}
	
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(a[i][j]=='*'){
				youx[i][j]=youx[i-1][j+1]+1;
				zuox[i][j]=zuox[i-1][j-1]+1;
			}
		}
	}
	
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			zuox[i][j]=min(zuox[i][j],f2[i][j]/2+1);
//			cout<<zuox[i][j];
		}
//		cout<<endl;
	}
	
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			youx[i][j]=min(youx[i][j],f[i][j]/2+1);
//			cout<<youx[i][j];
		}
//		cout<<endl;
	}
	
	for(int i=3;i<=m;i+=2){
		check(i);
	}
	
	printf("%lld\n",ans);
	return 0;
}


