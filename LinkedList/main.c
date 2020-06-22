#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
}*first=NULL; //first is globally available as a pointer to access this now we have to use -> arrow

void create(int A[],int n){
    int i;
    struct Node *t,*last;
    first=(struct Node*)malloc(sizeof(struct Node));

    first->data=A[0];
    first->next=NULL;
    last=first; //last sees the address inside of first
    for(i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;//here when it links with the new node
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
    int A[]={3,5,7,10,15};
    create(A,5);
    display(first);
    return 0;
}
