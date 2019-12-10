/*
  TITLE:IMPLEMENTATION OF SINGLY LINKED LIST
  NAME:Tauseef Mushtaque Ali Shaikh
  CLASS: S.Y.[CO]
  ROLLNO: 18CO63
  SUBJECT: DS
  DATE: 16/9/19
  DISCRIPTION: In this Program a singly linked list is created and different function is performed i.e. insert, remove, display.
*/
#include<stdio.h>
#include<stdlib.h>
struct sll
{
int data;
struct sll *next;
};
struct sll *einsert(struct sll *h, int d)
{
	struct sll *p, *temp;
	p=(struct sll*)malloc(sizeof(struct sll));
	if(p==NULL)
	{
		printf("\n NOT ENOUGH SPACE!\nNODE CANNOT BE INSERTED\n");
		return h;
		}
		p->data=d;
		p->next=NULL;
		if(h==NULL)
		{
			h=p;
			}
		else
		{
			temp=h;
			while(temp->next!=NULL)
			temp=temp->next;
			temp->next=p;
			}
	return h;			
	}

struct sll *sinsert(struct sll *h, int d)
{
	struct sll*p;
	p=(struct sll*)malloc(sizeof(struct sll));
	p->data=d;
	p->next=h;
	h=p;
	return h;
	}	

struct sll *ainsert(struct sll *h, int key, int d)
{
	struct sll *p, *temp;
	p=(struct sll*)malloc(sizeof(struct sll));
	p->data=d;
	p->next=NULL;
	if(h==NULL)
	{
		h=p;
		}
	else
	{
		temp=h;
		while(temp!=NULL && temp->data!=key)
		temp=temp->next;
		if(temp!=NULL)
		{
			p->next=temp->next;
			temp->next=p;
			}
			else 
			{
				printf("\nGIVEN NODE %d DOES NOT EXIST IN THE LINKED LIST!", key);
				free(p);
				}
		}
		return h;	
	}	
	
struct sll *lremove(struct sll *h)
{
	struct sll *temp, *prev;
	temp=h;
	if(h!=NULL)
	{
		if(h->next!=NULL)
		{
			while(temp->next!=NULL)
			{
				prev=temp;
				temp=temp->next;
			}
			prev->next=NULL;
		}
		else
		{
		h=NULL;
		free(temp);
		}
	}
		else
		{
		printf("\nLINK LIST IS EMPTY!");
		return h;
		}
	return h;	
}
	
struct sll *fremove(struct sll *h)
{
	struct sll *temp;
	temp=h;
	if(h!=NULL)
	{
		h=h->next;
		free(temp);
		}
	else
	{
		printf("\nLINK LIST IS EMPTY!");
	}
		return h;	
	}		

struct sll *aremove(struct all*h, int key)
{
	struct sll *temp, *p;
	temp=h;
	if(h!=NULL)
	{
	while(temp!=NULL && temp->data!=key)
	{
		temp=temp->next;
		}	
	if(temp!=NULL)
	{
	if(temp->next!=NULL)
	{
	p=temp->next;
	temp->next=temp->next;
	p->next=NULL;
	free(p);
		}
	else
	{
		printf("\nGIVEN NODE IS THE LAST NODE!");
		}		
		}
	else
	{
		printf("\nGIVEN KEY DOES NOT EXIST!");
		}		
	}
	else
	{
		printf("\nLINKED LIST IS EMPTY!");
		}
	return h;
}

void display(struct sll *h)
{
	struct sll *temp;
	temp=h;
	if(h!=NULL)
	{
		printf("\nLINKED LIST CONTENTS ARE:\n");
		while(temp!=NULL)
		{
			printf("\n%d\t", temp->data);
			temp=temp->next;
			}
		}
		else
		{
			printf("\nLINKED LIST IS EMPTY!");
			}
	}

int main()
{
	struct sll *head;
	int ch,d,key;
	head=NULL;
	while(1)
	{
	printf("\n\tMENU\n1.INSERT AT START\n2.INSERT AT END\n3.INSERT AFTER\n4.REMOVE FROM START\n5.REMOVE FROM END\n6.REMOVE AFTER\n7.DISPLAY\n0.EXIT");
    printf("\nEnter your choice::\n");
    scanf("%d",&ch);
    switch(ch)
    {
		case 1:
		{
			printf("\nENTER DATA: ");
			scanf("%d",&d);
			head=sinsert(head,d);
			break;
			}
		case 2:
		{
			printf("\nENTER DATA: ");
			scanf("%d",&d);
			head=einsert(head,d);
			break;
			}
		case 3:
		{
			printf("\nENTER DATA: ");
			scanf("%d",&d);
			printf("\nENTER KEY: ");
			scanf("%d",&key);
			head=ainsert(head,key,d);
			break;
			}
			case 4:
		{
			head=fremove(head);
			break;
			}
			case 5:
		{
			head=lremove(head);
			break;
			}
		case 6:
		{
			printf("\nENTER KEY: ");
			scanf("%d",&d);
			head=aremove(head,d);
			break;
			}
		case 7:
		{
			display(head);
			}
		case 0:
		{
		exit(0);
			}
		default:
		{
			printf("\nCHOOSE A VALID OPTION!");
			}
		}
	}
	}
