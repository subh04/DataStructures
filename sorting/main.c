#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int *b){
    int temp;
    if(a>b){
        temp=*b;
        *b=*a;
        *a=temp;
    }
}
void BubbleSort(int A[],int n){
    int i,j,flag;
    for(i=0;i<n-1;i++){
        flag=0;
        for(j=0;j<n-1-i;j++){
            if(A[j+1]>A[j]){
                swap(&A[j+1],&A[j]);
                flag=1;
            }
        }
        if(flag==0)
            break;
    }


}
void display(int A[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",A[i]);
    }
}
int main()
{
    int A[]={24,45,12,32,56,76,89,10,79,84},n=10;
    BubbleSort(A,n);
    display(A,n);
    return 0;
}
