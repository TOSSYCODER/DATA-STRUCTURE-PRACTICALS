/*
  TITLE:ARRAY IMPLEMENTATION OF CIRCULAR QUEUE
  NAME:Tauseef Mushtaque Ali Shaikh
  CLASS: S.Y.[CO]
  ROLLNO: 18CO63
  SUBJECT: DS
  DATE: 9/9/19
  DISCRIPTION: In this Program a Circular queue is created to store, search the location of data in queue, delete and display the data through the instructions given by the user.
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 7

struct Queue
{
	int data[MAX];
	int Front,Rear;
};

void initialize (struct Queue *q)
{
	q->Rear=q->Front=-1;
}

int isEmpty(struct Queue *q)
{
	return (q->Rear==-1);
}

int isFull(struct Queue *q)
{
	return (q->Front==((q->Rear+1)%MAX))?1:0;
}
int Insert(struct Queue *q,int d)
{
	if(isFull(q))
	return 0;
	else
	{
		q->Rear=(q->Rear+1)%MAX;
		q->data[q->Rear]=d;
		if(q->Front==-1)
		q->Front=0;
		return 1;
	}
}
int Delete(struct Queue *q)
{
	if(q->Rear==-1)
	printf("\n\t Queue is Empty!");
	else
	{
		int m;
		m=q->data[q->Front];
		if(q->Front==q->Rear)
		q->Front=q->Rear=-1;
		else
		q->Front=(q->Front+1)%MAX;
		printf("\n\t Element Deleted From Queue!");
	}
}
int Search(struct Queue *q,int k)
{
	int i=0;
	for(i=q->Front;i!=q->Rear;i=(i+1)%MAX)
	if(q->data[i]==k)
	return i;
	if(q->data[i]==k)
	return i;
	return -1;
}
void Display(struct Queue *q)
{
	int i;
	if(q->Rear==-1)
	printf("\n\t Queue is Empty!");
	else
	{
		printf("\n Queue contents are:\n");
		for(i=q->Front;i!=q->Rear;i=(i+1)%MAX)
		{
			printf("%d\n",q->data[i]);
		}
		printf("%d\n",q->data[i]);
	}
}
int main()
{
	int ch,d;
	struct Queue q;
	initialize(&q);
    while(1)
    {
		printf("\n\t\t\tMENU\n1.INSERT\n2.DLELETE\n3.SEARCH\n4.DISPLAY\n0.EXIT\n");
	printf("ENTER YOUR CHOICE: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("ENTER DATA TO BE INSERTED: ");
			scanf("%d",&d);
			Insert(&q,d);
			printf("\n DATA INSERTION SUCCESFULLY!");
			break;
			
			case 2:
			Delete(&q);
			break;
			
			case 3:
			printf("\n ENTER THE ELEMENT FOR SEARCH: ");
			scanf("%d",&d);
			d=Search(&q,d);
			if(d==-1)
			printf("\nTHE ELEMENT IS NOT FOUND!\n");
			else
			printf("THE ELEMENT IS FOUND IS AT %d",d);
			break;
			
			case 4:
			Display(&q);
			break;
			
			case 0:
		    exit(0);
		    break;

		    
		    default:
		    printf("ENTER A VALID CHOICE");
		}
	}
}
