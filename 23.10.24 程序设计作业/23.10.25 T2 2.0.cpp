#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;

//for function
int prefectnum(string s);
int svsum(string s);
int fact(int num);

int main()
{
	int a = 0;
	cin >> a;
	string s[a];
	for(int i=0;i<a;i++)
		cin >> s[i];
//**************************************************************
//	for(int i=0;i<a;i++)
//		cout << s[i] << endl;
		
	for(int i=0;i<a;i++)
		cout << prefectnum(s[i]) << endl;
	return 0;
}

int prefectnum(string s)
{
	int s6n = s.length();
//***************************************************
//	cout << svsum(s) << ' ' << "line27" << endl;
//	cout << svsum("70") << "line28" << endl;

	if(svsum(s) < svsum("66"))
		s6n = 0;
	else if(s[0] < '6')
		--s6n;
		
	if(s6n != 0)
		return	(fact(s6n)/(fact(2)*fact(s6n-2)));
	else
		return 0;
}


//String valve sum
int svsum(string s)
{
	int num_s = 0;
	for(int i=0; i<s.length() ; i++)
		num_s *= (((int)s[i] - (int)'0'))*pow(10,i);
	return num_s;		
}

//factorial
int fact(int num)
{
	int sum = 1;
	for(int i=1;i<=num;i++)
	{
		sum*=i;
	}
	return sum;
}