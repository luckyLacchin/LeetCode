#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string s(nums.size(), '1');
        cout << "initial string: " << s << endl;
        for (string str : nums) {
            cout << "str = " << str << endl;
            for (int i = 0; i < nums.size(); i++) {
                s[i] = s[i] ^ str[i];
                cout << "s[i] = " << s[i] << endl;
            } 
        }

        return s;
    }
};

int main() {
    Solution solution;

    vector<string> nums1 = {"01", "10"};
    cout << "Result 1: " << solution.findDifferentBinaryString(nums1) << endl;

    vector<string> nums2 = {"000", "011", "110"};
    cout << "Result 2: " << solution.findDifferentBinaryString(nums2) << endl;

    vector<string> nums3 = {"0", "1"};
    cout << "Result 3: " << solution.findDifferentBinaryString(nums3) << endl;

    return 0;
}
