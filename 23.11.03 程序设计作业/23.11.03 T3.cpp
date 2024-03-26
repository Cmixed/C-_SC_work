#include <iostream>
using namespace std;
int if_min(int a, int b,int c);
int common_divisor(int min, int a, int b, int c);
int main()
{
	int a, b, c, min, cd;
	a = b =c = 0;
	cin >> a >> b >> c;
	min = if_min(a,b,c);
	cd = common_divisor(min,a,b,c);
	cout << cd;

	return 0;
}

int if_min(int a, int b, int c)
{
	int min = 0;
	if(a<=b && a<=c)
		min = a;
	else if(b<=a && b<=c)
		min = b;
	else
		min = c;
	
	return min;
}

int common_divisor(int min, int a, int b, int c)
{
	int cd = 1;
	for(int i=2; i<=min; i++)
		if(a%i==0 && b%i==0 && c%i==0)
			cd = i;
	return cd;
}



