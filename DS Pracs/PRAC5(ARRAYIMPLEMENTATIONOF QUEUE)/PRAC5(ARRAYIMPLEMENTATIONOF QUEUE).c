/*
  TITLE:ARRAY IMPLEMENTATION OF LINEAR QUEUE
  NAME:Tauseef Mushtaque Ali Shaikh
  CLASS: S.Y.[CO]
  ROLLNO: 18CO63
  SUBJECT: DS
  DATE: 26/8/19
  DISCRIPTION: In this Program a linaer queue is created to store, search the location of data in queue, delete and display the data through the instructions given by the user.
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 5

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
	return (q->Front=q->Rear==-1);
}

int isFull(struct Queue *q)
{
	return (q->Rear==(MAX-1)?1:0);
}

int Insert(struct Queue *q,int d)
{
	if(isFull(q))
	return 0;
	q->data[++q->Rear]=d;
	if(q->Front==-1)
	q->Front=0;
	return 1;
}

void Display(struct Queue *q)
{
	int i;
	if(isEmpty(q))
	printf("\n\t Queue is Empty!");
	else
	{
		printf("\n Queue contents are:\n");
		printf("\n Queue Size : %d\n Front : %d\n Rear :%d\n",MAX,q->Front,q->Rear);
		for(i=q->Front;i<=q->Rear;i++)
		{
			printf("%d\n",q->data[i]);
		}
	}
}

int Delete(struct Queue *q)
{
	int d;
	d=q->data[q->Front];
	if(q->Front==q->Rear)
	q->Front=q->Rear=-1;
	else
	q->Front++;
	return d;
}

int Search(struct Queue *q,int k)
{
	int i=0;
	for(i=q->Front;i<=q->Rear;i++)
	if(q->data[i]==k)
	return i;
	return -1;
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
			if(isEmpty(&q))
			printf("\n QUEUE IS EMPTY!");
			else
			printf("\n DELETED ELEMENT IS: %d",Delete(&q));
			break;
			
			case 3:
			printf("\n ENTER THE ELEMENT FOR SEARCH: ");
			scanf("%d",&d);
			d=Search(&q,d);
			if(d==-1)
			printf("\n QUEUE IS EMPTY!\n");
			else
			printf("THE ELEMENT SEARCHED IS: %d",d);
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

	
