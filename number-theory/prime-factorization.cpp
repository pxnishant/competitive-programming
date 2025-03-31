#include <iostream>
#include<bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define fr(n) for(long long i=0;i<n;i++)
#define pb insert
using namespace std;

//O(root(n))
vector<int> primeFact(int n) {

    vector<int> ans;

    for (int i=2; i*i <= n; i++) {  //i*i = n handles when n is square of a prime

        while (n % i == 0) {
            ans.push_back(i);
            n /= i;
        }

    }

    if (n > 1) ans.push_back(n);    //handles n = prime

    return ans;

}


int main() {


}