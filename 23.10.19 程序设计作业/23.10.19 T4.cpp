#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	
	if(t>=90 && t<=100)
		cout << 'A';
	else if(t>=80 && t<90)
		cout << 'B';
	else if(t>=70 && t<80)
		cout << 'C';
	else if(t>=60 && t<70)
		cout << 'D';
	else
		cout << 'E';
	
	return 0;
}