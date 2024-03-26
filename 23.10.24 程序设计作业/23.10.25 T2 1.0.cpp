#include <iostream>
#include <string>
#include <cmath>

//for function
int svsum(std::string s);
int fact(int num);

int main()
{
	std::string s;
	int a;
	std::cin >> a;
	std::cin >> s;
	int s6n = s.length();
//	cout << svsum(s) << endl;
	if(svsum(s) < svsum("66"))
	{
		std::cout << 'N';
		goto End;
	}
	else if(s[0]<'6')
		--s6n;
	
	std::cout << int(fact(s6n)/(fact(2)*fact(s6n-2)));
End:
	return 0;
}

//String valve sum
int svsum(std::string s)
{
	int num_s = 0;
	for(int i=0; i<s.length() ; i++)
		num_s += (((int)s[i] - (int)'0'))*pow(10,i);
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