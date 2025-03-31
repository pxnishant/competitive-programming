#include<bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define fr(n) for(long long i=0;i<n;i++)
using namespace std;

const int N = 1e7 + 10;

vector<bool> isPrime(N, 1);
vector<int> lPrime(N, -1);  //lPrime[i] = lowest/smallest prime in the prime fact of i
vector<int> hPrime(N, -1);  //highest prime

//with the if condition, runs in O(N*log(log(N)))
//without the if, runs in O(N*log(n))
void sieve() {

    isPrime[1] = 0;

    for (int i=2; i<=N; i++) {

        if (!isPrime[i]) continue;

        lPrime[i] = i; hPrime[i] = i;

        for (int j=2*i; j<=N; j+=i) {
            isPrime[j] = 0;
            if (lPrime[j] == -1) lPrime[j] = i;
            hPrime[j] = i;
        }

    }

}


int main() {

    sieve();

    for (int i=1; i<=100; i++) {
        cout << isPrime[i] << " " << lPrime[i] << " " << hPrime[i] << endl;
    }
}