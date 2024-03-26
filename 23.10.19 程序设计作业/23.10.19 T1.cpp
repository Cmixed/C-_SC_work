#include <iostream>
using namespace std;

int main()
{
	int a, b, c, min, mid, max;
	a = b = c = min = 0;
	cin >> a >> b >> c;
    min = a;
    //for min
    if(a<b && a<c)
        min = a;
    else if(b<a && b<c)
        min = b;
    else
        min = c;
    //for mid
    if((a>b && a<c) || (a<b && a>c))
    	mid = a;
	else if((b>a && b<c)||(b<a && b>c))
		mid = b;
	else
		mid = c;
	//for max
	if(a>b && a>c)
    	max = a;
	else if(b>a && b>c)
		max = b;
	else
		max = c;
    
	if(min==mid-1 && max==mid+1)
		cout << "TRUE";
	else
		cout << "FALSE";
		
	return 0;
}