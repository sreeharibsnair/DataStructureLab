#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node * lchild, * rchild;
};
void main()
{
struct node * insert (struct node *,int);
struct node * search (struct node *,int);
void inorder (struct node *);
struct node * delete (struct node*, int);
struct node * root=0;
int item ,opt;
while(1)
{
printf("\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\n");
printf("Enter your option : ");
scanf("%d",&opt);
switch (opt)
{
case 1 :printf("Item to insert : ");
	scanf("%d",&item);
	root=insert(root,item); 	
	break;
case 2 :printf("item to delete : ");
	scanf("%d",&item);
	root=delete(root,item);	
	break;
case 3 :printf("item to search : ");
	scanf("%d",&item);
	if(search(root,item)==(struct node *)0)
	printf("not found\n");
	else
	printf("found\n");
	break;
case 4 :inorder(root);	
	break;
case 5 :exit(0);	
}}}
//function to search
struct node *search(struct node * r,int data)
{
while(r!=0 && r->data != data)
if(data<r->data)
	r=r->lchild;
else
r=r->rchild;
return r;
}


//function to insert
struct node * insert(struct node * r,int data)
{
struct node * t, * par=0,*t1;
t=(struct node *)malloc(sizeof(struct node));
t->data=data;
t->lchild=t->rchild=0;
if(r==0)
r=t;
else if(search(r,data)!=0)
printf("%d is duplicate",data);
else
{
t1=r;
while(t1 !=0)
{
par=t1;
if(data<t1->data)
t1=t1->lchild;
else
t1=t1->rchild;
}
if(data<par->data)//inserting
par->lchild=t;
else
par->rchild=t;
}
return r;
}


//inorder
void inorder(struct  node * r)
{
if(r!=0)
{
inorder(r->lchild);
printf("%d ,",r->data);
inorder(r->rchild);
}
}

//function to delete
struct node * delete(struct node * r,int data)
{
struct node * t=r,*par=0,*suc,*sucpar;
while(t!=0 && t->data!=data)//searching
{
par=t;
if (data<t->data)
t=t->lchild;
else
t=t->rchild;
}
if(t==0)
printf("%d not found...",data);
else
{
if(t->lchild==0 && t->rchild==0)//leaf node
{
if(par==0)//only single node
r=0;
else if (data<par->data)//leaf with parent
par->lchild=0;
else
par->rchild=0;
}
else if (t->lchild == 0 || t->rchild==0)//one child
{
if(par==0)//root is to be deleted
r=r->lchild==0? r->rchild:r->lchild;
else if (data <par ->data)
par->lchild =t->lchild==0?t->rchild:t->lchild;
else
par->rchild=t->lchild==0? t->rchild:t->lchild;
}
else //two child
{
sucpar=t;
suc=t->rchild;
while(suc->lchild!=0)//inorder successor
{
sucpar=suc;
suc=suc->lchild;
}
t->data=suc->data;
//delete inorder successor
if (suc->data <sucpar->data)
sucpar->lchild=suc->rchild;
else
sucpar->rchild=suc->rchild;
t=suc;
}
free(t);
}
return r;
}

