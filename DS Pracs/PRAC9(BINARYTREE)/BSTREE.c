/*
  TITLE:IMPLEMENT BINARY SEARCH TREE
  NAME:Tauseef Mushtaque Ali Shaikh
  CLASS: S.Y.[CO]
  ROLLNO: 18CO63
  SUBJECT: DS
  DATE: 30/9/19
  DISCRIPTION: In this Program binary search is implemented i.e. inorder, preorder, postorder.
*/
#include<stdio.h>
#include<stdlib.h>

struct bstree
{
int data;
struct bstree *left,*right;
};

struct bstree *insert(struct bstree *root, int d)
{
struct bstree *p;
if(root==NULL)
{
p=(struct bstree *)malloc(sizeof(struct bstree));
p->data=d;
p->left=NULL;
p->right=NULL;
root=p;
}
else
{
if(d<root->data)
root->left=insert(root->left,d);
else
root->right=insert(root->right,d);
}
return root;
}

void preorder(struct bstree *r)
{
	if(r!=NULL) 
	{
		printf("\n%d",r->data);
		preorder(r->left);
		preorder(r->right);
		}
}

void inorder(struct bstree *r)
{
	if(r!=NULL)
	{
		inorder(r->left);
		printf("\n%d",r->data);
		inorder(r->right);
		}
}

void postorder(struct bstree *r)
{
	if(r!=NULL)
	{
		postorder(r->left);
		postorder(r->right);
		printf("\n%d",r->data);
		}
}
	
struct bstree *search(struct bstree *root, int key)
{
	if(root!=NULL)
	{
		if(key==root->data)
		return root;
		else
		{
			if(key<root->data)
			root->left=search(root->left,key);
			else
			root->right=search(root->right,key);
			}
		}
	else
	return NULL;
}	

int main()
{
	int ch,d;
	struct bstree *p, *root=NULL;
	while(1)
	{
		printf("\n\n\t\t\tMENU\n1. INSERT\n2. INORDER\n3. PREORDER\n4. POSTORDER\n5. SEARCH\n0. EXIT\n");
		printf("ENTER YOUT CHOICE: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
			printf("\nENTER DATA: ");
			scanf("%d",&d);
			root=insert(root,d);
			break;
			
			case 2:
			printf("\n\tINORDER TRANSVERSAL IS: ");
			inorder(root);
			break;
			
			case 3:
			printf("\n\tPREORDER TRANSVERSAL IS: ");
			preorder(root);
			break;
			
			case 4:
			printf("\n\tPOSTORDER TRANSVERSAL IS: ");
			postorder(root);
			break;
			
			case 5:
			printf("ENTER KEY: ");
			scanf("%d", &d);
			p=search(root,d);
			if(p==NULL)
			printf("\nGIVEN KEY DOES NOT EXIST!");
			else
			printf("\nGIVEN KEY DOES EXIST!");
			
			case 0:
			exit(0);
			break;
			
			default:
			printf("INVALID CHOICE");
			}
		}
	}
