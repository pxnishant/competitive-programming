#include<bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define fr(n) for(long long i=0;i<n;i++)
#define pb push_back
#define int long long
using namespace std;

//find a non-empty subarray with the largest sum (print sum only)

void bruteForce() {         //O(n^2)

    vector<int> arr = {-4,-1,-2,-7,-3,-4};
    int maxi = INT_MIN;
    int n = arr.size();
    for (int i=0;i<n;i++) {
        int curr = 0;
        for (int j=i;j<n;j++) {
            curr += arr[j];
            maxi = max(maxi, curr);
        }
    }

    cout << maxi << endl;;
}

void kadanesAlgorithm() {           //O(n)
 
    vector<int> arr = {-4,-1,-2,-7,-3,-4};
    int n = arr.size();
    int prevSum = 0;
    int maxi = INT_MIN;

    for (int i=0;i<n;i++) {

        if (prevSum>=0) {
            prevSum += arr[i];
        }

        else
            prevSum = arr[i];

        maxi = max(maxi, prevSum);
    }

    cout << maxi << endl;
}

//print the starting and ending index of the subarray w the largest sum
//variable sized
void slidingWindow() {

    vector<int> arr = {-4,-1,-2,-7,-3,-4};
    int n = arr.size();

    int prevSum = 0;
    int maxi = INT_MIN;
    int maxl, maxr;
    int l = 0;

    for (int r=0;r<n;r++) {
        if (prevSum<=0) {
            l = r;
            prevSum = arr[r];
        }
        else {
            prevSum += arr[r];
        }

        if (prevSum >= maxi) {
            maxi = prevSum;
            maxl =  l;
            maxr = r;
        }

    }

    cout << maxl << " " << maxr << endl;

}



int32_t main() {
    quick;
    bruteForce();
    kadanesAlgorithm();
    slidingWindow();

}
