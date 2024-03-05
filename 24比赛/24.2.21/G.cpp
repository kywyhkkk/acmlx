/*********************************************************************
    $PROGRAM$: 
    $COPYRIGHT$: 
    $AUTHOR$: 
    $DATETIME$: 2024/2/21 13:26:21
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
#include<queue>

using namespace std;
const ll maxn=10001000;
//const ll N=1000100;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/
struct P{
	ll x,y,bh;
};
P bian[maxn];
ll a[maxn],n,m,s,minx,maxx,num=1,N,cnt=1;
ll nex[maxn],head[maxn],to[maxn],val[maxn];
ll cur[maxn],dis[maxn],t,mp[maxn],ans,ji;
ll vis1[maxn],p[maxn],jil[maxn],da[maxn];
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

void add(ll x,ll y,ll z){
	cnt++;
	nex[cnt]=head[x];	 //当前边的后继 
	head[x]=cnt;		//起点x的第一条边 
	to[cnt]=y;			 //当前边终点 
	val[cnt]=z;			//当前边权值 
}

ll bfs(){
	queue<ll> qq;
	cur[s]=head[s];
	fill(dis,dis+n*2+100,0);
	dis[s]=1;	//每个点对应的层数 
	qq.push(s);
	while(!qq.empty()){
		ll x=qq.front();
		qq.pop();
		for(int i=head[x];i;i=nex[i]){
			ll to2=to[i];
			if(val[i]<=0||dis[to2]){
				continue;
			} 
			dis[to2]=dis[x]+1;
			qq.push(to2);
			cur[to2]=head[to2];
		}
	}
	if(dis[t]==0){
		return 0;
	}else{
		return 1;
	}
}

ll dfs(ll x,ll z){
	if(x==t){
		return z;
	}
	ll res=0;
	for(int i=cur[x];i;i=nex[i]){
		cur[x]=i;	//将当前弧设置为现在遍历的边 
		ll to2=to[i];
		if(val[i]==0||dis[to2]!=dis[x]+1){
			continue;
		}
		ll k=dfs(to2,min(z,val[i]));
		val[i]-=k;
		val[i^1]+=k;
		res+=k;
		z-=k;
	}
	return res;
}
void init(){
	vis1[1]=1;
	for(int i=1;i<=N;++i){
		if(!vis1[i]){
			p[num]=i;
			num++;
		}
		for(int j=1;j<num&&i*p[j]<=N;++j){
			vis1[i*p[j]]=1;
			if(i%p[j]==0){
				break;
			}
		}
	}
}

int main(){
	n=read();
	N=n*2+1;
	init();
	cout<<num<<endl; 
	for(int i=1;i<=num;++i){
		mp[p[i]]=1;
	}
	if(n>1000){
		if(mp[n+1]==0){
			printf("-1");
		}else{
			for(int i=1;i<=n;++i){
				printf("%lld ",(ll)n-i+1);
			}
		}
		return 0;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(mp[i+j]){
				add(i,j+n,1);
				ji++;
				bian[ji].bh=cnt;
				bian[ji].x=i;
				bian[ji].y=j;
				add(j+n,i,0);
			}
		}
	}
	s=n+n+10;
	t=n+n+11;
	for(int i=1;i<=n;++i){
		add(s,i,1);
		add(i,s,0);
		add(i+n,t,1);
		add(t,i+n,0);
	}
	while(bfs()){
//		jishu++;
//		if(jishu>20){
//			break;
//		}
//cout<<ans<<endl;
		ans+=dfs(s,99991299912);
//		cout<<ans<<endl;
	}
//	cout<<ans<<endl;
	if(ans<n){
		printf("-1");
		return 0;
	}
	for(int i=1;i<=ji;++i){
		if(val[bian[i].bh]==0){
			da[bian[i].x]=bian[i].y;
		}
	}
	for(int i=1;i<=n;++i){
		printf("%lld ",da[i]);
	}
	return 0;
}


