#include <iostream>
#include<bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define int long long
#define fr(n) for(long long i=0;i<n;i++)
#define pb insert
using namespace std;


int gcd(int a, int b) {                     //Euclid's Algorithm, works even for a < b
   if (b==0) return a;                      //O(log2(a)) - Worst case, if b = 2
   return gcd(b, a%b);
    
}
   
int binaryExpRec(int a, int b, int M) {                      //O(log2(b))
   if (b==0) return 1;
   int res = binaryExpRec(a, b/2);
   if (b&1) {
      return (a * (res * res) % M) % M;
   }               
   else {
      return (res * res) % M;
   }
}

//iterative is quicker

int binaryExp(int a, int b, int M) {         //in log2(b) time
    int res = 1;                             //What if a > 10^9?
    while (b > 0) {                          //Add a %= M in the beginning.
        if (b&1) {                           //(a^b)%M = (a%M)^b
            res = (res*1LL*a)%M;
        }
        b = b >> 1;
        a = (a * 1LL * a)%M;
    }
    return res;
}





int32_t main() {
    cout << binaryExpRec(3,4) << endl;
}