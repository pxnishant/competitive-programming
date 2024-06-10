#include <iostream>
#include<bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define int long long
#define fr(n) for(long long i=0;i<n;i++)
#define pb push_back
using namespace std;

const int MOD = 1e9+7;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    fr(n) cin >> arr[i];
    vector<int> suffix(n);
    suffix[n-1] = arr[n-1];
    for (int i = n-2; i>=0; i--) {
        suffix[i] = suffix[i+1] + arr[i];
    }

    int c = 0;

    for (int i=0; i<n;i++) {
        c += arr[i];
        if (i + 1 < n && suffix[i+1] > 0) {
            c = abs(c);
        }
    }

    cout << abs(c) << endl;



}

int32_t main() {
    quick;
    int t; cin >> t;
    while (t--) {
       solve();
    }

}