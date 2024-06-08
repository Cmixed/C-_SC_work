#include <iostream>
#include <cmath>

using namespace std;

int n = 8;
int count = 0; // 策略数
const int maxn = 100;
int P[maxn];

bool hashTable[maxn] = {false};

void generateP(int index)
{
    if (index == n + 1)
    {
        bool flag = true;
        for (int  i = 1; i < n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (abs(i - j) == abs(P[i] - P[j]) )
                {
                    flag = false;
                }
                
            }
            
        }
        if (flag)
        {
            ::count++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (!hashTable[i])
        {
            P[index] = i;
            hashTable[i] = true;
            generateP(index + 1);
            hashTable[i] = false;
        }
        
    }
}

int main(int argc, const char** argv) 
{
    cin >> ::n;
    generateP(1);
    cout << ::count << endl;
    return 0;
}