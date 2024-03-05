/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2024/2/23 14:49:57
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
ll a[maxn],n,m,s,cnt,minx,maxx,fa[maxn],t;
ll suma[maxn],b[maxn],sumb[maxn],fb[maxn],ans;
ll ansa[maxn],ansb[maxn],s2,t2,fa2[maxn],fb2[maxn];
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
	for(int i=1;i<=n;++i){
		a[i]=read();
		suma[i]=suma[i-1]+a[i];
	}
	for(int j=1;j<=m;++j){
		b[j]=read();
		sumb[j]=sumb[j-1]+b[j];
	}
	fa[0]=0;
	fb[0]=0;
	s=-124232134;
	t=-431422134;
	s2=143124124;
	t2=214242424;
	for(int i=1;i<=n;++i){
		fa[i]=min(fa[i-1],suma[i]);
		fa2[i]=max(fa2[i-1],suma[i]);
	}
	for(int i=1;i<=m;++i){
		fb[i]=min(fb[i-1],sumb[i]);
		fb2[i]=max(fb2[i-1],sumb[i]);
	}
	for(int i=1;i<=n;++i){
		ansa[i]=suma[i]-fa[i-1];
		t=max(t,ansa[i]);
		t2=min(t2,suma[i]-fa2[i-1]);
	}
	for(int i=1;i<=m;++i){
		ansb[i]=sumb[i]-fb[i-1];
		s=max(s,ansb[i]);
		s2=min(s2,sumb[i]-fb2[i-1]);
	}
//	cout<<t<<" "<<s<<endl;
	if(t>=0&&t2>=0&&s<=0&&s2<=0){
		ans=t2*s;
		printf("%lld",ans);
		return 0;
	}
	if(t<=0&&t2<=0&&s>=0&&s2>=0){
		ans=t*s2;
		printf("%lld",ans);
		return 0;
	}
	ans=max(s*t,s2*t2);
	cout<<ans;
	return 0;
}


