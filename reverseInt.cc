#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int y = 0;
        while (x!= 0) {//i cna also write x > 0
            y = y * 10;
            y += x%10;
            //cout << "y = " << y << endl;
            

            x /= 10;
            //cout << "x = " << x << endl;
        }

        if (y > INT_MAX || y < INT_MIN)
            return 0;
        return y;   
    }
};


int main()
{

    int x = -12340;
    Solution sol;
    cout << "Soluzione: " << sol.reverse(x) << endl;

    return 0;
}

