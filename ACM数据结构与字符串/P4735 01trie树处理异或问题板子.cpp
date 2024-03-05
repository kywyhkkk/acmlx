/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2023/12/7 20:26:08
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
const ll maxn=600100;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/
ll tot,ans;
ll a[maxn],n,m,cnt,minx,maxx,s[maxn];
ll las[maxn*24],shu[maxn*24][2],root[maxn]; 
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

void ins(ll x,ll k,ll p,ll q,ll z){
	if(k<0){
		las[q]=x;
		return;
	}
	ll y=z>>k&1;
	if(p){
		shu[q][y^1]=shu[p][y^1];
	}
	shu[q][y]=++tot;
	ins(x,k-1,shu[p][y],tot,z);
	las[q]=max(las[shu[q][y]],las[shu[q][y^1]]);
}

ll ask(ll cur,ll z,ll k,ll la){
	if(k<0){
		return las[cur];
	}
	ll y=z>>k&1;
	if(las[shu[cur][y^1]]>=la){
		return ask(shu[cur][y^1],z,k-1,la);
	}else{
		return ask(shu[cur][y],z,k-1,la);
	}
}

int main(){
	n=read();
	m=read();
	las[0]=-1;
	root[0]=++tot;
	ins(0,23,0,root[0],0);
	cout<<las[0]<<endl;
	for(int i=1;i<=n;++i){
		a[i]=read();
		s[i]=s[i-1]^a[i];
		root[i]=++tot;
		ins(i,23,root[i-1],root[i],s[i]);
	} 
	
	for(int i=1;i<=m;++i){
		char z[2];
		ll x,y,val;
		scanf("%s",z);
		if(z[0]=='A'){
			x=read();
			root[++n]=++tot;
			s[n]=s[n-1]^x;
			ins(n,23,root[n-1],tot,s[n]);
		}
		if(z[0]=='Q'){
			x=read();
			y=read();
			val=read();
			ans=ask(root[y-1],s[n]^val,23,x-1);
			printf("%lld\n",val^s[ans]^s[n]);
//			printf("%lld\n",ans);
		}
	}
	return 0;
}


