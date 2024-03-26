#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    int count = 0;
    cin >> n;
    if(n==1)
        cout << n;
	int i = 2;	
	while(i<=n){
    	for(int j=2; j<=i; j++)
		{
        	if(i%j==0)
        		count++;
		}
        if(count==1)
       		cout << i << endl << endl;
       	i++;
       	count = 0;
    }
    return 0;
}