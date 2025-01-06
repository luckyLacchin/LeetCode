#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {

        if (arr.size() == 2)
        {
            if (arr[0] > arr[1])
                return 1;
            else
                return 2;
        }
        else if (arr.size() == 1)
        {
            return 1;
        }
        else
        {
            int chunks = 1;
            int start = 0;
            for (int i = 0; i < arr.size(); i++)
            {
                if (arr[i] == i)
                {
                    ++chunks;
                    mergeSort(arr, start, i - 1);
                    start = i + 1;
                    printVector(arr);
                }
            }
            mergeSort(arr,start,arr.size()-1);
            if (isOrganized(arr))
                return chunks;
            else
                return 1;
        }
    }

    bool isOrganized(vector<int> &arr)
    {
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] < arr[i - 1])
                return false;
        }
        return true;
    }

    void mergeSort(vector<int> &arr, int left, int right)
    {
        if (left < right)
        {
            int mid = left + (right - left) / 2;

            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);

            merge(arr, left, mid, right);
        }
    }

    void merge(vector<int> &arr, int left, int mid, int right)
    {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> L(n1);
        vector<int> R(n2);

        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int i = 0; i < n2; i++)
            R[i] = arr[mid + 1 + i];

        int i = 0;
        int j = 0;
        int k = left;

        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    void printVector(vector<int> vec)
    {

        for (int x : vec)
        {
            cout << x << " ";
        }
        cout << endl;
    }
};

int main()
{

    vector<int> vec = {1,0,2,3,4};
    Solution sol;
    cout << sol.maxChunksToSorted(vec) << endl;
    // printVector(prices);

    return 0;
}