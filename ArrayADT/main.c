#include <stdio.h>
#include <stdlib.h>

struct Array{
    int *A;
    int size;
    int length;

};
void display(struct Array arr){
    int i;
    printf("the elements in the array are \n");
    for(i=0;i<arr.length;i++){
        printf("%d ",arr.A[i]);
    }
}
void append (struct Array *arr,int x){//(struct Array *arr,int x) call by address so modified actually
    if(arr->length<arr->size){
        arr->A[arr->length]=x;
        arr->length++;
        }


}
void insert(struct Array *arr,int index,int x){
    if(index>=0&&index<=arr->length&&arr->length<arr->size){
        int i;
        for(i =arr->length;i>index;i--){
            arr->A[i]=arr->A[i-1];
        }
        arr->A[index]=x;
        arr->length=arr->length+1;
    }




}


void delete(struct Array *arr,int index){
    int i;
    if(index>arr->length-1){
        printf("\n invalid index");

    }else{
        for(i=index;i<arr->length-1;i++){
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
    }

}
int LinearSearch(struct Array *arr,int key){
    int i,temp;
    for(int i=0;i<arr->length;i++){
        if(key==arr->A[i]){

            /* TRANSPOSITION

            temp=arr->A[i-1];
            arr->A[i-1]=arr->A[i];
            arr->A[i]=temp;

            */
            /*MOVE TO HEAD*/
            temp=arr->A[0];
            arr->A[0]=arr->A[i];
            arr->A[i]=temp;




            return 0;
        }

    }
    return -1;




}

int BinarySearch(struct Array arr,int h,int l,int key){
    int mid;

    while(l<=h){
        mid=(l+h)/2;
    if(key==arr.A[mid])
        return mid;
    else if(key<arr.A[mid])
        h=mid-1;
    else
        l=mid+1;



    }
    return -1;



}
int get(struct Array arr,int index){
    if(index>=0&&index<arr.length){
        return arr.A[index];
    }
}

int set(struct Array arr,int index,int x){
    int i;
    if(index>=0&&index<arr.length){
            arr.A[index]=x;
    for(i=0;i<arr.length;i++){
        printf("%d ",arr.A[i]);
    }

    }
}
void max(struct Array arr){
    int max=arr.A[0];
    int i;
    for(i=1;i<arr.length;i++){
        if(arr.A[i]>max){
            max=arr.A[i];
        }

    }
    printf("max is %d ",max);

}
void min(struct Array arr){
    int min=arr.A[0];
    int i;
    for(i=1;i<arr.length;i++){
        if(arr.A[i]<min){
            min=arr.A[i];
        }

    }
    printf("\nmin is %d ",min);

}
void sum(struct Array arr){
    int sum=0;
    int i;
    for(i=0;i<arr.length;i++){
        sum=sum+arr.A[i];
    }
    printf("\nsum is %d ",sum);


}
void avg(struct Array arr){
    int sum=0;
    int i;
    for(i=0;i<arr.length;i++){
        sum=sum+arr.A[i];
    }
    printf("\naverage is %d ",sum/arr.length);


}

void reverse(struct Array arr){
    int B[arr.length];
    int i,j;
    for(i=arr.length-1,j=0;i>=0,j<arr.length;i--,j++){
        B[j]=arr.A[i];
    }
    for(i=0;i<arr.length;i++){
            arr.A[i]=B[i];

    }
    printf("\nprinting the reversed array\n");
    for(int i=0;i<arr.length;i++){
        printf("%d ",arr.A[i]);
    }

}
void reverseSwap(struct Array arr){
    int i,j,temp;
    for(i=0,j=arr.length-1;i<arr.length,j>=0;i++,j--){
        temp=arr.A[i];
        arr.A[i]=arr.A[j];
        arr.A[j]=temp;
    }
        printf("\nprinting the reversed array using swap\n");
        for(int i=0;i<arr.length;i++){
            printf("%d ",arr.A[i]);
    }

}

void insertInSortedArray(struct Array arr,int x){
    int i;
    for(i=arr.length-1;i>=0;i--){
        if(arr.A[i]>x){
            arr.A[i+1]=arr.A[i];
        }else{
        arr.A[i+1]=x;
        break;
        }

    }
    arr.length++;
    printf("\ninserting is sorted array\n");
    for(i=0;i<arr.length;i++){
        printf("%d ",arr.A[i]);
    }

}
int checkForSorted(struct Array arr){
    int i;
    for(i=0;i<arr.length-1;i++){
        if(arr.A[i]<arr.A[i+1])
            return 1;
        else{
            return 0;
            break;
        }
    }


}
void arrangeNegOnLeft(struct Array arr){
    int i=0;
    int j=arr.length-1;
    int temp;
    while(i<j)
    {
        while(arr.A[i]<0){i++;}
        while(arr.A[j]>0){j--;}

        if(i<j){
            temp=arr.A[i];
            arr.A[i]=arr.A[j];
            arr.A[j]=temp;
        }
    }
    for(i=0;i<arr.length;i++){
        printf("%d ",arr.A[i]);
    }
}

void SortedMerge(struct Array arr){
    int B[]={48,54,63,82,91};
    int C[15];
    int i=0;
    int j=0;
    int k=0;
    while(i<arr.length&&j<5){
        if(arr.A[i]<B[j]){
            C[k]=arr.A[i];
            i++;
            k++;
        }else{
            C[k]=B[j];
            j++;
            k++;

        }
    }
    for(;i<arr.length;i++){
        C[k]=arr.A[i];
        k++;
    }
    for(;i<arr.length;i++){
        C[k]=B[j];
        k++;
    }
    printf("\nMerged array is ");
    for(i=0;i<15;i++){
        printf("%d ",C[i]);
    }
}
void unionSetUnsorted(struct Array arr){
    int B[]={12,4,7,2,5};
    //int B[]={2,5,2,8};
    int C[15];
    int i=0,j=0,k=0;
    for(int i=0;i<arr.length;i++){
        C[k]=arr.A[i];

        k++;
    }
    int sizeofc=k;
    k=0;
    int earlyExit=0;
    for(j=0;j<5;j++){
        earlyExit=0;
        for(k=0;k<sizeofc;k++){
                if(B[j]==C[k]){
                    earlyExit=1;
                    break;
                }else{
                    continue;
                }

            }
            if(earlyExit==0){
                C[sizeofc]=B[j];
                sizeofc++;

            }
    }






    /*
    for(j=0;j<5;j++){

        if(B[j]==C[k]){
            //j++;
            k++;
        }else{
            for(i=arr.length;i<15;i++){
                C[i]=B[j];
                //j++;
                k++;
                break;
            }

        }
    }*/
    printf("\n unsorted Union");
    for(i=0;i<sizeofc;i++){
        printf("%d ",C[i]);
    }



}
void unionSetSorted(struct Array arr){
    int B[]={2,4,5,7,12};
    int C[15];
    int i=0;
    int j=0;
    int k=0;
    while(i<arr.length&&j<5){
        if(arr.A[i]<B[j]){
            C[k]=arr.A[i];
            i++;
            k++;
        }else if(arr.A[i]>B[j]){
            C[k]=B[j];
            j++;
            k++;

        }else{
            C[k]=arr.A[i];
            i++;
            j++;
            k++;
        }
    }
    for(;i<arr.length;i++){
        C[k]=arr.A[i];
        k++;
    }
    for(;j<5;j++){
        C[k]=B[j];
        k++;
    }
    printf("\nunion sorted is ");
    for(i=0;i<15;i++){
        printf("%d ",C[i]);
    }


}
void setIntersection(struct Array arr){
    int B[]={12,4,7,2,5};
    int C[10];
    int i=0;
    int j=0;
    int k=0;
    for(i=0;i<arr.length;i++){
        for(j=0;j<5;j++){
            if(arr.A[i]==B[j]){
                C[k]=arr.A[i];
                k++;
            }


        }
    }
    printf("\nintersection\n");
    for(i=0;i<k;i++){
        printf("%d ",C[i]);
    }





}
setIntersectionSorted(struct Array arr){
    int B[]={2,4,5,7,12};
    int C[15];
    int i=0;
    int j=0;
    int k=0;
    while(i<arr.length&&j<5){
        if(arr.A[i]<B[j]){
            //C[k]=arr.A[i];
            i++;
            //k++;
        }else if(arr.A[i]>B[j]){
            //C[k]=B[j];
            j++;
            //k++;

        }else{
            C[k]=arr.A[i];
            i++;
            j++;
            k++;
        }
    }
    for(;i<arr.length;i++){
        //C[k]=arr.A[i];
        k++;
    }
    for(;j<5;j++){
        //C[k]=B[j];
        k++;
    }
    int sizeofc=k;
    printf("\nunion sorted is ");
    for(i=0;i<sizeofc;i++){
        printf("%d ",C[i]);
    }




}

setDiffSorted(struct Array arr){
    int B[]={2,4,5,7,12};
    int C[15];
    int i=0;
    int j=0;
    int k=0;
    while(i<arr.length&&j<5){
        if(arr.A[i]<B[j]){
            C[k]=arr.A[i];
            i++;
            k++;
        }else if(arr.A[i]>B[j]){
            //C[k]=B[j];
            j++;
            //k++;

        }else{
            C[k]=arr.A[i];
            i++;
            j++;
            //k++;
        }
    }
    for(;i<arr.length;i++){
        //C[k]=arr.A[i];
        k++;
    }
    for(;j<5;j++){
        //C[k]=B[j];
        k++;
    }
    int sizeofc=k;
    printf("\nunion sorted is ");
    for(i=0;i<sizeofc-1;i++){
        printf("%d ",C[i]);
    }


}

void setDiff(struct Array arr){
    int B[]={12,4,7,2,5};
    int C[15];
    int i;
    int j;
    int k=0;
    int flag=0;
    for(i=0;i<arr.length;i++){
        flag=0;
        for(j=0;j<5;j++){
            if(arr.A[i]==B[j]){
                flag=1;
                //break;
            }else{
                continue;

            }

        }
        if(flag==0){
            C[k]=arr.A[i];
            k++;
        }
    }
    printf("\nDifference unsorted is ");
    for(i=0;i<15;i++){
        printf("%d ",C[i]);
    }

}




int main()
{
    struct Array arr;
    int n;
    int i;
    printf("Enter the size of array \n");
    scanf("%d",&arr.size);

    arr.A=malloc(arr.size*sizeof(int));
    arr.length=0;

    printf("Enter the number of elements you want to enter int the array \n");
    scanf("%d",&n);

    if(n>arr.size){
        printf("number of elements can be equal to or less than size of array");
    }else{
        for(i=0;i<n;i++){
            printf("enter element %d \n",i+1);
            scanf("%d",&arr.A[i]); //%d means it waits for an integer value
        }
        arr.length=n;
        printf("Menu \n");
        printf("Menu \n");
        printf("Menu \n");
        printf("Menu \n");
        printf("Menu \n");
        printf("Menu \n");
        printf("Menu \n");

    }
}
