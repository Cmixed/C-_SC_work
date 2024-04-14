#include <iostream>

using namespace std;
int sum(int n1, int n2);

int result = 0;

int main(int argc, char const *argv[])
{
    
    int n1, n2;
    cin >> n1 >> n2;
    result = sum(n1, n2);
    if (result != 0)
    {
        cout << result;
    } else 
    {
        cout << " ";
    }
    
   
    return 0;
}

int sum(int n1, int n2)
{
    int result = 0;
    if (n1>n2)
        return 0;
    else
        result=n1+sum(n1+1, n2);

    return result;
}