#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <set>
using namespace std;
//credo che con il backtracking fosse piuttosto facile, ma con complessità 2^n, adesso credo che la cosa migliore sia creare dei set, vedere se entra l'elemento e se non lo facesse mi fermo

class Solution {
    
public:
    int lengthOfLongestSubstring(string s) {
        vector<string> subsets;
        string currentString;
        set<char> setChar;
        pair<set<char>::iterator,bool> ret;
        int maxLength = INT_MIN;
        //backtracking (s,0,currentString,subsets);
        int length = 0;
        bool isCorrect = true; 
        for (int i = 0; i < s.size(); i++) {
            int j = i;
            for (; j < s.size(); j++) {
                ret = setChar.insert(s[j]);
                length = j - i + 1;
                if (ret.second == false) {
                    break;
                }
            }
            //devo togliere il primo elemento del set
            if (j == s.size())
                maxLength = max(maxLength,length);
            else
                maxLength = max(maxLength,length-1);
            setChar.clear();
        }

        if (maxLength == INT_MIN)
            maxLength = 0;
        
        return maxLength;
    }
 
};

int main() {    

    string s = "dvdf";

    Solution solution;

    int result2 = solution.lengthOfLongestSubstring(s);

    cout << "Result: " << result2 << endl;

    return 0;
}