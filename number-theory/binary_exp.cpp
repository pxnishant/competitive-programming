#include<bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define fr(n) for(long long i=0;i<n;i++)
using namespace std;

const int M = 1e9 + 7;

//f(a, n) = f(a, n/2) * f(a, n/2) if n = even
//f(a, n) = a * f(a, n/2) * f(a, n/2) if n = odd

//O(logn)
int binpow(int a, int n, int m) {

    if (n == 0) return 1;

    int res = binpow(a, n/2, m);

    if (n & 1) return (a * ((res * 1LL * res) % m) ) % m;

    return (res * 1LL * res)%m;

}

//O(logn)
int binpowit(int a, int n, int m) {

    int res = 1;
    while (n > 0) {
        if (n & 1) {
            res = (res * 1LL * a)%m;
        }
        n >>= 1;
        a = (a * 1LL * a)%m;
    }
    return res;
}


int main() {

    cout << binpow(2123123, 1231231, M) << endl;
    cout << binpowit(2123123, 1231231, M) << endl;
}