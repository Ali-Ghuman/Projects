#include <stdio.h>
#include <math.h>

int main()
{
	int n = 0;
	

	while (n > 100000 || n < 2)
	{
		printf("Enter a number between 2 to 1000000: ");
		scanf("%d", &n);
	}


	for (int i = 2, x = sqrt(n); i < x; i++)
	{
		while (n % i == 0)
		{
			n /= i;
			if (n == 1)
			{
				printf("%d\n", i);
				return 0; 
			}
			printf("%d * ", i);
		}	
	}
	printf("%d\n", n);
		
}

