#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int a,b;
	cin >> a;
	cin.get();
	cin >> b;
//	cout << a << b;
	switch(b)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: cout << 31;
				 break;
		case 2:  if(0 == a%4) cout << 29;
				   else cout << 28;
				 break;
		case 4:
		case 6:
		case 9:
		case 11: cout << 30;
				 break;
				 
		default : cout << "BUG";
	}
	
	return 0;
}