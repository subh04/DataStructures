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
                printf("%d ",sm.e[k].x);
                k++;

            }else{
                printf("%d ",0);
            }
        }
        printf("\n");
    }
}
int main()
{
    struct sparseMatrix sm;
    create(&sm);
    display(sm);

    return 0;
}
