#include <bits/stdc++.h>
using namespace std;

/*
 First Missing Positive
 Given an unsorted array, find the smallest missing positive integer.
 Time:  O(n)
 Space: O(1)

 Core idea:
 - Place each value x (1 ≤ x ≤ n) at index x-1.
 - Then scan for the first index i where a[i] != i+1.
*/

int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
        // Place nums[i] in correct position if possible
        while (nums[i] >= 1 && nums[i] <= n &&
               nums[nums[i] - 1] != nums[i]) {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }

    // Find first index where value is incorrect
    for (int i = 0; i < n; ++i) {
        if (nums[i] != i + 1)
            return i + 1;
    }

    return n + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    cout << firstMissingPositive(nums) << '\n';
    return 0;
}
