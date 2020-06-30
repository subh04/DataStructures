#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
}*top=NULL;
void push(int data){
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    if(t==NULL){
        printf("stack overflow");
    }else{
        t->data=data;
        t->next=top;
        top=t;
    }
}
int pop(){
    struct Node *p;
    int x;
    if(top==NULL){
        printf("nothing to pop\n");
    }else{
        p=top;
        x=top->data;
        top=top->next;
        free(p);
    }
    return x;
}
int isOperand(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/')
        return 0;
    else
        return 1;

}
int evalPostfix(char *postfixExp){
    int i;
    int x1,x2,r;
    for(i=0;postfixExp[i]!='\0';i++){
        if(isOperand(postfixExp[i]))
            push(postfixExp[i]-'0');
        else{
            x2=pop();
            x1=pop();
            switch(postfixExp[i]){
            case '+':
                r=x1+x2;

                break;
            case '-':
                r=x1-x2;

                break;
            case '*':
                r=x1*x2;

                break;
            case '/':
                r=x1/x2;

                break;

            }
            push(r);
        }
    }
    return top->data;
}
int main()
{
    char *postfixExp="234*+82/-";
    printf("the value of the postfix expression is %d\n",evalPostfix(postfixExp));
    //printf("Hello world!\n");
    return 0;
}
