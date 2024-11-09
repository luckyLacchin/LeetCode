#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        
        vector<int> count;
        bool swapped;
        for (int n: nums) {
            count.push_back(bitset<8>(n).count());
        }
        
        for (int n : count) {
            cout << n << " ";
        }
        cout << endl;
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            // Track whether any swaps were made in this pass
            bool swapped = false;
            for (int j = 0; j < n - i - 1; ++j) {
                // Swap if elements are out of order
                if (nums[j] > nums[j + 1] && count[j] == count[j+1]) {
                    swap(nums[j], nums[j + 1]);
                    swap(count[j], count[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i-1])
                return false;
        }
        return true;
    }

};
/*
class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        vector<pair<int,int>>mm;
        mm.push_back({nums[0],nums[0]});
        for(int i = 1 ; i < nums.size() ;i++)
        {
            int cur = __builtin_popcount(nums[i]);
            int prev = __builtin_popcount(nums[i-1]);
            if(cur != prev)
            {   
                mm.push_back({nums[i],nums[i]});
            }
            mm.back().first = min(mm.back().first,nums[i]);
            mm.back().second = max(mm.back().second,nums[i]);
        }
        for(int i = 1 ; i < mm.size() ; i++)
        {
            if(mm[i-1].second > mm[i].first)
                return false;
        }
        return true;
    }
};

The algorithm leverages the fact that elements within the same group (i.e., those with the same number of set bits) can be sorted freely by swapping adjacent elements. By checking that each group's maximum is less than the next group's minimum, it ensures that elements across groups are already in non-overlapping ranges, which guarantees a sorted order.
*/

int main () {

    vector<int> nums = {3,16,8,4,2};
    Solution sol;
    cout << "Il vettore puo' essere ordinato? " << sol.canSortArray(nums) << endl;

    return 0;
}