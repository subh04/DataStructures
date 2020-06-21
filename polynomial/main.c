#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct term{
    int coeff;
    int exponent;
};
struct polynomial {
    int numOfterms;
    struct term *t;
};
int processPoly(struct polynomial *p,int x){
    int i,sum=0;
    for(i=0;i<p->numOfterms;i++){
        sum=sum+p->t[i].coeff*pow(x,p->t[i].exponent);
    }
    return sum;
}

void display(struct polynomial p,int x,int processed){
    int i;
    for(i=0;i<p.numOfterms;i++){
        printf("%dX^%d +",p.t[i].coeff,p.t[i].exponent);
    }
    printf("\n");
    for(i=0;i<p.numOfterms;i++){
        printf("%d(%d)^%d +",p.t[i].coeff,x,p.t[i].exponent);
    }
    printf(" =%d\n",processed);
}
struct polynomial *add(struct polynomial *p1,struct polynomial *p2){
    int i,j,k;
    struct polynomial *sum;
    sum=(struct polynomial*)malloc(sizeof(struct polynomial));
    sum->t=(struct term*)malloc((p1->numOfterms+p2->numOfterms)*sizeof(struct term));
    i=j=k=0;
    while(i<p1->numOfterms && j<p2->numOfterms){
        if(p1->t[i].exponent>p2->t[j].exponent){
            sum->t[k]=p1->t[i];
            i++;
            k++;
        }else if(p1->t[i].exponent<p2->t[j].exponent){
            sum->t[k]=p2->t[j];
            j++;
            k++;
        }else{
            sum->t[k].exponent=p1->t[i].exponent;
            sum->t[k].coeff=p1->t[i].coeff+p2->t[j].coeff;
            i++;
            j++;
            k++;
        }
    }
    for(;i<p1->numOfterms;i++){
        sum->t[k]=p1->t[i];
        k++;
    }
    for(;j<p2->numOfterms;j++){
        sum->t[k]=p2->t[j];
        k++;
    }
    sum->numOfterms=k;
    return sum;
}

void create(struct polynomial *p){
    int i;
    printf("enter the number of terms in your polynomial\n");
    scanf("%d",&p->numOfterms);
    p->t=(struct term*)malloc(p->numOfterms*sizeof(struct term));
    for(i=0;i<p->numOfterms;i++){
        printf("enter the coefficient of term %d ",i+1);
        scanf("%d",&p->t[i].coeff);
        printf("\nenter the exponent of term %d ",i+1);
        scanf("%d",&p->t[i].exponent);
    }


}
void displayReg(struct polynomial p){
    int i;
    printf("\nreg print");
    for(i=0;i<p.numOfterms;i++){
        printf("%dX^%d +",p.t[i].coeff,p.t[i].exponent);
    }
    printf("\n");

}

int main()
{
    int x,i;
    struct polynomial p1,p2,*p3;
    create(&p1);
    create(&p2);
    printf("enter the value of x\n");
    scanf("%d",&x);
    int processed1=processPoly(&p1,x);
    int processed2=processPoly(&p2,x);

    printf("the result of first is %d \n",processed1);
    printf("the result of second is %d \n",processed2);
    display(p1,x,processed1);
    display(p2,x,processed2);
    p3=add(&p1,&p2);
    //displayReg(*p3);
    printf("enter the value of x for the added polynomial\n");
    scanf("%d",&x);
    int processed3=processPoly(p3,x);
    printf("the result of the added polynomial is %d \n",processed3);
    display(*p3,x,processed3);

    return 0;
}
