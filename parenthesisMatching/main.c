#include <stdio.h>
#include <stdlib.h>
struct Node{
    char bracket;
    struct Node *next;
}*top=NULL;
void push(char brac){
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    if(t==NULL){
        printf("the stack is full\n");
    }else{
        t->bracket=brac;
        t->next=top;
        top=t;
    }
}
void pop(){
    struct Node *p;
    if(top==NULL){
        printf("\nEmpty Stack\n");
    }else{
        p=top;
        top=top->next;
        free(p);
    }
}
void display(){
    struct Node *p;
    p=top;
    while(p!=NULL){
        printf("%d ",p->bracket);
        p=p->next;
    }
}
void isBalanced(char *exp){
    int i;
    for(i=0;exp[i]!='\0';i++){
        if(exp[i]=='('){
            push(exp[i]);
           }else if(exp[i]==')'){
                if(top==NULL){
                   printf("\nthe given expression is not balanced\n");
                   return;
                   }
                pop();
           }

    }
    if(top==NULL){
        printf("\nThe expression has balanced brackets");
    }else{
        printf("\nThe expression doesnt have balanced brackets");
    }
}
int main()
{
    char *exp="((a+b)*(c-d)))";
    isBalanced(exp);

}
