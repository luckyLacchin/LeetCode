#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

/*
You are given a sorted array nums of n non-negative integers and an integer maximumBit. You want to perform the following query n times:

Find a non-negative integer k < 2maximumBit such that nums[0] XOR nums[1] XOR ... XOR nums[nums.length-1] XOR k is maximized. k is the answer to the ith query.
Remove the last element from the current array nums.
Return an array answer, where answer[i] is the answer to the ith query.
*/
//This solution is too slow, think about something else
/*
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int currentXor, preXor;
        vector<int> queries;
        currentXor = preXor = nums[0];
        int maxXor = INT_MIN;
        int maxK = -1;
        for (int k = 0; k < pow(2,maximumBit);k++) {
                currentXor ^= k;
                if (maxXor < currentXor) {
                    maxXor = currentXor;
                    maxK = k;
                }
                currentXor = preXor;
        }
        queries.push_back(maxK);
        if (nums.size() > 1) {
            for (int i = 1; i < nums.size(); i++) {
                currentXor = preXor ^= nums[i];
                maxXor = INT_MIN;
                for (int k = 0; k < pow(2,maximumBit);k++) {
                    currentXor ^= k;
                    if (maxXor < currentXor) {
                        maxXor = currentXor;
                        maxK = k;
                    }
                    currentXor = preXor;
                }
                queries.push_back(maxK);
            }
        }
        
        reverse(queries.begin(),queries.end());
        return queries;
    }
};

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> prefixXOR(n);
        vector<int> answer(n);
        prefixXOR[0] = nums[0];
        for(int i = 1; i < n; i++){
           prefixXOR[i] =  prefixXOR[i - 1] ^ nums[i];
        }
        int mask = 0xFFFFFFFF << maximumBit;
        for(int i = 0; i < n; i++){
           int extract = prefixXOR[n-1-i] & ~(mask);
           answer[i] = ~extract & ~mask;
        }
        return answer;
    }
};

*/

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> queries;
        int currentXor = 0;

        for (int num : nums) {
            currentXor ^= num;
        }

        int mask = (1 << maximumBit) - 1;
    
        for (int i = nums.size() - 1; i >= 0; --i) {
            
            queries.push_back(currentXor ^ mask);
            currentXor ^= nums[i];
        }

        return queries;
    }
};

void printVector(const std::vector<int>& vec) {
    
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main () {

    Solution sol;
    vector<int> nums = {2,3,4,7};
    int maximumBit = 3;
    printVector(sol.getMaximumXor(nums,maximumBit));
    //5 2 6 5
    return 0;
}