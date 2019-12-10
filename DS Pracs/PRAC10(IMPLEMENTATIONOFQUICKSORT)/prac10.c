/*
  TITLE: IMPLEMENTATION OF QUICK SORT.
  NAME:Tauseef Mushtaque Ali Shaikh
  CLASS: S.Y.[CO]
  ROLLNO: 18CO63
  SUBJECT: DS
  DATE: 7/10/19
  DISCRIPTION: In this Program quick sort operation is carried out.
*/
#include<stdio.h>
#include<stdlib.h>
int partition(int a[],int low,int high)
{
	int pivot,i,j,k;
	pivot=a[low];
	i=low;
	j=high;
	while(i<j)
	{
		while(a[i]<=pivot && i<high)
		i++;
		while(a[j]>=pivot && j>low)
		j--;
		if(i<j)
		{
			k=a[i];
			a[i]=a[j];
			a[j]=k;
		}
	}
	a[low]=a[j];
	a[i]=pivot;
	return j;
}

void quicksort(int a[],int low,int high)
{
	int p,i;
	if(low<high)
	{
		printf("\n\nLow=%d\nHigh=%d",low,high);
		for(i=low;i<=high;i++)
		printf("\t%d",a[i]);
		p=partition(a,low,high);
		quicksort(a,low,p-1);
		quicksort(a,p+1,high);
	}
}

int main()
{
	int a[20],n,i;
	printf("Enter total Number of element:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the Elements:");
		scanf("%d",&a[i]);
	}
	quicksort(a,0,n-1);
	printf("\n\nSorted List contents is: \n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}

