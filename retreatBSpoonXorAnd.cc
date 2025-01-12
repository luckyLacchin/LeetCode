#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <string>
#include <list>

using namespace std;


int and_list (vector<int> x) {  // i use vector  as a list of nonnegative integers
    
    int res = x[0];  //init with the first element, i know that it exists, bc nonempty
    if (x.size() > 1) {
        for (int i = 1; i < x.size(); i++) { //starting from the second one element i iterate
            res &= x[i];
            if (res == 0)
                return 0; //i can give back also res
        }
    }
    return res;
}

int xor_list (vector<int> x) {//same implementation but using the xor operator

    int res = x[0];
    if (x.size() > 1) {
        for (int i = 1; i < x.size(); i++) {
            res ^= x[i];
        }
    }
    return res;
}

void printVector(const std::vector<int>& vec) {
    
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}


void backtrack(vector<int>&  nums, int index, vector<vector<int>>& subsets) {
    
    vector<int> currentSubset;

    for (int i = index; i < nums.size(); i++) {
        currentSubset.push_back(nums[i]);
        subsets.push_back(currentSubset);

    }
}

int f(vector<int> x) {
    
    if (x.empty())
        return 0;
    
    vector<vector<int>> subsets;
    vector<int> results;
    int andResult;
    for (int i = 0; i < x.size(); i++) {
        backtrack(x, i, subsets);
    }
    
    int xorResult;
    for (vector<int> curSet : subsets) {
        
        if (curSet.empty())
            continue;
        xorResult = curSet[0]; //we are sure that it is non empty
        if (curSet.size() > 1) {
            for (int i = 1; i < curSet.size(); i++) {
                xorResult ^= curSet[i];
            }   
        }
         
        results.push_back(xorResult);
 
    }
    andResult = results[0]; //for sure is non empty
    for (int n : results) { // i know that using the foreach the first iter is x[0] & x[0], but it is = x[0], so i don't mind. I prefer doing like this instead of looking for its size once more, for xor it would change, for and no
        if (andResult == 0)
            return 0;
        andResult &= n;
    }

    return andResult;
}


int main () {

    vector<int> x = {3,5,1};
    //cout << and_list(x) << endl;
    //cout << xor_list(x) << endl;
    f(x);
    return 0;
}