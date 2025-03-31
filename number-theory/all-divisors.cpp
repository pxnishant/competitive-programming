#include <iostream>
#include<bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define fr(n) for(long long i=0;i<n;i++)
#define pb insert
using namespace std;

//O(root(n))
vector<int> allDiv(int n) {

    vector<int> ans;

    for (int i=1; i*i <= n; i++) {
        
        if (n%i) continue;

        ans.push_back(i);
        if (i*i != n) ans.push_back(n/i);

    }

    return ans;

}


int main() {


}