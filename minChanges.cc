#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
class Solution {
public:
    int minChanges(string s) {
        
        int count0 = 0;
        int count1 = 0;
        int minChanges = INT_MAX;
        vector <int> zeros;
        vector <int> ones;
        int index, currentChanges;
        bool isZeroMore;
        string copy = s;
        for (int i = 2; i <= copy.size(); i+=2) {
            cout << "i = " << i << endl;
            if (copy.size()%i != 0) {
                continue;
            }
            for (int j = 0; j < copy.size(); j++) {
                cout << "j1= " << j << endl;
                if (copy[j] == '0') {
                    ++count0;
                    zeros.push_back(j);
                }
                else {
                    ++count1;
                    ones.push_back(j);
                }
                if ((j+1)%i==0) {
                    //i check immediately if i can find minChanges
                    cout << "j = " << j << endl;
                    cout << "currentChanges= " << currentChanges << endl;
                    cout << "minChanges= " << minChanges << endl;                    
                    currentChanges += min(count0,count1);
                    cout << "currentChanges1= " << currentChanges << endl;
                    if (currentChanges >= minChanges) {
                        continue;
                    }
                    isZeroMore = count0 >= count1 ? true : false;
                    cout << "count0= " << count0 << endl;
                    cout << "count1= " << count0 << endl;
                    if (isZeroMore) {
                        for (int index : ones) {
                            copy[index] = '0';
                        }
                    } else {
                        for (int index : zeros) {
                            copy[index] = '1';         
                        }
                    }
                    zeros.clear();
                    ones.clear();
                    count0 = count1 = 0;                    
                }
            }
            
            cout << "string = " << copy << endl;
            cout << "currentChanges2= " << currentChanges << endl;
            cout << "minChange2s= " << minChanges << endl;               
            minChanges = min(currentChanges, minChanges);
            cout << endl;
            currentChanges = 0;
            copy = s;
        }
        return minChanges;
    }
};
*/
class Solution {
public:
    int minChanges(string s) {
        // Initialize with first character of string
        char currentChar = s[0];

        int consecutiveCount = 0;
        int minChangesRequired = 0;

        // Iterate through each character in the string
        for (int i = 0; i < s.length(); i++) {
            // If current character matches the previous sequence
            if (s[i] == currentChar) {
                consecutiveCount++;
                continue;
            }

            // If we have even count of characters, start new sequence
            if (consecutiveCount % 2 == 0) {
                cout << "consecutiveCount: " << consecutiveCount << endl;
                cout << "i= " << i << endl;
                consecutiveCount = 1;
            }
            // If odd count, we need to change current character
            // to match previous sequence
            else {
                consecutiveCount = 0;
                minChangesRequired++;
            }

            // Update current character for next iteration
            currentChar = s[i];
            cout << "currentChar: " << currentChar << endl;
        }

        return minChangesRequired;
    }
};

int main () {

    string s = "10000010";
    Solution solution;
    int result = solution.minChanges(s);
    cout << "Result: " << result << endl;
    return 0;
}