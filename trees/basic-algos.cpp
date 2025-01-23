#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define quick ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define fr(n) for(int i=0;i<n;i++)
#define f first
#define s second
#define endl '\n'
#define pb push_back
using ll = long long;
using namespace std;
using namespace __gnu_pbds;
const int MOD = 998244353;
#define int long long
const int N = 1e9;
#define int long long


/************ level of each node (distance from root) ***********/


//method 1

// void dfs(int node, int parent, int lev) {
//    level[node] = lev;

//    for (int i : g[node]) {
//       if (i==parent) continue;
//       dfs(i, node, lev+1);
//    }
// }

//method 2

// void dfs(int node, int parent) {

//    for (int i : g[node]) {
//       if (i==parent) continue;
//       level[i] = level[node] + 1;
//       dfs(i, node);
//    }
// }

/************ parent of each node ***********/

// void dfs(int node, int prev) {

//    for (int child : g[node]) {
//       if (child == prev) continue;
//       parent[child] = node;
//       dfs(child, node);
//    }
// }

/************ size of each subtree ***********/

// void dfs(int node, int prev) {
//    for (int child : g[node]) {
//       if (child == prev) continue;
//       dfs(child, node);
//       stsize[node] += stsize[child];
//    }
// }


/*********** furthest leaf node from each node (height) ***********/

// void dfs(int node, int prev) {
//    for (int child : g[node]) {
//       if (child == prev) continue;
//       dfs(child, node);
//       height[node] = max(height[node], height[child] + 1);
//    }
// }