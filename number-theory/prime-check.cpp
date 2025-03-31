#include <iostream>
#include<bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define fr(n) for(long long i=0;i<n;i++)
#define pb insert
using namespace std;

//O(root(n))
bool primeCheck(int n) {

    if (n < 2) return false;

    for (int i=2; i*i <= n; i++) {

        if (n % i == 0) return false;

    }

    return true;

}

//O(0.5 * root(n))
bool isPrime( int n ) {
    if ( n == 1 ) return false; // by definition, 1 is not prime number
    if ( n == 2 ) return true; // the only one even prime
    if ( n%2 == 0 ) return false; // check if is even
    for ( int i = 3; i * i <= n; i += 2 ) // for each odd number
        if ( n%i == 0 ) return false;
    return true;
}


int main() {


}