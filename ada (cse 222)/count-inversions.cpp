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

int countSplitAndMerge(vector<int> & v, int l, int m, int r) {
   vector<int> temp; int inversions = 0;
   int i = l, j = m+1;

   while (i <= m && j <= r) {

      if (v[i] <= v[j]) {
         temp.push_back(v[i]); i++;
      }
      else {
         temp.push_back(v[j]); j++;
         inversions += m - i + 1;
      }
   }

   while (i<=m) { temp.push_back(v[i]); i++; }
   while (j<=r) { temp.push_back(v[j]); j++; }

   for (int i=l; i<=r; i++) {
      v[i] = temp[i-l];
   }

   return inversions;
}

int countAndSort(vector<int> & v, int l, int r) {

    int m = l + (r-l)/2;

    if (r == l) return 0;

    int x1 = countAndSort(v, l, m);
    int x2 = countAndSort(v, m+1, r);
    int x3 = countSplitAndMerge(v, l, m, r);

    return x1 + x2 + x3;

}

void solve() {
   
   int n; cin >> n;
   vector<int> v(n); fr(n) cin >> v[i];
   int ans = countAndSort(v, 0, n-1);
   cout << ans << endl;
}

        
int32_t main() { 
      quick;
      int t; t = 1;
      while (t--) {
         solve();
      }
}