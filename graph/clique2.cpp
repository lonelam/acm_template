typedef unsigned long long U;
typedef long long ll;
const int N=45;
//0为有边，1为无边
int n,K,x,i,j,ans;bool flag;U g[N];double res;
inline int ctz(U s){return s?__builtin_ctzll(s):64;}
void BornKerbosch(U cur,U allow,U forbid){
  if(!allow&&!forbid){
    ans=max(ans,__builtin_popcountll(cur));
    return;
  }
  if(!allow)return;
  int pivot=ctz(allow|forbid);
  U z=allow&~g[pivot];
  for(int u=ctz(z);u<n;u+=ctz(z>>(u+1))+1){
    BornKerbosch(cur|(1ULL<<u),allow&g[u],forbid&g[u]);
    allow^=1ULL<<u,forbid|=1ULL<<u;
  }
}
int main(){
  scanf("%d",&n);
  for(i=0;i<n;i++)g[i]=(1ULL<<n)-1-(1ULL<<i);
  for(i=0;i<n;i++)for(j=0;j<n;j++){
    scanf("%d",&x);
//0为有边，1为无边
    if(!x&&i!=j)g[i]^=1ULL<<j;
  }
  BornKerbosch(0,(1ULL<<n)-1,0);
  //ans为最大团大小
  printf("%d",ans);
}
