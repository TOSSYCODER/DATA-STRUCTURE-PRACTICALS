/*
 Titttle:- Implement a Menu Driven program of Factorial, Fibonacci and Palindrome by using switch case by implementing function
 Name:- TAUSEEF MUSHTAQUE ALI SHAIKH
 Roll no.:- 18CO63
 Class:- S.Y. [CO]
 Date:- 15-07-2019
 DISCRIPTION:- In This Program a menu based implementation is held for some actions such as Fuctions, Fibonacci Series and Palindrome of a Word/name (String) using functions made for an individual action to be performed.
 */
#include <stdio.h>
#include <string.h>
 int fact(int num)
{
	int i,fact=1;
	for ( i = 1; i <= num; i++)
	{
		fact=fact*i;
	}
	printf("\nfactorial of a number %d is:%d\n",num,fact);
	return(fact);
}

 int fibo(int number)
{
	int a=0,b=1,fibo;
	printf("\n%d\t%d",a,b);
	
	for ( int i = 0; i < number-2; i++)
	{
		fibo=a+b;
		a=b;
		b=fibo;
		printf("\t%d",fibo);
	}
	printf("\n");

	return(fibo);
}

void Pal(char str[50])
{
	int len,i;
	int flag=0;
	len =strlen(str);
	for (i = 0; i < len; i++)
	{
		if (str[i]!=str[len-i-1])
        {
            flag=1;
            break;
        }
	}
	if (flag)
	{
		printf("The %s is not a palindrome\n",str );
	}
	else
	{
		printf("The %s is a palindrome\n",str);
	}
}

int main()
{
	int n,num,number;
	char str[50];
	while(1)
	{
		printf("\nEnter the choice\n1.Find Factorial\n2.Find Fibonacci\n3.Find Palindrome\n0.Exit\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("\nEnter a number for it's Factorial: ");
				scanf("%d",&num);
				fact(num);
				break;
			case 2:
				printf("\nEnter the range for Fibonacci Series: ");
				scanf("%d",&number);
				fibo(number);
				break;
			case 3:
				printf("\nEnter a string to know it's a Palindrome or not:");
				scanf("%s",str);
				Pal(str);
				break;
			case 0:
				printf("\nExiting the program\n");
				return(0);
				break;
			default:
				printf("\nInput error\nEnter a VALID no.\n");
		}
	}
}
