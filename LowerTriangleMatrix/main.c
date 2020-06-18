#include <stdio.h>
#include <stdlib.h>



struct Matrix{
    int *A;
    int n;
};
void Set(struct Matrix *m,int i,int j,int x){
    if(i>=j){
        //row major formulae
        //m->A[(i*(i-1))/2+j-1]=x;
        //column major formulae
        m->A[m->n*(j-1)+(j-2)*(j-1)/2+(i-j)]=x;
    }
}

int Get(struct Matrix m,int i,int j){
    if(i>=j){
        //row major
        // return m.A[(i*(i-1))/2+j-1]
        return m.A[m.n*(j-1)+(j-2)*(j-1)/2+(i-j)];
    }else{
        return 0;
    }

}
void Display(struct Matrix m){
int i,j;
for(i=1;i<=m.n;i++){
    for(j=1;j<=m.n;j++){
        if(i>=j){
            //row major
            //printf("%d ",m.A[(i*(i-1))/2+j-1]);
            printf("%d ",m.A[m.n*(j-1)+(j-2)*(j-1)/2+(i-j)]);
        }else{
            printf("%d ",0);
        }
    }
    printf("\n");
}
}
int main()
{
    struct Matrix m;
    int i,j,x;
    printf("enter dimension of the matrix\n");
    scanf("%d",&m.n);
    m.A=(int *)malloc(m.n*(m.n+1)/2*sizeof(int));//number of non zeroes in lower triangle matrix is n(n+1)/2;
    printf("Enter all elements\n");
    for(i=1;i<=m.n;i++){
        for(j=1;j<=m.n;j++){
            scanf("%d",&x);
            Set(&m,i,j,x);
        }
    }
    printf("\n\n");
    Display(m);
    printf("\n%d",Get(m,2,1));



    return 0;
}
