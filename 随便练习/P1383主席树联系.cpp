/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2024/1/10 22:22:53
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
struct P{
	ll sum,l,r;
	char z;
};
P node[maxn*20];
ll a[maxn],n,m,s,cnt,minx,maxx;
ll tot,root[maxn],gen,wei[maxn];
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

void build(P &x,ll l,ll r){
	x.sum=0;
	if(l==r){
		x.z=NULL;
		return;
	}
	ll mid=(l+r)>>1;
	x.l=++tot;
	build(node[x.l],l,mid);
	x.r=++tot;
	build(node[x.r],mid+1,r);
}

void insert(P pas,P &x,ll l,ll r,ll z,char tmp){
	x.sum=pas.sum+1;
	if(l==r){
		x.z=tmp;
		return;
	}
	ll mid=(l+r)>>1;
	if(z<=mid){
		x.l=++tot;
		insert(node[pas.l],node[x.l],l,mid,z,tmp);
		x.r=pas.r;
	}
	if(z>mid){
		x.r=++tot;
		insert(node[pas.r],node[x.r],mid+1,r,z,tmp);
		x.l=pas.l;
	}
}

void ask(P x,ll l,ll r,ll k){
	if(l==r){
		cout<<x.z<<endl;
		return;
	}
	ll res=node[x.l].sum;
	ll mid=(l+r)>>1;
	if(res>=k){
		ask(node[x.l],l,mid,k);
	}else{
		ask(node[x.r],mid+1,r,k-res);
	}
}

int main(){
	cin>>n;
	root[0]=++tot;
	build(node[tot],1,n);
	for(int i=1;i<=n;++i){
		char op,c;
		int x;
		cin>>op;
		if(op=='T'){
			cin>>c;
			wei[i]=wei[i-1]+1;
			gen++;
			root[gen]=++tot;
			insert(node[root[gen-1]],node[root[gen]],1,n,wei[i],c);
		}
		if(op=='U'){
			cin>>x;
			gen++;
			root[gen]=root[gen-1-x];
			wei[i]=node[root[gen]].sum;
		}
		if(op=='Q'){
			cin>>x;
			wei[i]=wei[i-1];
			ask(node[root[gen]],1,n,x);
		}
	
	} 
	return 0;
}


