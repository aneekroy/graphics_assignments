#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
int ch;
struct node *lchild,*rchild;
};

void insert(struct node **t,int ch1)
{
if(*t==NULL)
{
(*t)=(struct node *)malloc(sizeof(struct node));
(*t)->ch=ch1;
(*t)->rchild=NULL;
(*t)->lchild=NULL;
return;
}
else{
     if(ch1<(*t)->ch)
     insert(&((*t)->lchild),ch1);
     else
     insert(&((*t)->rchild),ch1);
     }
return;
}

void preorder(struct node *t)
{
if(t!=NULL)
{
printf("%d ",t->ch);
preorder(t->lchild);
preorder(t->rchild);
}
else
return;
}
void inorder(struct node *t)
{
if(t!=NULL)
{
inorder(t->lchild);
inorder(t->rchild);
printf("%d ",t->ch);
}
else
return;
}
void postorder(struct node *t)
{
if(t!=NULL)
{
postorder(t->lchild);
printf("%d ",t->ch);
postorder(t->rchild);
}
else
return;
}
main()
{
    struct node *t;
    int i;
    int c;
    t=NULL;
   /* insert(&t,1);
    insert(&t,2);
    insert(&t,10);
    insert(&t,3);
    insert(&t,0);
    insert(&t,25);
    insert(&t,5);
    insert(&t,6);
    insert(&t,7);
    insert(&t,8);
    preorder(t);printf("\n");
    postorder(t);printf("\n");
    inorder(t);printf("\n");*/
    while(1)
    {
    printf("\nenter\n1->insert\n2->inorder\n3->preorder\n4->postorder\n5->exit\n");
    scanf("%d",&i);
    switch(i)
    {
    case 1:
         printf("\nenter the number you want to insert\n");
         scanf("%d",&c);
         insert(&t,c);
         break;
    case 2:
         inorder(t);
         break;
    case 3:
         preorder(t);
         break;
    case 4:
         postorder(t);
         break;
    case 5:
         exit(1);
        
    }
}
getch();
}       
    
