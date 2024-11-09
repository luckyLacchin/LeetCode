#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string compressedString(string word) {
        
        string comp = "";
        int indexComp = 0;
        int curLength = 1; //i take in consideration already the first letter

        if (word.size() > 1) {
            for (int i = 1; i < word.size(); i++) {
                if (word[i] != word[i-1] || curLength == 9) {
                    comp = comp + to_string(curLength) + word[i-1];
                    cout << "compRn: " << comp << endl;
                    curLength = 0;
                }
                if (i == word.size()-1) { // we are at the end of word
                    curLength += 1;
                    comp = comp + to_string(curLength) + word[i];
                    cout << "compRn: " << comp << endl;
                }
                ++curLength;
            }
        }
        else {
            comp = "1" + word;
        }

        return comp;
    }
};
//Best solution
class Solution {
public:
    string compressedString(string word) {
        string temp;
        char last=word[0];
        int cnt=1;
        for(int i=1; i<word.size(); i++){
            if(last==word[i]){
                if(cnt<9){
                    ++cnt;
                    continue;
                }else{
                    temp.push_back(cnt+'0');
                    temp.push_back(last);
                    cnt=1;
                }
            }else{
                temp.push_back(cnt+'0');
                temp.push_back(last);
                cnt=1;
                last=word[i];
            }
        }
        temp.push_back(cnt+'0');
        temp.push_back(last);
        return temp;
    }
};


int main () {


    Solution sol;
    string word = "d";
    string res = sol.compressedString(word);
    cout << "CompressedString: " << res << endl;
}

