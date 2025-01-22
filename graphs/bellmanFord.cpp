#include <iostream>
#include<bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
 
#define int long long
#define endl "\n"
#define fr(n) for(long long i=0;i<n;i++)
#define pb push_back
#define f first
#define s second

vector<vector<int>> edges;  //edge list, i.e. list of {u, v, w}
vector<int> dist;

// void path(int node) {
 
//   vector<int> ans;
 
//   ans.push_back(node);
 
//   for (int i=parent[node]; i!=node; i=parent[i]) {
//     ans.push_back(i);
//   }
 
//   ans.push_back(node);
 
//   reverse(ans.begin(), ans.end());
 
//   cout << "YES" << endl;
//   for (int i : ans) cout << i << " ";
//   cout << endl;
 
// }

void bellmanFord(int n) {

  for (int i=1; i<=n-1; i++) {
    
    for (auto e : edges) {
      int u, v, w; u = e[0], v = e[1], w = e[2];

      if (dist[u] != LLONG_MAX)
      dist[v] = min(dist[v], dist[u] + w);
 
    }

  }

}