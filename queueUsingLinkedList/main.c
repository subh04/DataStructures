#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
}*front=NULL,*rear=NULL;

void enqueue(struct Node *p,int x){
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    if(t==NULL){
        printf("stack overflow\n");
    }else{
        t->data=x;
        t->next=NULL;
        if(front==NULL){
            front=rear=t;
        }else{
            rear->next=t;
            rear=t;
        }
    }
}
void dequeue(struct Node *p){
    if(front==NULL){
        printf("queue is empty\n");
    }else{
    front=front->next;
    free(p);
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
    enqueue(front,5);
    enqueue(front,4);
    enqueue(front,3);
    enqueue(front,2);
    enqueue(front,1);
    dequeue(front);
    enqueue(front,5);
    display(front);
    //printf("Hello world!\n");
    return 0;
}
