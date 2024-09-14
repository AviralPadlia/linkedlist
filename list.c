#include<stdio.h>
#include<stdlib.h>

typedef struct _Node
{
 int val;
 struct _Node *next;
}Node;

Node *makeNode(int);
void print(Node *);
int countNodes(Node *);
Node *locate(Node *,int);
int count(Node *,int);
Node *getMin(Node *);
int isSorted(Node *);
void printSmallerItem(Node *);
void printReverse(Node *);
int countRec(Node *,int );
void reverseRec(Node *);
Node *reverse(Node *,Node **);
Node *getMinRec(Node *);
Node *append(Node * ,Node ** ,int );
Node *insBeforeFirst(Node *,int);
Node *insBeforeLast(Node *,int );
Node *insBefore(Node *,int ,int );
Node *insBeforeInfo(Node *,int ,int );
Node *insAfterFirst(Node *,Node *,int);
Node *insAfterLast(Node *,Node *,int);
Node *insAfterNode(Node *,Node *,int ,int);
Node *rmvFirst(Node *);
Node *rmvLast(Node *,Node **);
Node *rmvNode(Node *,Node **,int);
Node *clear(Node *);

void main()
{
 Node *start='\0',*last='\0',*nd;
 int n,cnt,pos,info;

 while(1)
 {
  printf("Enter the number[0 to stop] : ");
  scanf("%d",&n);

  if(n==0) break;

  nd=makeNode(n);

  if(start=='\0')
   start=nd;
  else
   last->next=nd;
  last=nd;
 }

 printf("\nItems in the List : ");
 print(start);

 n=countNodes(start);
 printf("\n\nNo. of Nodes : %d",n);

 printf("\n\nEnter the Item to locate : ");
 scanf("%d",&n);
 nd=locate(start,n);
 if(nd)
  printf("Item found at address : %d",nd);
 else
  printf("Item not found...");

 printf("\n\nEnter the Item to count it's No. of occurence : ");
 scanf("%d",&n);
 cnt=count(start,n);
 printf("Item %d occurs %d times in the list.",n,cnt);

 nd=getMin(start);
 printf("\n\nSmallest Item in the list is at address : %d",nd);

 if(isSorted(start))
  printf("\n\nList is Sorted.");
 else
  printf("\n\nList is not sorted.");

 printSmallerItem(start);

 printf("\n\n");
 printf("the List in the reverse order [");
 printReverse(start);
 printf("]");

 printf("\n\nEnter the Item to count it's No. of occurence : ");
 scanf("%d",&n);
 cnt=countRec(start,n);
 printf("Item %d occurs %d times in the list.",n,cnt);

 reverseRec(start);
 nd=start;
 start=last;
 last=nd;
 printf("\n\nItems in the List after reversing it ");
 print(start);

 start=reverse(start,&last);
 printf("\n\nItems in the List after reversing it ");
 print(start);

 nd=getMinRec(start);
 printf("\n\nSmallest Item in the list is at address : %d",nd);

 printf("\n\n");
  while(1)
 {
  printf("Enter the number[0 to stop] : ");
  scanf("%d",&n);

  if(n==0) break;

  start=append(start,&last,n);
 }

 printf("Items in the List : ");
 print(start);

 printf("\n\nEnter the number to insert before the first node : ");
 scanf("%d",&n);
 start=insBeforeFirst(start,n);
 printf("Items in the List : ");
 print(start);

 printf("\n\nEnter the number to insert before the last node : ");
 scanf("%d",&n);
 start=insBeforeLast(start,n);
 printf("Items in the List : ");
 print(start);

 printf("\n\nEnter the number to insert : ");
 scanf("%d",&n);
 printf("Enter the position to insert before it : ");
 scanf("%d",&pos);
 start=insBefore(start,pos,n);
 printf("Items in the List : ");
 print(start);

 printf("\n\nEnter the value before which you want to the number : ");
 scanf("%d",&info);
 printf("Enter the number to insert before the entered number: ");
 scanf("%d",&n);
 start=insBeforeInfo(start,info,n);
 printf("Items in the List : ");
 print(start);

 printf("\n\nEnter the number to insert after the first Node : ");
 scanf("%d",&n);
 last=insAfterFirst(start,last,n);
 printf("Item in the list ");
 print(start);

 printf("\n\nEnter the number to insert after a last node : ");
 scanf("%d",&n);
 last=insAfterLast(start,last,n);
 printf("Items in the list ");
 print(start);

 printf("\n\nEnter the number : ");
 scanf("%d",&n);
 printf("Enter the position for insert number after it : ");
 scanf("%d",&pos);
 last=insAfterNode(start,last,pos,n);
 printf("Items in the list ");
 print(start);

 start=rmvFirst(start);
 printf("\n\nItems in the list after removing first node : ");
 print(start);

 start=rmvLast(start,&last);
 printf("\n\nItems in the list after removing last node : ");
 print(start);

 printf("\n\nEnter the position for removing node : ");
 scanf("%d",&pos);
 start=rmvNode(start,&last,pos);
 printf("Items in the list after removing node : ");
 print(start);

 start=clear(start);
 printf("\n\nThe List is deleted...");
}

Node *makeNode(int n)
{
 Node *nd;
 nd=(Node *)malloc(sizeof(Node));
 nd->val=n;
 nd->next='\0';
 return nd;
}

void print(Node *ptr)
{
 printf("[ ");

 while(ptr)
 {
  printf("%d ",ptr->val);
  ptr=ptr->next;
 }
 printf("]");
}

int countNodes(Node *ptr)
{
 int cnt=0;

 while(ptr)
 {
  cnt++;
  ptr=ptr->next;
 }
 return cnt;
}

Node *locate(Node *ptr,int n)
{
 while(ptr&&ptr->val!=n) ptr=ptr->next;
 return ptr;
}

int count(Node *ptr,int n)
{
 int cnt=0;
 while(ptr)
 {
  cnt=cnt+(ptr->val==n);
  ptr=ptr->next;
 } 
 return cnt;
}

Node *getMin(Node *ptr)
{
 Node *nd=ptr;
 while(ptr)
 {
  if(ptr->val<nd->val)
   nd=ptr;

  ptr=ptr->next;
 }
 return nd;
}

int isSorted(Node *ptr)
{
 int sorted;
 Node *prv;
 if(ptr=='\0')
  return 0;

 for(prv=ptr,ptr=ptr->next,sorted=1;ptr&&sorted;prv=ptr,ptr=ptr->next)
  sorted=ptr->val>=prv->val;
 return sorted;
}

void printSmallerItem(Node *start)
{
 int avg,n;
 Node *ptr;

 for(avg=n=0,ptr=start;ptr;ptr=ptr->next)
 {
  n++;
  avg+=ptr->val;
 }

 avg/=n;

 printf("\n\nItems smaller than the average(%d) : [",avg);

 for(ptr=start;ptr;ptr=ptr->next)
  if(ptr->val<avg)
   printf(" %d ",ptr->val);

 printf("]");
}

void printReverse(Node *ptr)
{
 if(ptr=='\0') return;

 printReverse(ptr->next);
 
 printf(" %d ",ptr->val);
}

Node *getMinRec(Node *ptr)
{
 if(ptr=='\0'||ptr->next=='\0') return ptr;
 Node *nd=getMinRec(ptr->next);
 if(ptr->val<nd->val)
  return ptr;
 else
  return nd;
}

int countRec(Node *ptr,int n)
{
 if(ptr=='\0') return 0;
 return countRec(ptr->next,n)+(ptr->val==n);
}

void reverseRec(Node *ptr)
{
 if(ptr=='\0'||ptr->next=='\0') return;
  reverseRec(ptr->next);
 ptr->next->next=ptr;
 ptr->next='\0';
}

Node *reverse(Node *start,Node **p2last)
{
 Node *prv='\0',*ptr=start,*tmp;

 while(ptr)
 {
  tmp=ptr->next;
  ptr->next=prv;
  prv=ptr;
  ptr=tmp;
 }
 *p2last=start;
 return prv;
}

Node *append(Node *start,Node **p2last,int n)
{
 Node *nd=makeNode(n);

 if(start=='\0')
  start=nd;
 else
  (*p2last)->next=nd;

 *p2last=nd;
 return start;
}

Node *insBeforeFirst(Node *start,int n)
{
 Node *nd;
 if(start)
 {
  nd=makeNode(n);
  nd->next=start;
  return nd;
 }
 return start;
}

Node *insBeforeLast(Node *start,int n)
{
 Node *ptr,*prv,*nd;

 for(ptr=start;ptr&&ptr->next;prv=ptr,ptr=ptr->next);

 if(ptr)
 {
  nd=makeNode(n);
  nd->next=ptr;
  if(ptr==start)
   start=nd;
  else
   prv->next=nd;
 }
 return start;
}

Node *insBefore(Node *start,int pos,int n)
{
 Node *ptr,*prv;
 for(ptr=start;ptr&&pos>1;prv=ptr,ptr=ptr->next,pos--);
 if(ptr)
 {
  Node *nd=makeNode(n);
  nd->next=ptr;
  if(ptr==start)
   start=nd;
  else prv->next=nd;
 }
 return start;
}

Node *insBeforeInfo(Node *start,int info,int n)
{
 Node *ptr,*prv;
 for(ptr=start;ptr&&ptr->val!=info;prv=ptr,ptr=ptr->next);

 if(ptr)
 {
  Node *nd=makeNode(n);
  nd->next=ptr;
  if(ptr==start)
   start=nd;
  else
   prv->next=nd;
 }
 return start;
}

Node *insAfterFirst(Node *ptr,Node *last,int n)
{
 if(ptr)
 {
  Node *nd=makeNode(n);
  nd->next=ptr->next;
  ptr->next=nd;
  if(ptr==last)
   last=nd;
 }
 return last;
}

Node *insAfterLast(Node *start,Node *last,int n)
{
 if(last)
 {
  last->next=makeNode(n);
  last=last->next;
 }
 return last;
}

Node *insAfterNode(Node *ptr,Node *last,int pos,int n)
{
 while(ptr&&pos>1)
 {
  ptr=ptr->next;
  pos--;
 }
 if(ptr)
 {
  Node *nd=makeNode(n);
  nd->next=ptr->next;
  ptr->next=nd;
  if(ptr==last)
   last=nd;
 }
 return last;
}

Node *rmvFirst(Node *start)
{
 if(start)
 {
  Node *tmp=start;
  start=start->next;
  free(tmp);
 }
 return start;
}

Node *rmvLast(Node *start,Node **p2last)
{
 Node *prv,*ptr;
 for(ptr=start;ptr&&ptr->next;prv=ptr,ptr=ptr->next);

 if(ptr)
 {
  if(ptr==start)
   start='\0';
  else
  {
   prv->next='\0';
   *p2last=prv;
  }
  free(ptr);
 }
 return start;
}

Node *rmvNode(Node *start,Node **p2last,int pos)
{
 Node *ptr,*prv;
 for(ptr=start;ptr&&pos>1;prv=ptr,ptr=ptr->next,pos--);

 if(ptr)
 {
  if(ptr==start)
   start=start->next;
  else
  {
   prv->next=ptr->next;
   if(ptr==*p2last)
    *p2last=prv;
  }
  free(ptr);
 }
 return start;
}

Node *clear(Node *start)
{
 Node *ptr=start,*prv;
 while(ptr)
 {
  prv=ptr;
  ptr=ptr->next;
  free(prv);
 }
 return '\0';
}
