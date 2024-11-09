#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Given a string s, return the longest 
palindromic
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";
        
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        int start = 0;
        int maxLength = 1;
        
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        
        for (int length = 2; length <= n; length++) {
            for (int i = 0; i <= n - length; i++) {
                int j = i + length - 1;
                
                if (s[i] == s[j] && (length == 2 || dp[i+1][j-1])) {
                    dp[i][j] = true;
                    if (length > maxLength) {
                        maxLength = length;
                        start = i;
                    }
                }
            }
        }
        
        return s.substr(start, maxLength);
    }
};

/*
class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.length();
        int max_len = 0;
        int start = 0;

        for(int i=0; i<n ;i++)
        {
            int right = i;
            while(right < n && s[i] == s[right]) right++;

            int left = i-1;
            while(left >= 0 && right < n && s[left] == s[right])
            {
                left--;
                right++;
            }

            int cur_len = (right -1) - (left + 1) + 1;

            if(max_len < cur_len)
            {
                max_len = cur_len;
                start = left + 1;
            }
        }

        return s.substr(start,max_len);
    }
};

*/

int main () {

    string s = "babad";
    Solution sol;
    cout << "Soluzione: " << sol.longestPalindrome(s) << endl;


    return 0;
}