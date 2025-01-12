#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<string> current;
        return computeKCombinationsHelper(s, k, 0, current, false);  
    }

    bool isPalindrome (string word) {
        string copy = word;
        reverse(copy.begin(), copy.end());
        if (word == copy)
            return true;
        return false;
    }


    bool computeKCombinationsHelper(const string& s, int k, int start, vector<string>& current, bool found) {
        
        bool result = true;
        if (k == 1) {
            if (start < s.size()) {
                current.push_back(s.substr(start));
                for (string word : current) {
                    result = result && isPalindrome(word);
                    cout << "word: " << word << endl;
                    if (!result)
                        break;
                }
                cout << "result: " << result << endl;
                cout << endl;
                
                current.pop_back();
                return result;                
            }
            return false;
        }

        // Iterate over possible split points
        for (int i = start; i < s.size() - (k - 1); ++i) {
            current.push_back(s.substr(start, i - start + 1));
            found = found || computeKCombinationsHelper(s, k - 1, i + 1, current, found);
            current.pop_back();
            if (found)
                return true;
        }
        return found;
    }

};

int main() {
    Solution solution;

    // Test cases
    string s1 = "annabelle";
    int k1 = 2;
    cout << "Can \"" << s1 << "\" be split into " << k1 << " palindromic substrings? " 
         << (solution.canConstruct(s1, k1) ? "Yes" : "No") << endl;

    /*
    string s2 = "racecar";
    int k2 = 3;
    cout << "Can \"" << s2 << "\" be split into " << k2 << " palindromic substrings? " 
         << (solution.canConstruct(s2, k2) ? "Yes" : "No") << endl;

    string s3 = "aabb";
    int k3 = 4;
    cout << "Can \"" << s3 << "\" be split into " << k3 << " palindromic substrings? " 
         << (solution.canConstruct(s3, k3) ? "Yes" : "No") << endl;

    string s4 = "a";
    int k4 = 1;
    cout << "Can \"" << s4 << "\" be split into " << k4 << " palindromic substrings? " 
         << (solution.canConstruct(s4, k4) ? "Yes" : "No") << endl;

    string s5 = "abc";
    int k5 = 2;
    cout << "Can \"" << s5 << "\" be split into " << k5 << " palindromic substrings? " 
         << (solution.canConstruct(s5, k5) ? "Yes" : "No") << endl;
         */

    return 0;
}