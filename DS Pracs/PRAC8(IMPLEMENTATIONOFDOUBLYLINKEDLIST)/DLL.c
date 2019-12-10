/*
  TITLE:IMPLEMENTATION OF DOUBLY LINKED LIST
  NAME:Tauseef Mushtaque Ali Shaikh
  CLASS: S.Y.[CO]
  ROLLNO: 18CO63
  SUBJECT: DS
  DATE: 23/9/19
  DISCRIPTION: In this Program a doubly linked list is created and different function is performed i.e. insert, remove, display.
*/
#include<stdio.h>
#include<stdlib.h>

struct DLL
{
int data;
struct DLL *next, *prev;
};

struct DLL *insertAtEnd(struct DLL *h,int d)
{
	struct DLL *p,*tmp;
	p=(struct DLL *)malloc(sizeof(struct DLL));
	p->data=d;
	p->next=NULL;
	p->prev=NULL;
	if(h==NULL)
	{ 
		h=p;
	}
else
{ 
tmp=h;
while(tmp->next!=NULL)
tmp=tmp->next;
tmp->next=p;
p->prev=tmp;
}
return h;
}

struct DLL *insertAtStart(struct DLL *h,int d)
{
struct DLL *p;
p=(struct DLL *)malloc(sizeof(struct DLL));
p->data=d;
p->next=h;
p->prev=NULL;
if(h!=NULL)
h->prev=p;
h=p;
return h;
}

struct DLL *insertAfter(struct DLL *h,int key,int d)
{
struct DLL *p,*tmp;
p=(struct DLL *)malloc(sizeof(struct DLL));
p->data=d;
p->next=NULL;
p->prev=NULL;
if(h==NULL)
{
h=p;
}
else
{ 
tmp=h;
while(tmp!=NULL && tmp->data!=key )
tmp=tmp->next;
if(tmp!=NULL)
{
p->next=tmp->next;
p->prev=tmp;
if(tmp->next!=NULL)
(tmp->next)->prev=p;
tmp->next=p;
}
else
printf("\n\tGiven Node %d does not exist in the Linked List.",key);
}
return h;
}

struct DLL *removelast(struct DLL *h)
{
struct DLL *tmp;
tmp=h;
if(h!=NULL)
{
if(h->next!=NULL)
{
while(tmp->next!=NULL)
tmp=tmp->next;
(tmp->prev)->next=NULL;
}
else
h=NULL;
free(tmp);
}
else
printf("\nLL is empty.");
return h;
}

struct DLL *removeAfter(struct DLL *h,int key)
{
struct DLL *tmp,*p;
tmp=h;
if(h!=NULL)
{
while(tmp!=NULL && tmp->data!=key)
tmp=tmp->next;
if(tmp!=NULL)
{
if(tmp->next!=NULL)
{
p=tmp->next;
if(p->next!=NULL)
(p->next)->prev=tmp;
tmp->next=p->next;
p->next=NULL;
p->prev=NULL;
free(p);
}
else
printf("\nGiven Node is the last Node.");
}
else
printf("\nGiven key does not exist.");
}
else
printf("\nLL is empty.");
return h;
}

void display(struct DLL *h)
{
struct DLL *tmp;
tmp=h;
if(h!=NULL)
{
printf("\n\n\t\tLinked List Contents..\n");
while(tmp!=NULL)
{
printf("\t%d\n",tmp->data);
tmp=tmp->next;
}
}
else
printf("\nLL is empty.");
}

void displayRev(struct DLL *h)
{
struct DLL *tmp;
tmp=h;
if(h!=NULL)
{
printf("\n\n\t\tLinked List Contents in Reverse Order..\n");
while(tmp->next!=NULL)
tmp=tmp->next;
do
{
printf("\t%d\n",tmp->data);
tmp=tmp->prev;
}while(tmp!=NULL);
}
else
printf("\nLL is empty.");
}

int main()
{
			struct DLL *head;
			int ch,d,k;
			head=NULL;
			while(1)
		{
			
			printf("\n\t\tMENU");
			printf("\n\n1. INSERT AT END\n2. INSERT AFTER\n3. INSERT AT START\n4. REMOVE FROM LAST\n5. REMOVE AFTER\n6. DISPLAY\n7. DISPLAY REVERSE\n0. EXIT\n");
			printf("\nENTER THE CHOICE: ");
			scanf("%d",&ch);
			
			switch(ch)
			{
				case 1:
				printf("\nEnter the element to be insert: ");
				scanf("%d",&d);
				head=insertAtEnd(head,d);
				break;
				
				case 2:
				printf("Enter the KEY: ");
				scanf("%d",&k);
				printf("\nEnter the element to be insert: ");
				scanf("%d",&d);
				head=insertAfter(head,k,d);
				break;
				
				case 3:
				printf("\nEnter the element to be insert: ");
				scanf("%d",&d);
				head=insertAtStart(head,d);
				break;
				
				case 4:
				head=removelast(head);
				break;
				
				case 5:
				printf("Enter the KEY: ");
				scanf("%d",&k);
				head=removeAfter(head,k);
				break;
				
				case 6:
				display(head);
				break;
				
				case 7:
				displayRev(head);
			
				case 0:
				exit(0);
				break;
				
				default:
				printf("INVALID CHOICE!!");
				
			}
			
			
}
		return 0;			
			}
