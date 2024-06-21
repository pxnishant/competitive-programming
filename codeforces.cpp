#include<bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define fr(n) for(long long i=0;i<n;i++)
#define pb push_back
#define int long long
using namespace std;
 
 
void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    fr(n) cin >> arr[i];

    int mini = INT_MAX;

    for (int i=0;i<n-1;i++) {
        int maxi = max(arr[i], arr[i+1]);
        mini = min(mini, maxi);
    }  

    cout << mini - 1 << endl;
   
}
 
int32_t main() {
    quick;
    int t; cin >> t;
    while (t--) {
        solve();
    }
 
 
}