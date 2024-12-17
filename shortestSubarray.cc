#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
/*
class Solution
{
public:
    int minimumSubarrayLength(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n == 0)
            return -1;
        else if (n == 1)
            return nums[0] > k ? 1 : -1;

        vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(n + 1, {0, INT_MAX}));

        int minLength = INT_MAX;

        for (int i = 1; i <= n; i++)
        {
            dp[i][i].first = nums[i - 1];
            if (dp[i][i].first >= k)
            {
                dp[i][i].second = 1; // The length of a single element subarray
                minLength = min(minLength, dp[i][i].second);
            }

            for (int j = i + 1; j <= n; j++)
            {
                dp[i][j].first = dp[i][j - 1].first | nums[j - 1];
                if (dp[i][j].first >= k)
                {
                    dp[i][j].second = min(j - i + 1, dp[i][j - 1].second);
                    minLength = min(minLength, dp[i][j].second);
                }
            }
        }

        return minLength == INT_MAX ? -1 : minLength;
    }
};

It wants the solution O(n) not O(n^2)..think about it
*/

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> count(32, 0);
        int start = 0, end = 0, minLength = INT_MAX;

        while (end < nums.size()) {
            updateBits(count, nums[end], 1);
            while (start <= end && getVal(count) >= k) {
                minLength = min(minLength, end - start + 1);
                updateBits(count, nums[start], -1);
                start++;
            }
            end++;
        }

        return minLength == INT_MAX ? -1 : minLength;
    }

private:
    void updateBits(vector<int>& count, int num, int val) {
        for (int i = 0; i < 32; i++) {
            if ((num >> i) & 1) {
                count[i] += val;
            }
        }
    }

    int getVal(const vector<int>& count) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            if (count[i] > 0) {
                ans |= (1 << i);
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 3};
    int k = 2;
    cout << solution.minimumSubarrayLength(nums, k) << endl;

    return 0;
}