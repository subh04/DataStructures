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

        /*printf("length before append %d \n",arr.length);

        append(&arr,741); //call by address
        printf("length after append %d \n",arr.length);

        insert(&arr,3,999); //call by address
        printf("length after insert %d \n",arr.length);

        delete(&arr,3); //call by address
        printf("length after delete %d \n",arr.length);*/



        display(arr);

        int c=BinarySearch(arr,arr.length-1,0,5);
        printf("\nfound at %d\n",c);

        /*

        int c=LinearSearch(&arr,44);


        printf("\nThe elements of array after linear search with transposition improvement\n");


        display(arr);
        printf("\nfound at %d\n",c);

        */
        printf("getting index value of index %d\n%d\n",6,get(arr,2));

        printf("\nsetting value of index %d\n",3,set(arr,3,47));

        //max(arr);
        //min(arr);
       // sum(arr);
        //avg(arr);
        //reverse(arr);
        //reverseSwap(arr);
        insertInSortedArray(arr,25);




    }



}
