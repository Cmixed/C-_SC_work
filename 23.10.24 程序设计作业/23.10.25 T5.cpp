#include <iostream>
using namespace std;
int main(void)
{
	int m=0, n=0, num=0;
	cin >> m >> n;
	for(int i=m;i<=n;i++)
		if((i%4==0 && i%100!=0) || i%400==0)
			++num;
	cout << num;
}