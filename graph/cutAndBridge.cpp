vector<int> G[maxn];
int dfn[maxn], low[maxn], dfs_clock;
//割点答案
bool iscut[maxn];
//桥答案
vector<pair<int,int> > bridge;
void init()
{
  dfs_clock = 1;
  memset(dfn, 0,sizeof(dfn));
  for (int i = 1; i <= n; i++)
  {
    G[i].clear();
  }
  memset(iscut,0,sizeof(iscut));
  bridge.clear();
}
void addedge(int u, int v)
{
  G[u].push_back(v);
  G[v].push_back(u);
}
void dfs(int u, int fa)
{
  low[u] = dfn[u] = dfs_clock++;
  int cnt = 0;
  for (int v: G[u])
  {
    if (v != fa)
    {
      if (!dfn[v])
      {
        dfs(v, u);
        cnt++;
        low[u] = min(low[u], low[v]);
        //判断割点 u?=1用于判断树根
        if (u == 1 && cnt > 1) iscut[u] = true;
        if (u != 1 && low[v] >= dfn[u]) iscut[u] = true;
        //判断桥
        if (low[v] > dfn[u]) bridge.push_back({u, v});
      }
      else
      {
        low[u] = min(low[u], dfn[v]);
      }
    }
  }
  if (cnt <= 1 && u == 1) iscut[u] = false;
}
