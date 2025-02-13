#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define quick ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define fr(n) for(int i=0;i<n;i++)
#define ff first
#define ss second
#define endl '\n'
#define pb push_back
using ll = long long;
using namespace std;
using namespace __gnu_pbds;
const int MOD = 998244353;
#define int long long
const int M = 1e9 + 7;

/************************************ debug ************************************/

template <typename T>
void printe(const T& var) { cout << var << endl; }
template <typename T>
void printa(const vector<T>& arr) { for (const auto& elem : arr) cout << elem << " "; cout << endl; }
template <typename T>
void printa1(const vector<T>& arr) { int i = 0; for (const auto& elem : arr) { i++; if (i==1) continue; cout << elem << " "; } cout << endl; }
template <typename T>
void print2d(const vector<vector<T>>& mat) { for (const auto& row : mat) { for (const auto& elem : row) cout << elem << " "; cout << endl; } cout << endl; }

/************************************ functions ************************************/

ll _pow(ll a, ll b, ll m) { ll res = 1; while (b > 0) {if (b & 1) res = (res * a) % m; a = (a * a) % m; b = b >> 1;} return res; }
ll _ceil(ll a, ll b) { return (a+b-1)/b; }
ll fact(ll n, ll m) { ll res = 1; for (int i=2; i<=n; i++) {res = (res * i)%m;} return res; }
//understand comb later
ll comb(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
int set_bit_count(ll n) { return __builtin_popcountll(n); }

/************************************ data structures ************************************/

// find_by_order, order_of_key
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> o_set;

int LOG = 20;
int up[200010][20];
int depth[200010];
vector<vector<int>> g;
vector<int> parent;

//populates up (binary lifting)
void dfs(int node, int prev) {
   for (int neigh : g[node]) {
      if (neigh == prev) continue;

      up[neigh][0] = parent[neigh];
      for (int h=1; h<LOG; h++) {
         up[neigh][h] = up[up[neigh][h-1]][h-1];
      }

      depth[neigh] = depth[node] + 1;
      dfs(neigh, node);
   }
}

int find_lca(int a, int b) {

   if (depth[b] > depth[a]) swap(a, b);

   int k = depth[a] - depth[b];
   for (int i=0; i<LOG; i++) {
      int bit = (k >> i) & 1;
      if (bit) a = up[a][i];
   }

   if (a == b) return a;

   for (int i=LOG-1; i>=0; i--) {
      if (up[a][i] != up[b][i]) {
         a = up[a][i];
         b = up[b][i];
      }
   }

   return up[a][0];
}

void solve() {
   int n, q; cin >> n >> q; g.resize(n+1);
   parent = vector<int>(n+1, 1);
   for (int i=2; i<=n; i++) { 
      cin >> parent[i];
      g[parent[i]].push_back(i);
      g[i].push_back(parent[i]);
   }
   parent[1] = 1; up[1][0] = 1;

   dfs(1, -1);

   while (q--) {
      int a, b; cin >> a >> b;
      cout << find_lca(a, b) << endl;
   }



}




        
int32_t main() { 
      quick; int t; t = 1;
      while (t--) {
         solve();
      }
}