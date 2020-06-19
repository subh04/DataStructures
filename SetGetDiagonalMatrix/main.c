#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *A,n,ch,x,i,j;
    printf("enter the dimension of the matrix\n");
    scanf("%d",&n);
    A=(int *)malloc(n*sizeof(int));


    do{
        printf("\nMENU\n");
        printf("1.CREATE\n");
        printf("2.GET\n");
        printf("3.SET\n");
        printf("4.DISPLAY\n");
        printf("enter choice\n");
        scanf("%d",&ch);
        switch(ch){
        case 1:
            for(i=1;i<=n;i++){
                printf("enter the value of [%d][%d] ",i,i);
                scanf("%d",&A[i-1]);
            }
            break;
        case 2:
            printf("enter row value ");
            scanf("%d",&i);
            printf("enter column value ");
            scanf("%d",&j);
            if(i==j){
                printf("%d ",A[i-1]);
            }else{
                printf("%d ",0);
            }
            break;
        case 3:
            printf("enter row value ");
            scanf("%d",&i);
            printf("enter column value ");
            scanf("%d",&j);
            printf("enter element ");
            scanf("%d",&x);
            if(i==j){
                A[i-1]=x;
            }
            break;
        case 4:
            for(i=1;i<=n;i++){
                for(j=1;j<=n;j++){
                    if(i==j){
                        printf("%d ",A[i-1]);
                    }else{
                        printf("%d ",0);
                    }
                }
                printf("\n");
            }
            break;


        }

    }while(ch<=4);
    return 0;
}
