#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {

        vector<int> res;
        int actualValue = INT_MAX;
        for (int i = 0; i < prices.size(); i++)
        {
            int j = i+1;
            for (; j < prices.size(); j++)
            {
                if (prices[i] >= prices[j])
                {
                    res.push_back(prices[i] - prices[j]);
                    break;
                }
            }
            if (j == prices.size())
                res.push_back(prices[i]);
        }
        
        printVector(res);
        return res;
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

    vector<int> prices = {8, 4, 6, 2, 3};
    Solution sol;
    sol.finalPrices(prices);
    // printVector(prices);

    return 0;
}


/*
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> answer;

        for (auto it = prices.begin(); it != prices.end(); it++) {
            auto itt = it + 1;
            for (; itt != prices.end(); itt++) {
                if (*itt <= *it) {
                    answer.push_back(*it - *itt);
                    break;
                }
            }
            if (itt == prices.end())
                answer.push_back(*it);
        }

        return answer;
    }
};

*/