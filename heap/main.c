#include <stdio.h>
#include <stdlib.h>

void delete(int A[],int n){
    int x,i,j;
    //x=A[n];
    A[1]=A[n];
    i=1;
    j=2*i;
    while(j<n-1){
        if(A[j+1]>A[j])
            j=j+1;
        if(A[i]<A[j]){
            x=A[j];
            A[j]=A[i];
            A[i]=x;
            i=j;
            j=2*i;
        }else{
            break;
        }
    }
}
void insert(int A[],int n){
    int i=n,temp;
    temp=A[i];
    while(A[i]>A[i/2]&&i>1){

        A[i]=A[i/2];
        i=i/2;
        A[i]=temp;
    }






}
void create(){
    int A[]={0,40,35,30,15,10,2,5};
    int i;
    for(i=2;i<=7;i++){
        insert(A,i);

    }
    print(A,7);
    delete(A,7);
    print(A,6);

}
void print(int A[],int n){
int i;
for(i=1;i<=n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}
int main()
{
    create();
    //printf("Hello world!\n");
    return 0;
}
