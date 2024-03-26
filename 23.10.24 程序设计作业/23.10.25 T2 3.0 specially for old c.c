#include <stdio.h>
int ifprefect(int n);

int main()
{
	int array[10];
	int storage[10];
	int t; //line number
	int i; //initialization is not allowed in old standard
//processing input
	scanf("%d", &t);
	for(i=0; i<t; i++)
		scanf("%d", &array[i]);

	for(i=0; i<t; i++)
		storage[i] = ifprefect(array[i]);
		
//	printf("line20\n");
	for(i=0; i<t; i++)
		printf("%d\n", storage[i]);
//	printf("line23\n");
	
	return 0;
}


int ifprefect(int n)
{
	if(n<66)
		return 0;
		
	int total = 0;
	int i; //initialization is not allowed in old standard
	for(i=66;i<=n;i++) {
		int m = i;
//		printf("line34 %d\n", m);
		int count = 0; //each 6 num
		while(m){
			if(m%10==6) 
				count++;
			m /= 10;	
		}
		if(count==2)
			total++;
	}
	return total;
}