#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[]={6,3,8,10,16,7,5,2,9,14};
    int i,j,sum=10;
    for(i =0;i<9;i++){
        for(j=i+1;j<10;j++){
            if(A[i]+A[j]==sum){
                    printf("element %d + element %d = sum %d\n",A[i],A[j],sum);

            }
        }
    }
    return 0;
}
