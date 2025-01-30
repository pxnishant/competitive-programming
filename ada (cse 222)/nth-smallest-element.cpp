/*
Finding n-th smallest element of two sorted arrays Suppose you are given two sorted arrays
A and B, each of size n. Design an O(log n) algorithm to find the n-th smallest element of
the union of A and B.
*/

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

int nthSmallest(vector<int> a, vector<int> b, int l1, int r1, int l2, int r2) {

    if (l1 == r1 && l2 == r2) {
        if (a[l1] < b[l1]) return a[l1];
        else b[l1];
    }

    int m1 = l1 + (r1-l1)/2;
    int m2 = l2 + (r2-l2)/2;

    if (a[m1] < b[m2]) {
        l2 = m2 + 1;
        r1 = m1;
    }
    else {
        l1 = m1 + 1;
        r2 = m2;
    }

    return nthSmallest(a, b, l1, r1, l2, r2);


}

void solve() {
   
    int n; cin >> n;
    vector<int> a(n); fr(n) cin >> a[i];
    vector<int> b(n); fr(n) cin >> b[i];

    int ans = nthSmallest(a, b, 0, n-1, 0, n-1);

    cout << ans << endl;




}

        
int32_t main() { 
      quick;
      int t; t = 1;
      while (t--) {
         solve();
      }
}