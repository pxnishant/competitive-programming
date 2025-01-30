//Leetcode question: Find a local maximum. By definition, an index i such that v[i] > v[i+1] (if i+1 < n)
//and v[i] > v[i-1], if exists.

#include <bits/stdc++.h>
using namespace std;


int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;

        while (l <= r) {

            int m = l + (r-l)/2;

            if ((m-1 < 0 || nums[m] > nums[m-1]) && (m+1 >= n || nums[m] > nums[m+1])) {
                return m;
            }

            else if (m+1 < n && nums[m+1] > nums[m]) {
                l = m + 1;
            }

            else r = m - 1;

        }

        return -1;
}

int main() {

    return 0;
}