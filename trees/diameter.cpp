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

/************************************ debug ************************************/

template <typename T>
void printe(const T& var) { cout << var << endl; }
template <typename T>
void printa(const vector<T>& arr) { for (const auto& elem : arr) cout << elem << " "; cout << endl; }
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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> o_set; 
 
vector<vector<int>> g;
vector<int> furthLeaf;
vector<int> parent;
int diam = 0;

void dfs(int node, int prev) {
   for (int neighbor : g[node]) {
      if (neighbor == prev) continue;
      dfs(neighbor, node);
      furthLeaf[node] = max(furthLeaf[node], furthLeaf[neighbor] + 1);
   }
}

vector<int> maxPathAsLCA;
int diameter = 0;

//O(NlogN) but can easily be made O(N)

void dfs_diam(int node, int prev) {
   vector<int> d; //stores distances of children to furthest leaf
   for (int neighbor : g[node]) {
      if (neighbor == prev) continue;
      d.push_back(furthLeaf[neighbor]);
      dfs_diam(neighbor, node);
   }

   sort(d.begin(), d.end());
   reverse(d.begin(), d.end());
   if (d.size() == 0) return;     //leaf node
   if (d.size() == 1) { diameter = max(diameter, d[0] + 1); return; }
   diameter = max(diameter, d[0] + d[1] + 2);

}

void solve() {
   int n; cin >> n; g.clear(); g.resize(n+1); 
   furthLeaf.clear(); furthLeaf.resize(n+1, 0);
   maxPathAsLCA.clear(); maxPathAsLCA.resize(n+1, 0);

   fr(n-1) {
      int u, v; cin >> u >> v;
      g[u].push_back(v); g[v].push_back(u);
   }

   dfs(1, -1);
   dfs_diam(1, -1);

   cout << diameter << endl;

   

}
        
int32_t main() { 
      quick;
      int t; t = 1;
      while (t--) {
         solve();
      }
}