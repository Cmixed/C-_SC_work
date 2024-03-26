#include <iostream>
using namespace std;
int main()
{
	int a=0, b=0;
	cin >> a >> b;
	for(int i=a;i<=b;i++)
	{
		if(i%5==0 || i%7==0)
			if(i%5==0 && i%7==0)
			;
			else
				cout << i << endl << endl;
	}
	
	return 0;
}