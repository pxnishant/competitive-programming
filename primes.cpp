#include <iostream>
#include<bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define int long long
#define fr(n) for(long long i=0;i<n;i++)
#define pb push_back
using namespace std;

void allFactors(vector<int> & arr, int n) {                 //O(√n)

    for (int i=2; i*i<=n;i++) {
        if (n%i==0) {
            arr.pb(i);
            if (i*i!=n) arr.pb(n/i);
        }
    }
    
}

void primeFactors(vector<int> & arr, int n) {               //O(√n)

    for (int i=2; i*i<=n;i++) {
        while (n%i==0) {
            arr.pb(i);
            n /= i;
        }
    }

    if (n>1) arr.pb(n);
    
}

//----------------------------------- precomputation algorithms -------------------------------

const int N = 1e7+10;
vector<bool> isPrime(N, 1);
vector<int> lPrime(N, 0);
vector<int> hPrime(N);                           // 24 = 2x2x2x3, lowest prime = 2, highest prime = 3
void sieve() {                                      //O(Nlog(log(N)). This is independent of base of log.
    isPrime[0] = isPrime[1] = false;                //O(Nlog(N)) if we remove the if condition

    for (int i=2;i<N;i++) {
        if (isPrime[i]) {
            lPrime[i] = hPrime[i] = i;
            for (int j=2*i;j<N;j+=i) {
                isPrime[j] = false;
                hPrime[j] = i;
                if (lPrime[j]==0) lPrime[j] = i;
            }
        }
    }
}

const int P = 1e5+10;

vector<int> divisors[P];
void sieveDivisors() {                          //O(Plog(P))
    for (int i=2;i<P;i++) {
        for (int j=i;j<P;j+=i) {
            divisors[j].push_back(i);
        }
    }
}

//----------------------------------- precomputation algorithms ----------------------------
//using above precomputation:

void sievePrimeFact(vector<int> & arr, int n) {         //In worst case, we keep dividing by 2. 
    while (n>1) {                                       //O(log2(n))
        int factor = lPrime[n];
        while (n%factor==0) {
            arr.pb(factor);
            n /= factor;
        }
    }
}




int32_t main() {
    quick;  

    sieveDivisors();
    for (auto i : divisors[36]) {
        cout << i << " ";
    }


    return 0;
}