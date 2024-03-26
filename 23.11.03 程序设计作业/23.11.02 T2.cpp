#include <iostream>
#include <string>

int main()
{
	std::string s;
	std::cin >> s;

	int count=0;//how many 0 have in the end
	for(long i=(s.length()-1-count); i>=0; i--)
		if(s[i]=='0')
			count++;
		else
			break;

	for(long i=(s.length()-1-count); i>=0; i--) 
		std::cout << s[i];
		
	return 0;
}