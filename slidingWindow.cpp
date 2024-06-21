#include<bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define fr(n) for(long long i=0;i<n;i++)
#define pb push_back
#define int long long
using namespace std;
 
//do elements repeat within a 'k' sized window?

/*

return true if an array consists of two equal elements 
which are not furhter than 'k' distance   
=> return (arr[i] == arr[j] && abs(i-j) < k)

*/


//brute-force

void bruteForce(vector<int> arr, int k) {       //O(n*k)


    if (k==1) {
        cout << "YES" << endl; return;
    }


    int n = arr.size();

    for (int i=0;i<n;i++) {
        for (int j=i+1;abs(i-j)<k && j < n;j++) {

            if (arr[i]==arr[j])
                {
                    cout << "YES" << endl;
                    return;
                }

        }
    }

    cout << "NO" << endl;


}


//fixed-size sliding window

void slidingWindow(vector<int> arr, int k) {

    if (k==1) {
        cout << "YES" << endl; return;
    }

    int n = arr.size();

    unordered_set<int> s;
    int l = 0;

    for (int i=0;i<n;i++) {


        if (s.size() >= k) {
            
            s.erase(arr[l]);
            l++;
        }

        if (s.count(arr[i])) {
            cout << "YES" << endl;
            return;
        }

        s.insert(arr[i]);



    }

    cout << "NO" << endl;



}

 
int32_t main() {
    quick;
    vector<int> arr = {1,1,9,5,2,4};
    bruteForce(arr, 2);
    slidingWindow(arr, 2);

 
}