#include<bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define fr(n) for(long long i=0;i<n;i++)
#define f first
#define s second
using namespace std;
    
typedef long long ll;
 
vector<vector<ll>> dist;
 
void floydWarshall() {
  int n, m, q; cin >> n >> m >> q;
  
  dist.resize(n+1, vector<ll>(n+1, LLONG_MAX));
 
  for (int i=1; i<=n; i++) {
    dist[i][i] = 0;
  }
 
  for (int i=0; i<m; i++) {
    int u, v, w; cin >> u >> v >> w;
    dist[u][v] = min(w*1LL, dist[u][v]); 
    dist[v][u] = min(w*1LL, dist[v][u]);
 
  }
 
  for (int k = 1; k<=n; k++) {
    for (int i = 1; i<=n; i++) {
      for (int j=1; j<=n; j++) {
 
        if (dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
 
      }
    }
  }
 
  while (q--) {

    int u, v; cin >> u >> v;
    if (dist[u][v]==LLONG_MAX)
      cout << -1 << endl;
    else
      cout << dist[u][v] << endl;
 
  }
 
}
    
int main() {
    quick;
    floydWarshall();
}