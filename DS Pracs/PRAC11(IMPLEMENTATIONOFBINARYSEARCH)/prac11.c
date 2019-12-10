/*
  TITLE:IMPLEMENT BINARY SEARCH.
  NAME:Tauseef Mushtaque Ali Shaikh
  CLASS: S.Y.[CO]
  ROLLNO: 18CO63
  SUBJECT: DS
  DATE: 7/10/19
  DISCRIPTION: In this Program binary search is implemented.
*/
#include<stdio.h>
int binarySer(int a[], int n, int k)
{
int low, upper, mid;
low=0;
upper=n-1;
for(mid=(low+upper)/2; low<=upper; mid=(low+upper)/2)
{
	if(k==a[mid])
		return mid;
	if(k>a[mid])
		low=mid+1;
	else
		upper=mid-1;
}
return -1;
}

int main()
{
	int a[20], n, i, k;
	printf("\nENTER TOTAL NO. OF ELEMENTS: ");
	scanf("%d", &n);
	printf("\n\tENTER ELEMENTS IN SORTED ORDER: \n");
	for(i=0;i<n;i++)
	{
		printf("ELEMENT %d = ", i);
		scanf("%d", &a[i]);
	}
	printf("\n\tENTER KEY ELEMENT TO SEARCH: ");
	scanf("%d", &k);
	i=binarySer(a,n,k);
	if(i==-1)
		printf("\nKEY ELEMENT DOES NO EXIST!");	
	else
		printf("\nKEY ELEMENT EXIST AT LOCATION %d", i);	
}
