/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2024/2/18 20:52:09
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
ll a[maxn],n,m,s,cnt,minx,maxx;
ll cntc,cntd,cnts,cnth,C[101],D[101],S[101],H[101];
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
	cntc=0;
	cntd=0;
	cnth=0;
	cnts=0;
}

int main(){
	ll T=read();
	while(T--){
		init();
		n=read();
		char trum[4];
		scanf("%s",trum);
		for(int i=1;i<=n*2;++i){
			char x[3];
			scanf("%s",x);
			if(x[1]=='C'){
				cntc++;
				C[cntc]=x[0]-'0';
			}
			if(x[1]=='D'){
				cntd++;
				D[cntd]=x[0]-'0';
			}
			if(x[1]=='H'){
				cnth++;
				H[cnth]=x[0]-'0';
			}
			if(x[1]=='S'){
				cnts++;
				S[cnts]=x[0]-'0';
			}
		}
		sort(C+1,C+1+cntc);
		sort(D+1,D+1+cntd);
		sort(H+1,H+1+cnth);
		sort(S+1,S+1+cnts);
		ll res=cntc%2+cntd%2+cnth%2+cnts%2;
		if(trum[0]=='S'){
			res=res-cnts%2;
			if(cnts<res||((cnts-res)%2==1)){
				printf("IMPOSSIBLE\n");
				continue;
			}
			ll tmp=1;
			for(int i=2;i<=cntc;i+=2){
				printf("%lldC %lldC\n",C[i-1],C[i]);
			}
			if(cntc%2==1){
				printf("%lldC %lldS\n",C[cntc],S[tmp]);
				tmp++;
			}
			for(int i=2;i<=cntd;i+=2){
				printf("%lldD %lldD\n",D[i-1],D[i]);
			}
			if(cntd%2==1){
				printf("%lldD %lldS\n",D[cntd],S[tmp]);
				tmp++;
			}
			for(int i=2;i<=cnth;i+=2){
				printf("%lldH %lldH\n",H[i-1],H[i]);
			}
			if(cnth%2==1){
				printf("%lldH %lldS\n",H[cnth],S[tmp]);
				tmp++;
			}
			for(int i=tmp+1;i<=cnts;i+=2){
				printf("%lldS %lldS\n",S[i-1],S[i]);
			}
		}
		if(trum[0]=='C'){
			res=res-cntc%2;
			if(cntc<res||((cntc-res)%2==1)){
				printf("IMPOSSIBLE\n");
				continue;
			}
			ll tmp=1;
			for(int i=2;i<=cnts;i+=2){
				printf("%lldS %lldS\n",S[i-1],S[i]);
			}
			if(cnts%2==1){
				printf("%lldS %lldC\n",S[cnts],C[tmp]);
				tmp++;
			}
			for(int i=2;i<=cntd;i+=2){
				printf("%lldD %lldD\n",D[i-1],D[i]);
			}
			if(cntd%2==1){
				printf("%lldD %lldC\n",D[cntd],C[tmp]);
				tmp++;
			}
			for(int i=2;i<=cnth;i+=2){
				printf("%lldH %lldH\n",H[i-1],H[i]);
			}
			if(cnth%2==1){
				printf("%lldH %lldC\n",H[cnth],C[tmp]);
				tmp++;
			}
			for(int i=tmp+1;i<=cntc;i+=2){
				printf("%lldC %lldC\n",C[i-1],C[i]);
			}
		}
		if(trum[0]=='H'){
			res=res-cnth%2;
			if(cnth<res||((cnth-res)%2==1)){
				printf("IMPOSSIBLE\n");
				continue;
			}
			ll tmp=1;
			for(int i=2;i<=cntc;i+=2){
				printf("%lldC %lldC\n",C[i-1],C[i]);
			}
			if(cntc%2==1){
				printf("%lldC %lldH\n",C[cntc],H[tmp]);
				tmp++;
			}
			for(int i=2;i<=cntd;i+=2){
				printf("%lldD %lldD\n",D[i-1],D[i]);
			}
			if(cntd%2==1){
				printf("%lldD %lldH\n",D[cntd],H[tmp]);
				tmp++;
			}
			for(int i=2;i<=cnts;i+=2){
				printf("%lldS %lldS\n",S[i-1],S[i]);
			}
			if(cnts%2==1){
				printf("%lldS %lldH\n",S[cnts],H[tmp]);
				tmp++;
			}
			for(int i=tmp+1;i<=cnth;i+=2){
				printf("%lldH %lldH\n",H[i-1],H[i]);
			}
		}
		if(trum[0]=='D'){
			res=res-cntd%2;
			if(cntd<res||((cntd-res)%2==1)){
				printf("IMPOSSIBLE\n");
				continue;
			}
			ll tmp=1;
			for(int i=2;i<=cntc;i+=2){
				printf("%lldC %lldC\n",C[i-1],C[i]);
			}
			if(cntc%2==1){
				printf("%lldC %lldD\n",C[cntc],D[tmp]);
				tmp++;
			}
			for(int i=2;i<=cnts;i+=2){
				printf("%lldS %lldS\n",S[i-1],S[i]);
			}
			if(cnts%2==1){
				printf("%lldS %lldD\n",S[cnts],D[tmp]);
				tmp++;
			}
			for(int i=2;i<=cnth;i+=2){
				printf("%lldH %lldH\n",H[i-1],H[i]);
			}
			if(cnth%2==1){
				printf("%lldH %lldD\n",H[cnth],D[tmp]);
				tmp++;
			}
			for(int i=tmp+1;i<=cntd;i+=2){
				printf("%lldD %lldD\n",D[i-1],D[i]);
			}
		}
	}
	return 0;
}


