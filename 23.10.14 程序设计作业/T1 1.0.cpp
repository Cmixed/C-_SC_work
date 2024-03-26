#include <iostream>
#include <string>

using namespace std;
int num(string);

int main()
{
	string a, b;
	int max;
	
	cin >> a >> b;
//	cout << a.length() << b.length() << endl;
	
	if(a > b)
		max = num(a);
	else
		max = num(b);
	
//	cout << (int) a[0] - (int)'/' << endl;
	cout << max;
	
	return 0;	
}

int num(string s)
{
	int num_s = 0;
	for(int i=0; i<s.length() ; i++)
		num_s += ((int)s[i] - (int)'0');
	return num_s;
		
}