#include<bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define fr(n) for(long long i=0;i<n;i++)
#define f first
#define s second
using namespace std;
    
vector<vector<int>> g;
vector<bool> vis;
vector<int> parent;
 
int start = -1; int endd = -1;
 
void path(int start, int endd) {
 
  vector<int> ans;
 
  ans.push_back(start);
 
  for (int i=endd; i!=start; i=parent[i]) {
    ans.push_back(i);
  }
 
  ans.push_back(start);
   
  reverse(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (int i : ans) cout << i << " ";
  cout << endl;
  
}
 
void dfs(int node, int prev) {
 
  for (int child : g[node]) {
 
    if (vis[child] && child != prev) {
 
      if (start==-1) {
 
        start = child;
        endd = node;
        return;
      }
 
    }
 
    else if (vis[child]) continue;
 
    else {
      vis[child] = 1;
      parent[child] = node;
      dfs(child, node);
    }
 
  }
 
 
} 
void solve() {
 
  int n, m; cin >> n >> m; g.resize(n+1);
  vis.resize(n+1, 0); parent.resize(n+1, -1);
 
  for (int i=0; i<m; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
 
  for (int i=1; i<=n; i++) {
 
    if (!vis[i]) {
      vis[i] = 1; dfs(i, -1);
 
      if (start != -1) {
 
        path(start, endd); return;
 
      }
 
    }
 
  }
 
  cout << "IMPOSSIBLE" << endl;
 
}
 
int main() {
    quick;
    solve();
}