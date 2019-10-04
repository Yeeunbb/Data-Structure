#include <stdio.h>

long long factorial (int n);
int combination (int n, int r);

int main()
{
	int n, x, y;

	printf("n? ");
	fflush(stdout);
	scanf("%d", &n);

	for (y=0; y<n; y++)
	{
		for (x=0; x<=y; x++)
		{
			if(combination(y,x)<10)
			{
				printf("     ");
				printf("%d",combination(y,x));
			}
			else if(combination(y,x)>=10&&combination(y,x)<100)
			{
				printf("    ");
				printf("%d",combination(y,x));
			}
			else if(combination(y,x)>=100&&combination(y,x)<1000)
			{
				printf("   ");
				printf("%d",combination(y,x));
			}
			else
			{
				printf("  ");
				printf("%d",combination(y,x));
			}
		}
		printf("\n");
	}

	return 0;
}

long long factorial (int n)
{
	int i;
	long long fact=1;

	for(i=1; i<=n; i++)
	{
		fact=fact*i;
	}

	return fact;
}

int combination (int n, int r)
{
	return factorial(n)/(factorial(n-r)*factorial(r));
}
