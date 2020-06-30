#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node{
    char opertor;
    struct Node *next;
}*top=NULL;
void push(char x){
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    if(t==NULL){
        printf("stack overflow");
    }else{
        t->opertor=x;
        t->next=top;
        top=t;
    }

}
char pop(){
    char x;
    struct Node *p;
    if(top==NULL){
        printf("Nothing to pop\n");
    }else{
        p=top;
        x=top->opertor;
        top=top->next;
        free(p);

    }
    return x;
}
void display(){
    struct Node *p=top;
    while(p!=NULL){
        printf("%d ",p->opertor);
        p=p->next;
    }
}
int isEmpty(){
    if(top==NULL){
        return 1;
    }else{
        return 0;
    }
}
int pre(char x){
    if(x=='+'||x=='-')
        return 1;
    else if(x=='*'||x=='/')
        return 2;
    else
        return 0;
}
int isOperand(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/')
        return 0;
    else
        return 1;

}
char * InfixToPostfix(char *exp){
    char *postfix;
    //int len=strlen(exp);
    postfix=(char *)malloc(sizeof(char));
    int i=0,j=0;
    while(exp[i]!='\0'){
        if(isOperand(exp[i])){
            postfix[j]=exp[i];
            i++;
            j++;
        }else{
            if(pre(exp[i])>pre(top->opertor)){
                push(exp[i]);
                i++;
            }else{
                postfix[j]=pop();
                j++;
            }
        }
    }
    while(top!=NULL){
        postfix[j]=pop();
        j++;
    }
    postfix[j]='\0';
    return postfix;
}
int main()
{

    push('#');
    //display();
    char *exp="a+b*c-d/e";
    char *postfix=InfixToPostfix(exp);
    printf("%s ",postfix);
    return 0;
}
