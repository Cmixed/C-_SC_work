#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;

int main()
{
	double metre, hour, minute, second, sum;
	
	cin >> metre >> hour >> minute >> second;
	cout << setprecision(4) << (metre / ((hour*60) + minute + (second/60)));
	
	return 0;
}