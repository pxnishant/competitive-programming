#include <iostream>
#include<bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define int long long
#define fr(n) for(long long i=0;i<n;i++)
#define pb push_back
using namespace std;

const int MOD = 1e9+7;
const int N = 1e5+10;

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
    int digits = floor(log10(n)) + 1;
    int maxn = 0, minn = 0;
    int temp = 1;
    for (int i=0; i<digits; i++) {
        minn += temp;
        temp = temp * 10;
    }
    minn--;
    maxn = 2*(temp)/10 - 2;

    if (n <= maxn && n >= minn) {

        if (((n-minn)%10)==9) {
            cout << "NO" << endl; return;
        }
        
    } 

    else {
        cout << "NO" << endl; return;
    }

    int c = n;

    int tzeroes = 0;
    int nt = 0;

    bool tflag = 1;

    while (n>0) {
        if (n%10==0) {
            if (tflag) tzeroes++;
        }
        else {
            tflag = 0;
        }
        n = n/10;
    }

    bool flag1 = 0;

    while (c>0) {
        if (c%10==0) {
            if (flag1) nt++;
        }
        else {
            flag1 = 1;
        }
        c = c/10;
    }

    if (tzeroes>1) {
        cout << "NO" << endl; return;
    }

    if (nt>=1) {
        cout << "NO" << endl; return;
    }

    cout << "YES" << endl;

}


int32_t main() {
    quick;
    int t; cin >> t;
    while (t--) {
        solve();
    }
}