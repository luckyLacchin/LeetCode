#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
    string repeatLimitedString(string s, int repeatLimit)
    {
        if (s.size() > 1)
        {
            // facciamo un vettore, dopo faccio ordine decrescente, leggiamo, vediamo se repeatLimit sia rispettato in caso otteniamo la lettere successiva e così via
            vector<char> vec(s.begin(), s.end());
            vector<char> res;
            // void mergeSort(vector<char>& arr, int left, int right)
            mergeSort(vec, 0, vec.size() - 1);
            vector<pair<char, int>> elems;
            elems.push_back(make_pair(vec[0], 1));
            int index = 0;
            int reps = 1;
            for (int i = 1; i < vec.size(); i++)
            {
                if (vec[i] == vec[i - 1])
                    elems[index].second += 1;
                else
                {
                    elems.push_back(make_pair(vec[i], 1));
                    ++index;
                }
            }
            /*
            cout << endl;
            printVector(vec);
            printVectorPair(elems);
            */
            if (elems.size() > 1)
            {
                index = 0;
                res.push_back(elems[index].first);
                //cout << "resElement: " << elems[index].first << endl;
                elems[index].second -= 1;
                index = elems[index].second > 0 ? 0 : 1;
                for (int i = 1; i < vec.size(); i++)
                {
                    // cout << "i = " << i << endl;
                    if (elems[index].first == res[res.size() - 1])
                    {
                        ++reps;
                        if (reps > repeatLimit)
                        {
                            if (index + 1 >= elems.size())
                                break;
                            for (int i = index + 1; i < elems.size(); i++)
                            {
                                if (elems[i].second > 0)
                                {
                                    res.push_back(elems[i].first);
                                    elems[i].second -= 1;
                                    //cout << "resElement+1: " << elems[index + 1].first << endl;
                                    reps = 0;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            elems[index].second -= 1;
                            res.push_back(elems[index].first);
                            //cout << "resElement2: " << elems[index].first << endl;
                        }
                    }

                    else
                    {
                        if (elems[index].second <= 0)
                        {   
                            int i = index;
                            for (; i < elems.size(); i++)
                            {
                                if (elems[i].second > 0)
                                {
                                    index = i;
                                    break;
                                }
                            }
                            if (i == elems.size())
                                break;


                        }

                        res.push_back(elems[index].first);
                        //cout << "resElement3: " << elems[index].first << endl;
                        elems[index].second -= 1;
                        reps = 1;
                    }

                    if (elems[index].second <= 0)
                    {
                        if (index >= elems.size() - 1)
                        {
                            break; // così usciamo e restituiamo direttamente la stringa
                        }
                        else
                            ++index;
                    }
                }

                std::string str(res.begin(), res.end());
                return str;
            }
            else
            {
                if (s.size() >= repeatLimit)
                    return s.substr(0, repeatLimit);
                else
                    return s;
            }
        }
        else
        {
            return s;
        }
    }

    void merge(vector<char> &arr, int left, int mid, int right)
    {
        // Create temporary vectors for the left and right halves
        vector<char> leftArr(arr.begin() + left, arr.begin() + mid + 1);
        vector<char> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

        int i = 0, j = 0, k = left;

        // Merge the two halves in descending order
        while (i < leftArr.size() && j < rightArr.size())
        {
            if (leftArr[i] > rightArr[j])
            {
                arr[k] = leftArr[i];
                i++;
            }
            else
            {
                arr[k] = rightArr[j];
                j++;
            }
            k++;
        }

        // Copy the remaining elements of the left half, if any
        while (i < leftArr.size())
        {
            arr[k] = leftArr[i];
            i++;
            k++;
        }

        // Copy the remaining elements of the right half, if any
        while (j < rightArr.size())
        {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
    }

    // Merge Sort function
    void mergeSort(vector<char> &arr, int left, int right)
    {
        if (left < right)
        {
            int mid = left + (right - left) / 2;

            // Recursively sort the two halves
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);

            // Merge the two halves
            merge(arr, left, mid, right);
        }
    }

    void printVector(vector<char> vec)
    {

        for (char x : vec)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    void printVectorPair(vector<pair<char, int>> vec)
    {

        for (pair<char, int> x : vec)
        {
            cout << "(" << x.first << "," << x.second << "), ";
        }
        cout << endl;
    }
};

int main()
{

    string s = "xyutfpopdynbadwtvmxiemmusevduloxwvpkjioizvanetecnuqbqqdtrwrkgt";
    int repeatLimit = 1;
    Solution sol;
    cout << "Soluzione: " << sol.repeatLimitedString(s, repeatLimit) << endl;

    return 0;
}


/*

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        string result;
        int currentCharIndex = 25;  // Start from the largest character
        while (currentCharIndex >= 0) {
            if (freq[currentCharIndex] == 0) {
                currentCharIndex--;
                continue;
            }

            int use = min(freq[currentCharIndex], repeatLimit);
            result.append(use, 'a' + currentCharIndex);
            freq[currentCharIndex] -= use;

            if (freq[currentCharIndex] >
                0) {  // Need to add a smaller character
                int smallerCharIndex = currentCharIndex - 1;
                while (smallerCharIndex >= 0 && freq[smallerCharIndex] == 0) {
                    smallerCharIndex--;
                }
                if (smallerCharIndex < 0) {
                    break;
                }
                result.push_back('a' + smallerCharIndex);
                freq[smallerCharIndex]--;
            }
        }

        return result;
    }
};

L'idea praticamente è la mia stessa ma estremamente ottimizzata
*/