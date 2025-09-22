#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int que[SIZE],front=0,rear=0;
void enqueue(int);
int dequeue();
void display();
int search(int);
void main()
{
int opt,item,ans;
while(1)
{
printf("\n1.Insert\n2.Delete\n3.Display\n4.Search\n5.Exit\n");
printf("Your option:");
scanf("%d",&opt);
switch(opt)
{
case 1:
printf("Item to insert:");
scanf("%d",&item);
enqueue(item);
break;
case 2:
item=dequeue();
printf("Deleted item=%d",item);
break;
case 3:
display();
break;
case 4:
printf("Item to search:");
scanf("%d",&item);
ans=search(item);
if(ans==1)
printf("Found....");
else
printf("Not Found....");
break;
case 5:
exit(0);
}
}
}
void enqueue(int data)
{
int r1=(rear+1)%SIZE;
if(r1==front)
printf("Queue is full");
else
{
rear=r1;
que[rear]=data;
}
}
int dequeue()
{
if(front==rear){
printf("Empty queue");
exit(2);
}else
{
front=(front+1)%SIZE;
return que[front];
}
}
void display()
{
int f=front,r=rear;
while(f!=r)
{
f=(f+1)%SIZE;
printf("%d,",que[f]);
}
}
int search(int item)
{
int f=front,r=rear;
while(f!=r)
{
f=(f+1)%SIZE;
if(que[f]==item)
return 1;
}
return 0;
}

