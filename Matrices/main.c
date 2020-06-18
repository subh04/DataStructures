#include <stdio.h>
#include <stdlib.h>



struct Matrix{
    int A[10];
    int n;
};
void Set(struct Matrix *m,int i,int j,int x){
    if(i==j){
        m->A[i-1]=x;
    }
    else{
        printf("rows and column do not match");
    }
}
int Get(struct Matrix m,int i,int j){
    if(i==j){
        return m.A[i-1];
    }else{
        return 0;
    }
}
void Display(struct Matrix m){
int i,j;
for(i=1;i<=m.n;i++){
    for(j=1;j<=m.n;j++){
        if(i==j){
            printf("%d ",m.A[i-1]);
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
    m.n=4;
    Set(&m,1,1,1);
    Set(&m,2,2,2);
    Set(&m,3,3,3);
    Set(&m,4,4,4);
    Display(m);
    printf("\n%d",Get(m,1,1));
    return 0;
}
