#include <vector>
#include <cmath>
#include <iostream>


using namespace std;

class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        //devo invertire tutte le direzioni mi sa...
        vector<vector<int>> dp = grid;
        int n = grid[0].size();
        int m = grid.size();
        int firstMove;
        int secondMove;
        int thirdMove;            
        for (int j = 1; j < n; j++) {
            for (int i = 0; i < m; i++) {
                if (i+1 >= m || j-1 < 0 || grid[i+1][j-1] > grid[i][j])
                    firstMove = 0;
                else
                    firstMove = dp[i+1][j-1] + grid[i][j];
                if (j-1 < 0 || grid[i][j-1] > grid[i][j])
                    secondMove = 0;
                else
                    secondMove = dp[i][j-1] + grid[i][j];
                if (i - 1 < 0 || j - 1 < 0 || grid[i-1][j-1] > grid[i][j])
                    thirdMove = 0;
                else
                    thirdMove = dp[i-1][j-1] + grid[i][j];
                int firstComparison = max (firstMove,secondMove);
                dp[i][j] = max (firstComparison,thirdMove);
                cout << "d[i][j] = " << dp[i][j] << endl;
            }        
        }
        int res = INT_MIN;
        int lastColumn = n-1;
        for (int i = 0; i < m; i++) {
            res = max(dp[i][lastColumn],res);
            cout << "col: " << dp[i][lastColumn] << endl;
        }
        return res;
    }

    int maxMoves(vector<vector<int>>& grid) {
        //devo invertire tutte le direzioni mi sa...
        vector<vector<int>> dp;
        int n = grid[0].size();
        int m = grid.size();
        dp.resize(m);
        for (int i = 0; i < m; i++) {
            dp[i].resize(n);
        }
        int firstMove;
        int secondMove;
        int thirdMove;            
        for (int j = 1; j < n; j++) {
            for (int i = 0; i < m; i++) {
                if (i+1 >= m || j-1 < 0 || grid[i+1][j-1] >= grid[i][j] || (dp[i+1][j-1] == 0 && j > 1))
                    firstMove = 0;
                else
                    firstMove = dp[i+1][j-1] + 1;
                if (j-1 < 0 || grid[i][j-1] >= grid[i][j] || (dp[i][j-1] == 0 && j > 1))
                    secondMove = 0;
                else
                    secondMove = dp[i][j-1] + 1;
                if (i - 1 < 0 || j - 1 < 0 || grid[i-1][j-1] >= grid[i][j] || (dp[i-1][j-1] == 0 && j > 1))
                    thirdMove = 0;
                else
                    thirdMove = dp[i-1][j-1] + 1;
                int firstComparison = max (firstMove,secondMove);
                dp[i][j] = max (firstComparison,thirdMove);
                cout << "d[i][j] = " << dp[i][j] << endl;
            }        
        }
        int res = INT_MIN;
        int lastColumn = n-1;
        for (int i = 0; i < m; i++) {
            res = max(dp[i][lastColumn],res);
            cout << "col: " << dp[i][lastColumn] << endl;
        }
        return res;
    }

};

int main() {
    // Initialize the grid
    /*vector<vector<int>> grid = {
        {2, 4, 3, 5},
        {5, 4, 9, 3},
        {3, 4, 2, 11},
        {10, 9, 13, 15}
    };
    */
    vector<vector<int>> grid = {
        {187,167,209,251,152,236,263,128,135},
        {267,249,251,285,73,204,70,207,74},
        {189,159,235,66,84,89,153,111,189},
        {120,81,210,7,2,231,92,128,218},
        {193,131,244,293,284,175,226,205,245},
    };

    // Create an instance of Solution
    Solution solution;

    // Call the maxMoves function and store the result
    //int result = solution.maxMoves(grid);
    int result2 = solution.maxMoves(grid);

    // Output the result
    cout << "Maximum moves: " << result2 << endl;

    return 0;
}

//this is correct indeed, now i should do the maxMoves