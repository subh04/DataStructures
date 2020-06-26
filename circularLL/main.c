#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*Head;
void create(int A[],int n){
    int i;
    struct Node *t,*last;
    Head=(struct Node*)malloc(sizeof(struct Node));
    Head->data=A[0];
    Head->next=Head;
    last=Head;
    for(i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}
void display(struct Node *h){
    do{
        printf("%d ",h->data);
        h=h->next;
    }while(h!=Head);
}
void insertElement(struct Node *h,int pos,int data){
    struct Node *t=NULL;
    int i;
    if(pos==0){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=data;
        if(Head==NULL){
            Head=t;
            Head->next=Head;
        }else{
            while(h->next!=Head){
                h=h->next;
            }
            h->next=t;
            t->next=Head;
            Head=t;
        }


    }else{
        for(i=0;i<pos-1;i++){
            h=h->next;
        }
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=data;
        t->next=h->next;
        h->next=t;
    }
}
int main()
{
    int A[]={2,3,4,5,6};
    create(A,5);
    display(Head);
    insertElement(Head,0,299);
    printf("\n");
    display(Head);
    insertElement(Head,3,599);
    printf("\n");
    display(Head);
    return 0;
}
