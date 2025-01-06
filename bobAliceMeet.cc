#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    vector<int> leftmostBuildingQueries(vector<int> &heights, vector<vector<int>> &queries)
    {
        int n = heights.size();
        vector<vector<int>> adjList(n);
        vector<int> ans;
        cout << "n: " << n << endl;
        for (int i = 0; i < n; i++)
        {
            adjList[i].push_back(i);
            for (int j = i + 1; j < n; j++)
            {

                if (heights[j] > heights[i])
                {
                    adjList[i].push_back(j);
                }
            }
            cout << i << ": ";
            printVector(adjList[i]);
        }
        int a, b;
        bool found = false;
        for (vector<int> query : queries)
        {
            a = query[0];
            b = query[1];
            for (int i = 0; i < adjList[a].size(); i++)
            {
                for (int j = 0; j < adjList[b].size(); j++)
                {
                    if (adjList[a][i] == adjList[b][j])
                    {
                        cout << "value: " << adjList[a][i] << endl;
                        ans.push_back(adjList[a][i]);
                        found = true;
                        break;
                    }
                }
                if (found)
                {
                    break;
                }   
            }
            if (!found) {
                ans.push_back(-1);
            }
            else {
                found = false;
            }
        }
        printVector(ans);
        return ans;
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
    vector<int> heights = {6, 4, 8, 5, 2, 7};
    vector<vector<int>> queries = {{0, 1}, {0, 3}, {2, 4}, {3, 4}, {2, 2}};
    Solution sol;
    sol.leftmostBuildingQueries(heights, queries);
    // printVector(prices);

    return 0;
}