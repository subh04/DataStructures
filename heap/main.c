#include <stdio.h>
#include <stdlib.h>

void insert(int A[],int n){
    int i=n,temp;
    temp=A[i];
    while(A[i]>A[i/2]&&i>1){

        A[i]=A[i/2];
        i=i/2;
        A[i]=temp;
    }



    for(i=0;i<=7;i++){
        printf("%d ",A[i]);
    }


}
void create(){
    int A[]={0,10,20,30,25,5,40,35};
    int i;
    for(i=2;i<=7;i++){
        insert(A,i);
        printf("\n");
    }
}
int main()
{
    create();
    //printf("Hello world!\n");
    return 0;
}
