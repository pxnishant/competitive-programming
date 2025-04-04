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
const int N = 1e9;
#define int long long

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

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
string d = "DURL";

void merge(vector<int> & v, int l, int m, int r) {
   vector<int> temp(r-l+1);
   int i = l, j = m+1;
   for (int k=l; k<=r; k++) {
      if (i <= m && (j>r || v[i] < v[j])) {
         temp[k - l] = v[i]; i++;
      }
      else {
         temp[k - l] = v[j]; j++;
      }
   }

   for (int k=l; k<=r; k++) {
      v[k] = temp[k - l];
   }

}

void mergesort(vector<int> & v, int l, int r) {
   int m = l + (r - l) / 2;
   if (l == r) return;

   mergesort(v, l, m);
   mergesort(v, m+1, r);
   merge(v, l, m, r);

}

void solve() {
   
   int n; cin >> n;
   vector<int> v(n); fr(n) cin >> v[i];

   mergesort(v, 0, n-1);
   printa(v);
 

}

        
int32_t main() { 
      quick;
      int t; t = 1;
      while (t--) {
         solve();
      }
}