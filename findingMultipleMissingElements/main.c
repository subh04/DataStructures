#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    //finding missing values in sorted array
    int arr[]={6,7,8,9,11,12,15,16,17,18,19};
    int l=arr[0];
    int h=arr[10];
    int n=11;
    int diff=l-0;
    int i;
    printf("missing numbers are ");
    for(i=0;i<n;i++){
        if(arr[i]-i!=diff){

            while(diff<arr[i]-i){
                printf("%d ",i+diff);
                diff++;
            }
        }
    }
    */
    //finding missing numbers of unsorted array
    int A[]={3,7,4,9,12,6,1,11,2,10};
    int h=12;
    int l=1;
    int n=10;
    int i;
    int B[h+1];
    for(i=1;i<=h;i++){
        B[i]=0;
        //printf("%d ",B[i]);
    }
    for(int i=0;i<n;i++){
        B[A[i]]++;
    }
    printf("missing numbers are ");
    for(int i=l;i<=h;i++){
        if(B[i]==0){
            printf("%d ",i);
        }
    }



    return 0;

}
