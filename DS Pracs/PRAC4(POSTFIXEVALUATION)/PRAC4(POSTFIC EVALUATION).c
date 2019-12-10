/*
  TITLE: Evaluation of Postfix Expression
  NAME:Tauseef Mushtaque Ali Shaikh
  CLASS: S.Y.[CO]
  ROLLNO: 18CO63
  SUBJECT: DS
  DATE: 19/8/19
  DISCRIPTION: In this Program a Postfix Expression is Evaluated and Result is Stored in a Stack.
*/

#include<stdio.h>
#include<stdlib.h>
#define max 50

struct stack
{
int data[max];
int top;
};

int empty(struct stack *s)
{
	return (s->top==-1)?1:0;
}

void push(struct stack *s,int ele)
{
	if (s->top < max-1)
	s->data[++s->top]=ele;
	else
	printf("\nSTACK OVERFLOW");
}

int pop(struct stack *s)
{
	if(!empty(s))
	return s->data[s->top--];
	else
	return (int)-1;
}

int eval(char *expr)
{
char c;
int i,res,op2;
struct stack st;
st.top=-1;
for(i=0;expr[i]!='\0';i++)
 { 
	 c=expr[i];
	 switch(c)
		{
			case '+':
			op2=pop(&st);
			res=pop(&st)+op2;
			push(&st,res);
			break;
			
			case '-':
			op2=pop(&st);
			res=pop(&st)-op2;
			push(&st,res);
			break;
			
			case '*':
			op2=pop(&st);
			res=pop(&st)*op2;
			push(&st,res);
			break;
			
			case '/':
			op2=pop(&st);
			res=pop(&st)/op2;
			push(&st,res);
			break;
			
			case '%':
			op2=pop(&st);
			res=pop(&st)%op2;
			push(&st,res);
			break;
			
			
			case '$':
			op2=pop(&st);
			res=pow(pop(&st),op2);
			push(&st,res);
			break;
			
			case '0':
			exit(0);
			break;
			
			default:
			push(&st,c-'0');
			
		}
 }
 return pop(&st);	
}

int main()
{
	while(1)
	{
	char *postfix;
		int res;
		postfix=(char*)malloc(1);
		printf("\nEnter postfix Expression:");
		scanf("%s",postfix);
		res=eval(postfix);
		printf("\n Evalution to Postfix Expression is : %d\n",res);
		printf("\nEnter 0 to exit the program\n");
	}
}


