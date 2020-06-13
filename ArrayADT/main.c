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

        int c=LinearSearch(&arr,44);


        printf("\nThe elements of array after linear search with transposition improvement\n");


        display(arr);
        printf("\nfound at %d\n",c);


    }



}
