#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        
        int index = -1;
        int min = INT_MAX;

        while (k > 0) {
            for (int i = 0; i < nums.size(); i++) {
                cout << "ciao" << endl;
                if (nums[i] < min) {
                    min = nums[i];
                    index = i;
                    cout << "index: " << index << endl;
                }
            }

            nums[index] = nums[index] * multiplier;
            cout << "k: " << k << endl;
            cout << "index: " << index << endl;
            k--;
            min = INT_MAX;
            
        }

        return nums;
    }
};

void printVector (vector <int> vec) {

    for (int x : vec) {
        cout << x << " ";
    }
    cout << endl;
}

int main () {

    vector<int> nums = {2,1,3,5,6};
    Solution sol;
    int k = 5;
    int multiplier = 2;
    sol.getFinalState(nums,k,multiplier);
    //cout << "Soluzione: " << sol.getFinalState(nums,k,multiplier) << endl;
    printVector(nums);

    return 0;
}