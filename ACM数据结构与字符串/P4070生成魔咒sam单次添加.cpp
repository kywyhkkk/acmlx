/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2023/12/21 20:34:35
    $DESCRIPTION$: 
*********************************************************************/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
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
char s[maxn];
struct Suffix{
	int fa[maxn<<1],l[maxn<<1];
	int last,tot,ltot,ans;
	map<ll,ll> ch[maxn<<1];
	void init(){
		last=tot=1;
		ans=0;
//		memset(ch[1],0,sizeof ch[1]);
	}
	void ins(ll c,int pos){
		int p=last,np=++tot;last=np;l[np]=l[p]+1;
//		memset(ch[tot],0,sizeof ch[tot]);
		for(;p&&!ch[p].count(c);p=fa[p]){
			ch[p][c]=np;
		}
		if(!p){
			fa[np]=1;
		}else{
			int q=ch[p][c];
			if(l[p]+1==l[q]){
				fa[np]=q;
			}else{
				int nq=++tot;l[nq]=l[p]+1;
//				map<ll,ll>::iterator it;
//				for(it=ch[q].begin();it!=ch[q].end();it++){
//					ll res1=it->first;
//					ll res2=it->second;
//					ch[nq][res1]=res2;
//				}
				ch[nq]=ch[q];
//				memcpy(ch[nq],ch[q],sizeof(ch[q]));
				fa[nq]=fa[q];
				for(;p&&ch[p][c]==q;p=fa[p])ch[p][c]=nq;
				fa[np]=fa[q]=nq;
			}
		}
		ans+=l[np]-l[fa[np]];
	}
	void build(ll x,int y){
//		cout<<x-'0'<<" "<<y<<endl;
		ins(x,y);
		printf("%lld\n",ans);
	}
}sam;
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
	ll m=read();
	sam.init();
	for(int i=1;i<=m;++i){
		ll x=read();
		sam.build(x,i);
	}
	return 0;
}


