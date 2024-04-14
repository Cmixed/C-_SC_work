#include <iostream>
using namespace std;

int main()
{
    int f(int);
    int n, s;
    cin >> n;
    s = f(n);
    cout << s << endl;
    return 0;
}

int f(int n)
{
    if (n == 1)
        return 1;
    else
        return (n * n + f(n - 1));
}
