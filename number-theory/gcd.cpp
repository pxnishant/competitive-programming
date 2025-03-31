#include <iostream>
#include<bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define fr(n) for(long long i=0;i<n;i++)
#define pb insert
using namespace std;


//euclid's algo, works in O(log2(max(a, b)))

int gcd(int sm, int lg) {

    if (sm == 0) return lg;

    return gcd(lg%sm, sm);

}

int main() {


}