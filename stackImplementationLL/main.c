#include <stdio.h>
#include <stdlib.h>
int c=0;
struct Node{
    int data;
    struct Node *next;
}*top=NULL;
void push(int x){
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    if(t==NULL){
        printf("\nstack overflow in heap");
    }else{
        t->data=x;
        t->next=top;
        top=t;
    }
}
void pop(){
    struct Node *p;
    if(top==NULL){
        printf("\nstack is empty");
    }else{
        p=top;
        top=top->next;
        free(p);
    }
}
void display(struct Node *p){
    if(top==NULL){
        printf("\nNothing to display");
    }
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}
void peek(int pos){
    count();
    if(pos<1||pos>c){
        printf("\ninvalid position");
        return;
    }
    struct Node *p=top;
    int i;
    for(i=0;i<pos-1;i++){
        p=p->next;
    }
    printf("\nvalue in the given position is %d",p->data);
}
void count(){
    struct Node *p=top;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    printf("\n");
}
void isFull(){
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    if(t==NULL){
        printf("\nstack is full");

    }else{
        printf("\nstack is not full");
    }
    free(t);
}
int main()
{

    push(10);
    push(50);
    push(10);
    push(555);
    pop();
    pop();
    pop();
    push(2);
    display(top);
    peek(1);
    peek(-2);
    peek(12);
    isFull();


    //printf("%d",c);
    return 0;
}
