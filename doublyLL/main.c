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
void count(struct Node *p){
    int c=0;
    while(p!=NULL){
        c=c+1;
        p=p->next;
    }
    printf("\ncount is %d",c);
}
void insert(struct Node *p,int pos,int data){
    struct Node *t;
    int i;
    if(pos==0){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=data;
        if(p==NULL){
            t->next=NULL;
            t->prev=NULL;
        }else{
            t->prev=first->prev;
            first->prev=t;
            t->next=first;
            first=t;
        }
    }else{
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=data;
        for(i=0;i<pos-1;i++){
            p=p->next;
        }
        t->next=p->next;
        t->prev=p;
        p->next=t;
        if(t->next!=NULL){
            t->next->prev=t;
        }

    }
}
void deleteElement(struct Node *p,int pos){
    int i;
    if(pos==1){
        if(p==NULL){
            printf("\nnothing to delete");
            return;
        }else{
            first=first->next;
            first->prev=NULL;
            free(p);
        }
    }else{
        for(i=0;i<pos-1;i++){
            p=p->next;
        }
        p->prev->next=p->next;
        if(p->next!=NULL){
            p->next->prev=p->prev;
        }
        free(p);
    }

}
int main()
{
    int A[]={12,4,5,6,89,10};
    create(A,6);
    display(first);
    count(first);
    insert(first,0,999);
    printf("\n");
    display(first);
    insert(first,0,1111);
    printf("\n");
    display(first);
    deleteElement(first,1);
    printf("\n");
    display(first);
    deleteElement(first,3);
    printf("\n");
    display(first);
    deleteElement(first,6);
    printf("\n");
    display(first);

    return 0;
}
