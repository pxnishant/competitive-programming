#include<bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define fr(n) for(long long i=0;i<n;i++)
using namespace std;

const int N = 1e5 + 10;

vector<vector<int>> divisors(N);    //stores each divisor (once)
vector<vector<int>> primeFactors(N);    //stores each prime factor (once)
vector<bool> isPrime(N, 1);
vector<int> lPrime(N, -1);  //lPrime[i] = lowest/smallest prime in the prime fact of i
vector<int> hPrime(N, -1);  //highest prime

//O(N*log(log(N)))
void sievePrimeFactors() {

    for (int i=2; i<=N; i++) {

        if (!isPrime[i]) continue;

        primeFactors[i].push_back(i);
        lPrime[i] = i; hPrime[i] = i;

        for (int j=2*i; j<=N; j+=i) {
            primeFactors[j].push_back(i);
            isPrime[j] = 0;
            if (lPrime[j] == -1) lPrime[j] = i;
            hPrime[j] = i;
        }
    }
}

//O(N*log(n))
void sieveDivisors() {

    for (int i=1; i<=N; i++) {
        for (int j=i; j<=N; j+=i) {
            divisors[j].push_back(i);
        }
    }
}


//after O(nlog(logn)) preprocessing, i.e. finding hprime or lprime
//find prime factorization with count of each factor in O(logn)

vector<int> primeFact(int n) {
    vector<int> ans;
    
    while (n > 1) {
        int prime = hPrime[n];
        while (n % prime == 0) {
            ans.push_back(prime);
            n /= prime;
        }
    }

    return ans;

}


int main() {

    sievePrimeFactors();
    // sieveDivisors();

    vector<int> v = primeFact(12);

    for (int i : v) cout << i << " ";

}