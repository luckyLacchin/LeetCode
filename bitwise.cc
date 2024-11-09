#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
//like this it should work but maybe i can do everything in the backtracking function
//the solution is right but it is not optimized due to backtracking...
class Solution {
public:
    //i can prune immediately the subset that are equal to zero
    void backtrack(vector<int>& nums, int index, vector<int>& currentSubset, vector<vector<int>>& subsets, int currentBitwise) {

        //printVector(currentSubset);
        subsets.push_back(currentSubset);
        
        for (int i = index; i < nums.size(); i++) {

            if ((currentBitwise & nums[i]) <= 0)
                return;

            currentSubset.push_back(nums[i]);
            currentBitwise &= nums[i];
            backtrack(nums, i + 1, currentSubset, subsets, currentBitwise); 

            currentSubset.pop_back();
        }
    }
    /*
    int largestCombination(vector<int>& candidates) {
        
        vector<vector<int>> subsets;
        vector<int> currentSubset;
        int currentBitwise = candidates[0];
        backtrack(candidates,0,currentSubset,subsets,currentBitwise); //2^n, we are calculating all the subsets, maybe there is a way to do pruning before..
        //in subsets now we have all the subset, now we visit them
        int maxSize = INT_MIN;
        int tempSize, tempBitwise;

        for (vector<int> temp : subsets) {
            cout << "ciao" << endl;
            printVector(temp);
            if (temp.empty()) {
                continue;  // Skip empty subsets
            }
            tempBitwise = temp[0];
            for (int num : temp) {
                tempBitwise &= num;
            }
            cout << "TempBitWise: " << tempBitwise << endl;
            tempSize = temp.size();
            maxSize = max(maxSize,tempSize);
        }

        return maxSize;
    }
    */
    //this solution is better just O(n)
    int largestCombination(vector<int>& candidates) {
        int maxSize = 0;
        
        // We will check each bit position from 0 to 31 (assuming 32-bit integers)
        for (int bit = 0; bit < 32; ++bit) {
            int count = 0;
            for (int num : candidates) {
                if (num & (1 << bit)) {
                    count++;  // Count how many numbers have the `bit` set to 1
                }
            }
            maxSize = max(maxSize, count);  // Track the largest count of numbers sharing this bit
        }
        
        return maxSize;
    }

    void printVector(const std::vector<int>& vec) {
    
        for (int num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }
};


int main () {

    vector <int> candidates = {16,17,71,62,12,24,14};
    Solution solution;
    cout << "Result: " << solution.largestCombination(candidates) << endl;


    return 0;
}

/*
class Solution {
public:
    static int largestCombination(vector<int>& candidates) {
        int max_set=0;
        for(char b=0; b<24; b++){
            int b_bit_set=0;
            for(unsigned x: candidates){
                b_bit_set+=(x>>b & 1);
            }
            max_set=max(max_set, b_bit_set);
        }
        return max_set;
    }
};


class Solution {
public:
    static int largestCombination(vector<int>& candidates) {
        int max_set=0;
        for(char b=0; b<24; b++){
            int b_bit_set=0;
            for(unsigned x: candidates){
                b_bit_set+=(x>>b & 1);
            }
            max_set=max(max_set, b_bit_set);
        }
        return max_set;
    }
};

*/