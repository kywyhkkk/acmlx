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
	int ch[maxn<<1][26],fa[maxn<<1],l[maxn<<1],size[maxn<<1],k[maxn<<1],c[maxn<<1];
	int last,tot;
	void init(){
		last=tot=1;
		memset(ch[1],0,sizeof ch[1]);
	}
	void ins(int c,int pos){
		int p=last,np=++tot;last=np;l[np]=l[p]+1;
		memset(ch[tot],0,sizeof ch[tot]);
		for(;p&&!ch[p][c];p=fa[p]){
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
				memcpy(ch[nq],ch[q],sizeof(ch[q]));
				fa[nq]=fa[q];fa[q]=fa[np]=nq;
				for(;ch[p][c]==q;p=fa[p])ch[p][c]=nq;
			}
		}
		size[np]=1;
	}
	void build(){
		init();
		int n=strlen(s+1);
		cout<<tot<<endl;
		for(int i=1;i<=n;++i){
			ins(s[i]-'0',i);
			cout<<tot<<endl;
		}
		for(int i=1;i<=tot;++i){
			c[l[i]]++;
		}
		for(int i=1;i<=tot;++i){
			c[i]+=c[i-1];
		}
		for(int i=1;i<=tot;++i){
			k[c[l[i]]--]=i;
		}
		for(int i=tot;i>=1;--i){
			int id=k[i];
			size[fa[id]]+=size[id];
		}
		
	}
	void shuchu(){
		ll ans=0;
		for(int i=1;i<=tot;++i){
			ans+=(l[i]-l[fa[i]]);
		}
		printf("%lld",ans);
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
	scanf("%s",s+1);
	sam.build(); 
	sam.shuchu();
	return 0;
}


