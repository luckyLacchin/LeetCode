#include <iostream>
using namespace std;
int f (int n) {
    int c = 0;
    while (n >= 0) {
        n -= 2;
        c += n - 2;
    }
    return c;
}

int main () {

    int n = 2;
    cout << f(n) << endl;
    cout << f(n-2) << endl;

}