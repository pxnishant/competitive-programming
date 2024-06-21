#include<bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define fr(n) for(long long i=0;i<n;i++)
#define pb push_back
#define int long long
using namespace std;
 
//find the length of the longest subarray with every element equal

void slidingWindow(vector<int> arr) {

    int l = 0;
    int maxi = 1;
    for (int r=0;r<arr.size();r++) {
        if (arr[r] == arr[l]) {
            maxi = max(maxi, r - l + 1);
        }

        else {

            l = r;
        }

    }

    cout << maxi;

}


/*

length of smallest subarray where sum is
greater than or equal to the target

*/

void smSubArray(vector<int> arr, int target) {          //O(n)
    int n = arr.size();
    
    int l = 0, sum = 0;
    int mini = INT_MAX;

    for (int r=0;r<n;r++) {

        sum += arr[r];

        while (sum>=target) {
            mini = min(mini, r-l+1);
            sum -= arr[l];
            l++;
        }

    }

    if (mini==INT_MAX) 
        cout << "NO SUCH LENGTH" << endl;
    

    else
        cout << mini << endl;

}

 
int32_t main() {
    quick;
    vector<int> arr = {2,2,2,2,1,3};
    smSubArray(arr, 7);
 
 
}