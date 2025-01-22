#include<bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define fr(n) for(long long i=0;i<n;i++)
#define f first
#define s second
using namespace std;
    
vector<vector<int>> g;
vector<int> indegree;

void solve() {

  int n, m; cin >> n >> m; g.resize(n+1); indegree.resize(n+1, 0);

  for (int i=0; i<m; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v); indegree[v]++;
  }

  queue<int> q; vector<int> ans;

  for (int i=1; i<=n; i++) {
    if (!indegree[i]) q.push(i);
  }

  while (!q.empty()) {
    int t = q.front(); q.pop();
    ans.push_back(t);

    for (int i : g[t]) {
      indegree[i]--;
      if (!indegree[i]) q.push(i);
    }
  }

  if (ans.size()==n) {

    for (int i : ans) cout << i << " ";

  }

  else {
    cout << "IMPOSSIBLE" << endl;
  }
  

 
}
    
int main() {
    quick;
    solve();
}