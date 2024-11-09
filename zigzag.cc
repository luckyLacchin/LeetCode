#include <iostream>
#include <vector>

using namespace std;
// i don't know why on leetcode doesn't work to retry...Read on chatgpt what was the problem...
// https://leetcode.com/problems/zigzag-conversion/
class Solution
{
public:
    /*
    string convert(string s, int numRows)
    {
        string result = "";
        if (s.size() > 1 && numRows != 1)
        {
            int numColum = calColumn(s.size(), numRows);
            //cout << "numColumn: " << numColum << endl;
            vector<vector<char>> matrix(numRows, vector<char>(numColum, '0'));
            int index = 0, j = 0, i = 0;
            int sottr = numRows - 2 + 1;

            while (j < numColum)
            {
                // cout << "j: " << j << endl;
                for (i = 0; i < numRows; i++)
                {

                    matrix[i][j] = s[index];
                    ++index;
                }
                --i;
                // cout << "i0: " << i << endl;
                for (int k = 0; k < numRows - 2 && j < numColum-1; k++, j++, i--)
                {
                    /*
                    cout << "i1: " << i << " , j1: " << j << endl;
                    cout << "j+1: " << j + 1 << endl;
                    cout << "s[index]1: " << s[index] << endl;

                    matrix[i - 1][j + 1] = s[index];
                    ++index;
                }
                // cout << "j2 = " << j << endl;
                ++j;
            }
            /*
            cout << endl;
            print2DVector(matrix);
            cout << endl;

            for (vector<char> vec : matrix)
            {
                for (char c : vec)
                {
                    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ',' || c == '.')
                    {
                        result += c;
                    }
                }
            }
        }
        else
        {
            result = s;
        }

        return result;
    }
    */

    string convert(string s, int numRows)
    {
        if (numRows == 1 || s.size() <= numRows)
            return s; // Special cases

        vector<string> rows(min(numRows, int(s.size()))); // Row storage
        int currentRow = 0;
        bool goingDown = false;

        // Traverse each character in s
        for (char c : s)
        {
            rows[currentRow] += c; // Append character to the current row

            // Change direction if we are at the top or bottom row
            if (currentRow == 0 || currentRow == numRows - 1)
            {
                goingDown = !goingDown;
            }

            // Move up or down
            currentRow += goingDown ? 1 : -1;
        }

        // Concatenate all rows to form the final result
        string result;
        for (string &row : rows)
        {
            result += row;
        }

        return result;
    }

    int calColumn(int size, int numRows)
    {
        if (numRows == 1)
            return size; // Special case for a single row

        int cycleLength = numRows + (numRows - 2); // One full zigzag cycle
        int cycles = size / cycleLength;           // Number of full cycles
        int remainder = size % cycleLength;        // Characters left after full cycles

        int columns = cycles * (numRows - 1); // Each cycle adds numRows-1 columns

        // If there are remaining characters, calculate additional columns needed
        if (remainder > 0)
        {
            columns += 1; // First extra column for the vertical part
            if (remainder > numRows)
            {
                columns += remainder - numRows; // Extra columns for diagonal characters
            }
        }

        return columns;
    }

    void print2DVector(const vector<vector<char>> &matrix)
    {
        for (const auto &row : matrix)
        {
            for (const auto &ch : row)
            {
                cout << ch << ' ';
            }
            cout << endl; // Move to the next line after each row
        }
    }
};

int main()
{

    string s = "PAYPALISHIRING";
    int numRows = 4;
    Solution sol;
    cout << "Sol: " << sol.convert(s, numRows) << endl;

    return 0;
}