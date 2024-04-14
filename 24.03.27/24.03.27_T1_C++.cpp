#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char** argv) 
{
    string str1;
    cin >> str1;
    long long sum = 0;
    for (unsigned int i = 0; i < str1.length(); i++) {
        sum =  (sum * 10 + (str1[i] - '0')) % 6;
    }

    if (sum == 0)  {
        cout << "YES";
    } else
        cout << "NO";
    
    return 0;
}