#include <stdio.h>
#include <stdlib.h>
//Sparse matrix
struct elements{
    int i;
    int j;
    int x;
};
struct sparseMatrix{
    int m;
    int n;
    int numOfNonZeros;
    struct elements *e;
};
void create(struct sparseMatrix *sm){
    int i;
    printf("Enter rows\n");
    scanf("%d",&sm->m);
    printf("Enter columns\n");
    scanf("%d",&sm->n);
    printf("Enter number of non zeros\n");
    scanf("%d",&sm->numOfNonZeros);
    sm->e=(struct elements *)malloc(sm->numOfNonZeros*sizeof(struct elements));
    printf("Enter all the non zero elements\n");
    for(i=0;i<sm->numOfNonZeros;i++){
        printf("Enter row of the non zero element\n");
        scanf("%d",&sm->e[i].i);
        printf("Enter column of the non zero element\n");
        scanf("%d",&sm->e[i].j);
        printf("Enter the element\n");
        scanf("%d",&sm->e[i].x);

    }

}
void display(struct sparseMatrix sm){
    int i,j,k=0;
    for(i=1;i<=sm.m;i++){
        for(j=1;j<=sm.n;j++){
            if(i==sm.e[k].i && j==sm.e[k].j){
                printf("%d\t",sm.e[k].x);
                k++;

            }else{
                printf("%d\t",0);
            }
        }
        printf("\n");
    }
}
struct sparseMatrix * add(struct sparseMatrix *sm1,struct sparseMatrix *sm2){
    int i,j,k;
    i=j=k=0;
    struct sparseMatrix *sum;
    sum=(struct sparseMatrix*)malloc(sizeof(struct sparseMatrix));
    sum->e=(struct elements*)malloc(sm1->numOfNonZeros+sm2->numOfNonZeros*sizeof(struct elements));
    while(i<sm1->numOfNonZeros&&j<sm2->numOfNonZeros){
        if(sm1->e[i].i<sm2->e[j].i){
            sum->e[k]=sm1->e[i];
            i++;
            k++;
        }else if(sm1->e[i].i>sm2->e[j].i){
            sum->e[k]=sm2->e[j];
            j++;
            k++;
        }else{
            if(sm1->e[i].j<sm2->e[j].j){
                sum->e[k]=sm1->e[i];
                i++;
                k++;
            }else if(sm1->e[i].j>sm2->e[j].j){
                sum->e[k]=sm2->e[j];
                j++;
                k++;
            }else{
                sum->e[k]=sm1->e[i];
                sum->e[k].x=sm1->e[i].x+sm2->e[j].x;
                k++;
                i++;
                j++;

            }

        }

    }
    for(;i<sm1->numOfNonZeros;i++){
        sum->e[k]=sm1->e[i];
        k++;
    }
    for(;j<sm1->numOfNonZeros;j++){
        sum->e[k]=sm2->e[j];
        k++;
    }
    sum->m=sm1->m;
    sum->n=sm1->n;
    sum->numOfNonZeros=k;

    return sum;



}
int main()
{
    struct sparseMatrix sm1,sm2,*sm3;
    create(&sm1);
    create(&sm2);
    sm3=add(&sm1,&sm2);
    printf("Matrix 1\n");
    display(sm1);
    printf("Matrix 2\n");
    display(sm2);
    printf("Matrix sum\n");
    display(*sm3);

    return 0;
}
