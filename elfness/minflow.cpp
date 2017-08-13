#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int V=600;
const int En=50000;
const int oo=0x3f3f3f3f;
struct Edge {
  int num,ne,c;
} e[En];
int p[V],K;
void add(int x,int y,int c) {
  e[K].num=y;
  e[K].c=c;
  e[K].ne=p[x];
  p[x]=K++;
  e[K].num=x;
  e[K].c=0;
  e[K].ne=p[y];
  p[y]=K++;
}
int d[V],cur[V],low[V],pre[V],gap[V],pree[V];
int st,ed,N;
int sap() {
  int ret=0;
  bool fail;
  memset(gap,0,sizeof(gap));
  memset(low,0,sizeof(low));
  memset(d,0,sizeof(d));
  for(int i=0; i<N; i++)cur[i]=p[i];
  gap[0]=N;
  low[st]=oo;
  int u=st;
  while(d[st]<N) {
    fail=true;
    for(int i=cur[u]; i!=-1; i=e[i].ne) {
      int v=e[i].num;
      cur[u]=i;
      if(e[i].c&&d[u]==d[v]+1) {
        pre[v]=u;
        pree[v]=i;
        low[v]=min(low[u],e[i].c);
        u=v;
        if(u==ed) {
          do {
            e[pree[u]].c-=low[ed];
            e[pree[u]^1].c+=low[ed];
            u=pre[u];
          } while(u!=st);
          ret+=low[ed];
        }
        fail=false;
        break;
      }
    }
    if(fail) {
      gap[d[u]]--;
      if(!gap[d[u]])return ret;
      d[u]=N;
      for(int i=p[u]; i!=-1; i=e[i].ne)
        if(e[i].c)d[u]=min(d[u],d[e[i].num]+1);
      gap[d[u]]++;
      cur[u]=p[u];
      if(u!=st)u=pre[u];
    }
  }
  return ret;
}
struct ELF {
  int u,v,lo;
} b[En];
int n,m,lb[V],ts,tt;
void solve() {
  N=n+4;
  ts=0;
  tt=n+1;
  st=n+2;
  ed=n+3;
  memset(lb,0,sizeof(lb));
  int i,u,v;
  for(i=0; i<N; i++)p[i]=-1;
  K=0;
  for(i=0; i<m; i++) {
    u=b[i].u;
    v=b[i].v;
    lb[v]+=b[i].lo;
    lb[u]-=b[i].lo;
    add(u,v,oo-b[i].lo);
  }
  for(i=1; i<=n; i++) {
    add(ts,i,oo);
    add(i,tt,oo);
  }
  for(i=0; i<n+2; i++) {
    if(lb[i]>0)add(st,i,lb[i]);
    else add(i,ed,-lb[i]);
  }
  int ans=sap();
  add(tt,ts,oo);
  printf("%d\n",sap());
}
int _,ca,i;
int main() {
  scanf("%d",&_);
  ca=0;
  while(_--) {
    ca++;
    scanf("%d%d",&n,&m);
    for(i=0; i<m; i++) {
      scanf("%d%d%d",&b[i].u,&b[i].v,&b[i].lo);
    }
    printf("Case #%d: ",ca);
    solve();
  }
}