#include <iostream>
using namespace std;
int main()
{
	int a=0,b=0,min=0,max=0;
	cin >> a >> b;
	if(a>b)
		min=b;
	else
		min=a;
	for(int i=1;i<min;i++)
		if(a%i==0 && b%i==0)
			max=i;
	cout << max;
	return 0; 
}