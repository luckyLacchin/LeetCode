#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
/*
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums[0] == 0)
            return 0;
        return jump_rec(nums,nums.size()-1,0,0);
    }

    int jump_rec (vector<int> nums, int n,int index,int count) {
        if (index == n)
            return count;
        else {
            int minSoFar = INT_MAX;
            int temp;
            for (int j = 1; j <= nums[index];j++) {
                temp = jump_rec(nums,n,index+j,count+1);
                cout << "temp = " << temp << endl;
                minSoFar = min (temp,minSoFar);
            }
            return minSoFar;
        }
    }
};
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        // DP array to store the minimum jumps to reach each index
        vector<int> dp(n, INT_MAX);
        dp[0] = 0; // Start position requires 0 jumps

        // Fill the DP table
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (j + nums[j] >= i) { // If index `i` is reachable from index `j`
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n - 1]; // Minimum jumps to reach the last index
    }
};

//now i have to do not recursive

int main() {
    Solution solution;
    
    // Test cases
    vector<int> nums1 = {2, 3, 1, 1, 4}; // Expected output: 2
    vector<int> nums2 = {2, 3, 0, 1, 4}; // Expected output: 2
    vector<int> nums3 = {1, 2, 3};       // Expected output: 2
    vector<int> nums4 = {0};             // Expected output: 0 (already at the end)
    vector<int> nums5 = {1, 1, 1, 1};    // Expected output: 3

    // Testing and displaying results
    cout << "Test case 1: " << solution.jump(nums1) << endl;
    /*
    cout << "Test case 2: " << solution.jump(nums2) << endl;
    cout << "Test case 3: " << solution.jump(nums3) << endl;
    cout << "Test case 4: " << solution.jump(nums4) << endl;
    cout << "Test case 5: " << solution.jump(nums5) << endl;
    */

    return 0;
}
