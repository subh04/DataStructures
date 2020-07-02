#include <stdio.h>
#include <stdlib.h>
struct Node{
    char data;
    struct Node *next;
}*top1=NULL,*top2=NULL,*top3=NULL,*last1=NULL,*last2=NULL,*last3=NULL;

void enqueue(char data,int priority){
    if(priority==1){
        struct Node *t;
        t=(struct Node *)malloc(sizeof(struct Node));
        if(t==NULL){
            printf("stack overflow");
        }else{
            t->data=data;
            t->next=NULL;
            if(top1==NULL)
                top1=last1=t;
            else{
                last1->next=t;
                last1=t;
            }
        }
    }else if(priority==2){
        struct Node *t;
        t=(struct Node *)malloc(sizeof(struct Node));
        if(t==NULL){
            printf("stack overflow");
        }else{
            t->data=data;
            t->next=NULL;
            if(top2==NULL)
                top2=last2=t;
            else{
                last2->next=t;
                last2=t;
            }
        }
    }else if(priority==3){
        struct Node *t;
        t=(struct Node *)malloc(sizeof(struct Node));
        if(t==NULL){
            printf("stack overflow");
        }else{
            t->data=data;
            t->next=NULL;
            if(top3==NULL)
                top3=last3=t;
            else{
                last3->next=t;
                last3=t;
            }
        }
    }
}
void dequeue(){
    if(top1!=NULL){
        struct Node *p;
        p=top1;
        top1=top1->next;
        free(p);
    }else if(top2!=NULL){
        struct Node *p;
        p=top2;
        top2=top2->next;
        free(p);
    }else if(top3!=NULL){
        struct Node *p;
        p=top3;
        top3=top3->next;
        free(p);
    }else
        printf("Nothing to delete");
}
void display(){
    struct Node *p;
    if(top1==NULL&&top2==NULL&&top3==NULL){
        printf("nothing to show");
    }
    p=top1;
    while(p!=NULL){
        printf("%c ",p->data);
        p=p->next;
    }
    p=top2;
    while(p!=NULL){
        printf("%c ",p->data);
        p=p->next;
    }
    p=top3;
    while(p!=NULL){
        printf("%c ",p->data);
        p=p->next;
    }
}
int main()
{
    enqueue('a',1);
    enqueue('b',1);
    enqueue('c',2);
    enqueue('d',3);
    enqueue('e',2);
    enqueue('f',1);
    enqueue('g',2);
    enqueue('h',3);
    enqueue('i',2);
    //dequeue();
    //dequeue();
    //dequeue();
    display();
    return 0;
}
