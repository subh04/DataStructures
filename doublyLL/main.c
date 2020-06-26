#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;
void create(int A[],int n){
    struct Node *t,*last;
    int i;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->prev=NULL;
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
}
void display(struct Node *p){
    while(p!=NULL){
       printf("%d ",p->data);
       p=p->next;
    }
}
int main()
{
    int A[]={12,4,5,6,89,10};
    create(A,6);
    display(first);

    return 0;
}
