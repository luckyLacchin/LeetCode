#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class Solution
{
public:
    /*
        long long minEnd(int n, int x)
        {

            bitset<28> resultBit(x);
            int base = findFirstZeroBit(x);
            long long result = x;
            int initialValue = x;
            int prev = x;
            bool first = true;
            for (; n > 1; n--)
            {
                if (((result + 1) & initialValue) != initialValue)
                {

                    if (first)
                    {
                        result = initialValue | (1 << base);
                        first = false;
                        prev = result;
                        cout << "result1: " << result << endl;
                    }
                    else
                    {
                        result = prev | (1 << base);
                        cout << "result: " << result << endl;
                    }
                }
                else
                {
                    ++result;
                }
                base = findFirstZeroBit(result);
                resultBit = bitset<28>(result);
                if (isFirstZeroAfterOne(result))
                    first = true;
            }

            return result;
        }
        int findFirstZeroBit(int num)
        {
            int position = 0;

            while (num & (1 << position))
            {
                position++;
            }

            return position;
        }
        bool isFirstZeroAfterOne(int num)
        {
            // If `num` is zero, it has no '1' bits, so return false.
            if (num == 0)
                return false;

            // Skip trailing zeros (if any) by right-shifting until the last '1' is at the lowest bit.
            while ((num & 1) == 0)
            {
                num >>= 1;
            }

            // After skipping, check if the next bit is zero
            // Right-shift by one to look at the next bit after the last '1' bit.
            num >>= 1;

            // Check if the next bit after the first '1' is zero.
            return (num & 1) == 0;
        }
        */
    int merge(int x, int v)
    {
        int result = x;
        int bitPos = 0;

        while (v > 0)
        {

            if ((x & (1 << bitPos)) == 0)
            {

                if (v & 1)
                {
                    result |= (1 << bitPos);
                }
                v >>= 1;
            }
            bitPos++;
        }
        return result;
    }

    int minEnd(int n, int x)
    {
        return merge(x, n - 1);
    }
};

int main()
{
    int n = 8;
    int x = 1;
    Solution sol;
    cout << "Soluzione: " << sol.minEnd(n, x) << endl;
    return 0;
}
