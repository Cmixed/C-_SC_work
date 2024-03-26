#include <iostream>
using namespace std;
bool if_primer_number(int n);
int main()
{
	int num;
	cin >> num;
	int ar[100], an = 0;
	for(int i=1; i<=num; i++) {
		if(if_primer_number(i)) {
			ar[an] = i;
			an++;
		}
	}
	for(int i=1; i<an; i++) {
		if(ar[i+1]==ar[i]+2)
			cout << ar[i] << ' ' << ar[i+1] << endl;
	}

	return 0;
}

bool if_primer_number(int n)
{
	int count = 0;
	for(int i=2; i<=n/2; i++)
		if(n%i==0)
			count++;
	if(count==0)
		return 1;
	else
		return 0;
}

