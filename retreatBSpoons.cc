#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <string>

using namespace std;

bool isFlowing (string s) {
    for (int i = 1; i < s.size(); i++) {
        if (s[i] < s[i-1])
            return false;
    }
    return true;
}

bool isReceding (string s) {
    for (int i = 1; i < s.size(); i++) {
        if (s[i] > s[i-1])
            return false;
    }
    return true;
}

void backtrack(string& nums, int index, string& currentSubset, vector<string>& subsets) {
    
    if (currentSubset.size() >= 3) { // i should have done it also >= 1 and <= 5....
        //cout << currentSubset << endl;
        subsets.push_back(currentSubset);
        return;  // Exit if we have a valid subset of length 3
    }

    // Prova ad aggiungere ogni elemento successivo al sottoinsieme corrente in modo contiguo
    for (int i = index; i < nums.size(); i++) {

        currentSubset.push_back(nums[i]);  // Aggiunge l'elemento corrente al sottoinsieme

        // Richiama ricorsivamente per il prossimo elemento contiguo
        backtrack(nums, i, currentSubset, subsets); 
        backtrack(nums, i + 1, currentSubset, subsets);
        if (i > 0)
            backtrack(nums, i - 1, currentSubset, subsets); 
        currentSubset.pop_back();  // Rimuove l'ultimo elemento per tornare indietro
    }
}



int main () {

    /*
    string test = "abcdef";
    cout << isFlowing(test) << endl; // Should print 1 (true)
    cout << isReceding(test) << endl; // Should print 0 (false)
    */
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string currentSubset; 
    vector<string> subsets;
    backtrack(alphabet,0,currentSubset,subsets);
    int count = 0;
    for (string s: subsets) {
        //cout << s << endl;
        if (!isReceding(s) && !isFlowing(s)) {
            //cout << "ciao" << endl;
            ++count;
        }
    }
    cout << count << endl;

    return 0;
}