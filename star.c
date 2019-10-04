#include <stdio.h>
int main()
{
	int i,x,y,z;

	for(i=1; i<=5; i++)//Q1
	{
		printf("*");
	}

	printf("\n\n");

	for(i=1; i<=5; i++)//Q2
	{
		printf("*\n");
	}

	printf("\n\n");

	for(y=1; y<=5; y++)//Q3
	{
		for(x=1; x<=5; x++)
		{
			printf("*");
		}
		printf("\n");
	}

	printf("\n\n");

	for(y=1; y<=5; y++)//Q4
	{
		for(x=1; x<=5; x++)
		{
			printf("%d",y);
		}
		printf("\n");
	}

	printf("\n\n");

	for(y=1; y<=5; y++)//Q5
	{
		for(x=1; x<=5; x++)
		{
			printf("%d", x);
		}
		printf("\n");
	}

	printf("\n\n");

	for(y=1; y<=5; y++)//Q6
	{
		for(x=1; x<=5; x++)
		{
			printf("%d", x+y-1);
		}
		printf("\n");
	}

	printf("\n\n");

	for(y=5; y>=1; y--)//Q7
	{
		for(x=1; x<=5; x++)
		{
			printf("%d", y+x-1);
		}
		printf("\n");
	}

	printf("\n\n");

	for(y=1; y<=5; y++)//Q8
	{
		for(x=1; x<=y; x++)
		{
			printf("*");
		}
		printf("\n");
	}

	printf("\n\n");

	for(y=5; y>=1; y--)//Q9
	{
		for(x=1; x<=y; x++)
		{
			printf("*");
		}
		printf("\n");
	}

	printf("\n\n");

	for(y=1; y<=5; y++)//Q10
	{
		for(x=1; x<y; x++)
		{
			printf(" ");
		}
		for(z=5; z>y-1; z--)
		{
			printf("*");
		}
		printf("\n");
	}

	printf("\n\n");

	for(y=5; y>=1; y--)//Q11
	{
		for(x=1; x<y; x++)
		{
			printf(" ");
		}
		for(z=5; z>=y; z--)
		{
			printf("*");
		}
		printf("\n");
	}

	printf("\n\n");

	for(y=1; y<=5; y++)//Q12
	{
		for(x=1; x<=y; x++)
		{
			printf("*");
		}
		printf("\n");
	}
	for(z=4; z>=1; z--)
	{
		for(x=1; x<=z; x++)
		{
			printf("*");
		}
		printf("\n");
	}

	printf("\n\n");

	for(y=5; y>=1; y--)//Q13
	{
		for(x=1; x<=y; x++)
		{
			printf("*");
		}
		printf("\n");
	}
	for(z=2; z<=5; z++)
	{
		for(x=1; x<=z; x++)
		{
			printf("*");
		}
		printf("\n");
	}

	printf("\n\n");

	for(y=1; y<=5; y++)//Q14
	{
		for(z=1; z<y; z++)
		{
			printf(" ");
		}
		for(x=5; x>=y; x--)
		{
			printf("*");
		}
		printf("\n");
	}
	for(y=2; y<=5; y++)
	{
		for(z=3; z>=y-1; z--)
		{
			printf(" ");
		}
		for(x=1; x<=y; x++)
		{
			printf("*");
		}
		printf("\n");
	}

	printf("\n\n");

	for(y=1; y<=5; y++)//Q15
	{
		for(z=4; z>=y; z--)
		{
			printf(" ");
		}
		for(x=1; x<=y; x++)
		{
			printf("*");
		}
		printf("\n");
	}
	for(y=4; y>=1; y--)
	{
		for(z=5; z>y; z--)
		{
			printf(" ");
		}
		for(x=1; x<=y; x++)
		{
			printf("*");
		}
		printf("\n");
	}

	printf("\n\n");

	for(y=1; y<=5; y++)//Q16
	{
		for(z=5; z>y; z--)
		{
			printf(" ");
		}
		for(x=1; x<=2*y-1; x++)
		{
			printf("*");
		}
		printf("\n");
	}

	printf("\n\n");

	for(y=1; y<=5; y++)//Q17
	{
		for(z=1; z<y; z++)
		{
			printf(" ");
		}
		for(x=9; x>=2*y-1; x--)
		{
			printf("*");
		}
		printf("\n");
	}

	printf("\n\n");

	for(y=1; y<=5; y++)//Q18
	{
		for(z=4; z>=y; z--)
		{
			printf(" ");
		}
		for(x=1; x<=2*y-1; x++)
		{
			printf("*");
		}
		printf("\n");
	}
	for(y=1; y<=4; y++)
	{
		for(z=0; z<y; z++)
		{
			printf(" ");
		}
		for(x=7; x>=2*y-1; x--)
		{
			printf("*");
		}
		printf("\n");
	}

	printf("\n\n");

	for(y=1; y<=5; y++)//Q19
	{
		for(x=5; x>=y; x--)
		{
			printf("*");
		}
		for(z=1; z<=2*y-1; z++)
		{
			printf(" ");
		}
		for(x=5; x>=y; x--)
		{
			printf("*");
		}
		printf("\n");
	}
	for(y=2; y<=5; y++)
	{
		for(x=1; x<=y; x++)
		{
			printf("*");
		}
		for(z=9; z>=2*y-1; z--)
		{
			printf(" ");
		}
		for(x=1; x<=y; x++)
		{
			printf("*");
		}
		printf("\n");
	}

	printf("\n\n");

	for(y=1; y<=5; y++)//Q20
	{
		for(x=1; x<=y; x++)
		{
			printf("*");
		}
		for(z=9; z>=2*y-1; z--)
		{
			printf(" ");
		}
		for(x=1; x<=y; x++)
		{
			printf("*");
		}
		printf("\n");
	}
	for(y=1; y<=4; y++)
	{
		for(x=4; x>=y; x--)
		{
			printf("*");
		}
		for(z=1; z<=2*(y+1)-1; z++)
		{
			printf(" ");
		}
		for(x=4; x>=y; x--)
		{
			printf("*");
		}
		printf("\n");
	}

	printf("\n\n");

	for(y=1; y<=5; y++)//Q21
	{
		for(z=1; z<=y; z++)
		{
			printf(" ");
		}
		for(x=9; x>=2*y-1; x--)
		{
			printf("*");
		}
		printf("\n");
	}
	for(y=1; y<=4; y++)
	{
		for(z=4; z>=y; z--)
		{
			printf(" ");
		}
		for(x=1; x<=2*(y+1)-1; x++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

