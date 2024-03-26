#include <iostream>
#include <string>
using namespace std;

int main()
{
	int num = 0;
	string s;
	cin >> s;
	int c = s.length();
	cout << c;
	
	for(int i=0; i<=s.length(); i++)
	{
		num += s[i] - (int)'0';
	}
	if(num%3 == 0 && s[c]%2 == 0)
		cout << "YES";
	else
		cout << "NO";
		
	return 0;
}