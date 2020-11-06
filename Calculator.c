
/*
*
*	Simple Calculator
*
*/

#include <stdio.h>
#include <Math.h>



// Factorial Method
int factorial(int x)
{	
	int fact = 1;
	for(int i=1; i<=x; i++)
	{
		fact = fact * i;
	}

	return fact;
}

int main()
{
    float a,b;
	int op;
	int x,y;

	printf("\n  Choose an Option\n");
	printf("======================\n");
	printf("Enter 1 for +\n");
	printf("Enter 2 for -\n");
	printf("Enter 3 for *\n");
	printf("Enter 4 for /\n");
	printf("Enter 5 for %\n");
	printf("Enter 6 for cos(x)\n");
	printf("Enter 7 for sin(x)\n");
	printf("Enter 8 for tan(x)\n");
	printf("Enter 9 for ln(x)\n");
	printf("Enter 10 for factorial\n\n");

	printf("Option = ");
	scanf("%d",&op);

	if(op != 10){
		printf("\nEnter 1st number = ");
		scanf("%f",&a);
	}
	else{
		printf("\nEnter number = ");
		scanf("%d",&x);
	}


	if(op == 1 || op == 2 || op == 3 || op == 4 || op == 5 )
	{
		printf("Enter 2nd number = ");
		scanf("%f",&b);
	}

	printf("\n");
	switch(op)
	{
		case 1:
			printf("a + b = %f\n", a+b);
			break;
		case 2:
			printf("a - b = %f\n", (a-b));
			break;
		case 3:
			printf("a * b = %f\n", a*b);
			break;
		case 4:
			printf("a / b = %f\n", (a/b));
			break;
		case 5:
			x = a;
			y = b;
			printf("a % b = %d\n", x%y);
			break;
		case 6:
			printf("cos(x) = %f\n", cos(a));
			break;
		case 7:
			printf("sin(x) = %f\n", sin(a));
			break;
		case 8:
			printf("tan(x) = %f\n", tan(a));
			break;
		case 9:
			printf("ln(x) = %f\n", log(a));
			break;
		case 10:
			printf("%d! = %d\n", x, factorial(x));
			break;
		default:
			printf("Wrong option");
			break;
	}


    return 0;

}
