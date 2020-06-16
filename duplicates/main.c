#include <stdio.h>
#include <stdlib.h>

int main()
{


    int A[]={3,6,8,8,10,12,15,15,15,20};
    //printing elements having duplicates sorted array
    /*int i;
    int last_duplicate=0;
    printf("elements having duplicates\n");
    for(i=0;i<10;i++){

        if(A[i]==A[i+1]&&last_duplicate!=A[i]){
            last_duplicate=A[i];
            printf("%d ",A[i]);
        }
    }
    */
    //counting number of duplicates sorted array
    /*
    int i,j;
    for(i=0;i<10;i++){
        if(A[i]==A[i+1]){
            j=i+1;
            while(A[j]==A[i]){
                j++;
            }
            printf("%d is appearing %d times\n",A[i],j-i);
            i=j-1;
        }
    }
    */
    //using hash table of sorted and unsorted array

    int i;
    int h=A[9];
    int H[h];
    for(i=0;i<=h;i++){
        H[i]=0;

    }
    for(i=0;i<10;i++){
        H[A[i]]++;
        //printf("%d ",H[i]);
    }
    for(i=0;i<=h;i++){
        printf("%d ",H[i]);

    }
    for(i=0;i<=h;i++){
        if(H[i]>1){
            printf("\n%d has appeared %d times ",i,H[i]);
        }
    }

    return 0;
}
