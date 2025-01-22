#include<bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define fr(n) for(long long i=0;i<n;i++)
#define f first
#define s second
using namespace std;
    
typedef long long ll;
vector<vector<pair<int, int>>> g;
vector<ll> dist;
vector<bool> proc;
vector<int> parent;

void dijkstra(int s, int n) {

  dist.resize(n+1, LLONG_MAX);
  proc.resize(n+1); parent.resize(n+1);

  dist[s] = 0;

  priority_queue<pair<int, int>> pq;
  pq.push({0, s}); parent[1] = -1;

  while (!pq.empty()) {

    int t = pq.top().s; pq.pop();
    if (proc[t]) continue;
    proc[t] = 1;

    for (auto child : g[t]) {
      int c = child.f; int w = child.s;

      if (dist[t] + w < dist[c]) {

        dist[c] = dist[t] + w;
        parent[c] = t;

        pq.push({-dist[c], c});

      }

    }

  }

}

void solve() {

  int n, m; cin >> n >> m;
  g.resize(n+1);

  fr(m) {
    int u, v, w; cin >> u >> v >> w;
    g[u].push_back({v, w});
  }


  dijkstra(1, n);
 
}
    
int main() {
    quick;
    solve();
}