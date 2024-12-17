#include <vector>
#include <iostream>
#include <stack>

using namespace std;
// the best way is that for each number i have also the biggest prime number that preceeds it, so the looking is faster. Be careful nums[i] != 0;
// remember that 0 and 1 are not consider prime number
class Solution
{
public:
    bool primeSubOperation(vector<int> &nums)
    {
        if (nums.size() == 1)
            return true;
        else
        {
            // idk if it makes sense to have also this vector...
            int tryout, lastRight;
            vector<stack<int>> precs = findPrimesUpTo1000();
            stack<int> copy;
            bool order = true;
            for (int i = 1; i < nums.size(); i++)
            {
                if (nums[i - 1] >= nums[i])
                {
                    order = false;
                }
            }
            if (order)
            {
                // when array is already in strictly increasing order.
                return true;
            }

            for (int i = nums.size() - 1; i >= 1; i--)
            {
                // cout << "i: " << i << endl;
                if (nums[i] <= nums[i - 1])
                {
                    copy = precs[nums[i - 1]];
                    while (!copy.empty())
                    {
                        // cout << "lol: " << precs[nums[i - 1]].top() << endl;
                        tryout = nums[i - 1] - copy.top();
                        // cout << "tryout: " << tryout << endl;
                        copy.pop();
                        if (tryout >= nums[i])
                            break;
                        else
                            lastRight = tryout;
                    }
                    /*
                    cout << endl;
                    printVector(nums);
                    */
                    if (lastRight != 0)
                        nums[i - 1] = lastRight;
                    if (nums[i - 1] >= nums[i])
                        return false; // even though i subtract it, it doesn't change
                }
            }
            /*
            cout << endl;
            printVector(nums);
            */
            return true;
        }
    }

private:
    vector<stack<int>> findPrimesUpTo1000()
    {
        const int limit = 1000;
        vector<bool> isPrime(limit + 1, true);
        vector<stack<int>> primes(limit + 1);
        int precPrime = 0;
        stack<int> stack;
        stack.push(0);
        isPrime[0] = isPrime[1] = false;

        for (int p = 2; p * p <= limit; ++p)
        {
            if (isPrime[p])
            {
                for (int multiple = p * p; multiple <= limit; multiple += p)
                {
                    isPrime[multiple] = false;
                }
            }
        }

        for (int i = 2; i <= limit; ++i)
        {

            if (isPrime[i])
            {
                primes[i] = stack;
                stack.push(i);
            }
            else
            {
                primes[i] = stack;
            }
        }

        return primes;
    }

    void printVector(const std::vector<int> &vec)
    {

        for (int num : vec)
        {
            cout << num << " ";
        }
        cout << endl;
    }
};

/*
solution better optimized, mine beats only the 10%
a way to optimize it, it is to start from 0 and subtract it with the highest prime and then go on
class Solution {
public:
    bool check(int n)
    {
        if (n <= 1)
        return false;
        if (n == 2 || n == 3)
            return true;
        if (n % 2 == 0 || n % 3 == 0)
          return false;
        for (int i = 5; i <= sqrt(n); i = i + 6)
           if (n % i == 0 || n % (i + 2) == 0)
            return false;
        return true;
    }
    bool primeSubOperation(vector<int>& nums) {
        bool fl=true;
        int n=nums.size();
        if(n==1) return true;
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]>=nums[i])
            {
                fl=false;
            }
        }
        if(fl)
        {
            // when array is already in strictly increasing order.
            return true;
        }
        for(int i=nums[0]-1;i>1;i--)
        {
            if(check(i))
            {
                nums[0]-=i;
                break;
            }
        }
        for(int i=1;i<n;i++)
        {
            int k=nums[i]-nums[i-1];
            if(k<=0) return false;
            for(int j=k-1;j>1;j--)
            {
                if(check(j))
                {
                    nums[i]-=j;
                    break;
                }
            }
        }
        return true;
    }
};
*/

int main()
{
    vector<int> nums = {8, 4, 8, 7};
    Solution sol;
    cout << "sol: " << sol.primeSubOperation(nums) << endl;

    return 0;
}