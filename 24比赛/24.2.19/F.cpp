/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2024/2/19 15:28:00
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
const ll inf=0x3f3f3f3f3f3f3fll;
/*
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/
ll a[maxn],n,m,s,cnt,minx,maxx,ans[maxn],daan;
ll f[1010][1010][9],g[1010][1010][9];
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

ll askf(ll l,ll r,ll xl,ll xr,ll bh,ll k){
	if(l>r){
		return 0;
	}
	ll tmp=inf;
	for(int i=l;i<=r;++i){
		tmp=min(tmp,f[l][i][k]);
	}
	return tmp;
}

ll askg(ll l,ll r,ll xl,ll xr,ll bh,ll k){
	if(l>r){
		return 0;
	}
	ll tmp=-inf;
	for(int i=l;i<=r;++i){
		tmp=max(tmp,g[l][i][k]);
	}
	return tmp;
}

void solve(ll i,ll j,ll k)
{
	if(j-i+1<k){
		f[i][j][k]=0;
			g[i][j][k]=0;
			return;
	}
	if(i==j){
		f[i][j][k]=a[i];
		g[i][j][k]=a[i];
		return;
	}
	if(k%2==1){
		if(a[j]==0){
			f[i][j][k]=0;
			g[i][j][k]=0;
			return;
		}
		
		if(a[j]>0){
			ll tmp=askf(i,j-1,1,n,1,k-1);
			f[i][j][k]=tmp*a[j];
			g[i][j][k]=askg(i,j-1,1,n,1,k-1)*a[j];
			
		}
		if(a[j]<0){
			f[i][j][k]=askg(i,j-1,1,n,1,k-1)*a[j];
			g[i][j][k]=askf(i,j-1,1,n,1,k-1)*a[j];
		}
	}
	if(k%2==0){
		f[i][j][k]=askf(i,j-1,1,n,1,k-1)-a[j];
		g[i][j][k]=askg(i,j-1,1,n,1,k-1)-a[j];
	}
}

int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	
	for(int i=0;i<=n;++i){
		for(int j=0;j<=n;++j){
				f[i][j][0]=1;
				g[i][j][0]=1;
		}
	}
	
	for(int k=1;k<=6;++k){
		for(int i=1;i<=n;++i){
			for(int j=i;j<=n;++j){
				solve(i,j,k);
			}
//			for(int j=1;j<=n;++j){
//				lin[i][j]
//			}
		}
		
	}
//	cout<<g[1][6][6]<<endl;
//	cout<<g[7][13][6]<<endl;
	for(int i=0;i<=n;++i){
		for(int j=0;j<=n;++j){
			for(int k=0;k<=6;++k){
				g[i][j][k]=max(g[i][j][k],(ll)0);
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<=i-1;++j){
			ans[i]=max(ans[i],ans[j]+g[j+1][i][6]);
			
		}
		daan=max(ans[i],daan);
//		cout<<ans[i]<<" ";
	}
//	cout<<endl;
	printf("%lld\n",daan);
	return 0;
}


