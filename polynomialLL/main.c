#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Node{
    int coeff;
    int exp;
    int next;
}*first,*last;
void createFirst(int c,int e){
    first=(struct Node *)malloc(sizeof(struct Node));
    first->coeff=c;
    first->exp=e;
    first->next=NULL;
    last=first;
}
void createRest(int c,int e){
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->next=last->next;
    last->next=t;
    t->coeff=c;
    t->exp=e;
    last=t;
}
void display(struct Node *p){
    while(p!=NULL){
        printf("%d*X^%d+",p->coeff,p->exp);
        p=p->next;
    }
}
void calculatePolynomial(struct Node *p,int x){
    double sum=0.0;
    while(p!=NULL){
        printf("%d*%d^%d+",p->coeff,x,p->exp);
        p=p->next;
    }
    p=first;
    while(p!=NULL){
        sum=sum+p->coeff*pow(x,p->exp);
        p=p->next;
    }
    printf("=%f ",sum);

}
int main()
{
    int num,c,e,i,x;
    printf("Enter total number of terms in your polynomial\n");
    scanf(" %d",&num);
    printf("\nenter the coefficient of term number %d",1);
    scanf(" %d",&c);
    printf("\nenter the exponent of term number %d",1);
    scanf(" %d",&e);
    createFirst(c,e);
    for(i=1;i<num;i++){
        printf("\nenter the coefficient of term number %d",i+1);
        scanf(" %d",&c);
        printf("\nenter the exponent of term number %d",i+1);
        scanf(" %d",&e);
        createRest(c,e);


    }
    display(first);
    printf("\nenter the value of x\n");
    scanf("%d",&x);
    calculatePolynomial(first,x);
    return 0;
}
