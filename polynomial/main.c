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

int main()
{
    int x,i;
    struct polynomial p;
    printf("enter the number of terms in your polynomial\n");
    scanf("%d",&p.numOfterms);
    p.t=(struct term*)malloc(p.numOfterms*sizeof(struct term));
    for(i=0;i<p.numOfterms;i++){
        printf("enter the coefficient of term %d ",i+1);
        scanf("%d",&p.t[i].coeff);
        printf("\nenter the exponent of term %d ",i+1);
        scanf("%d",&p.t[i].exponent);
    }
    printf("enter the value of x\n");
    scanf("%d",&x);
    int processed=processPoly(&p,x);
    printf("the result is %d ",processed);
    return 0;
}
