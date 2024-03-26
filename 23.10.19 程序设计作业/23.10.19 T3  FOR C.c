#include <stdio.h>

int main()
{
	int a,b;
	scanf("%d%*c%d", &a, &b);
	
	switch(b)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: printf("31");
				 break;
		case 2:  if(0 == a%4) printf("29");
				   else printf("28");
				 break;
		case 4:
		case 6:
		case 9:
		case 11: printf("30");
				 break;
				 
		default : printf("Unreasonable input");
	}
	return 0;
}