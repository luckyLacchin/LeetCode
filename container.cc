#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        // This one is really interesting i'm pretty sure u do it with DP, in reality it is not DP
        int n = height.size();
        vector<vector<int>> DP(n, vector<int>(n, 0));
        int maxValue = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                DP[i][j] = min(height[i], height[j]) * (j - i);
                maxValue = max(maxValue, DP[i][j]);
                cout << "DP: " << DP[i][j] << ", i: " << i << ", j:" << j << endl;
            }
        }
        return maxValue;
    }
    void printVector(vector<int> vec)
    {

        for (int x : vec)
        {
            cout << x << " ";
        }
        cout << endl;
    }
};

int main()
{

    vector<int> height = {1,1};
    Solution sol;
    cout << "sol: " << sol.maxArea(height) << endl;
    // printVector(prices);

    return 0;
}