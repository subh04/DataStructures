#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
}*first=NULL,*last=NULL;
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
    printf("\nBubble Sort");
    display(A,n);

}
void insertionSort(struct Node *A[],int n,int x){
    struct Node *t,*p;
    int i;
    BubbleSort(A,n);
    display(A,n);
    //
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    p=last=first;
    //printf("%d",last->data);
    for(i=1;i<n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        p->next=t;
        p=p->next;
        last=t;

    }
    displayLL(first);
    struct Node *q=NULL;
    p=first;
    while(p!=NULL){
        if(p->data>x){
            q=p;
            p=p->next;
            //q->data=x;
            //q->next=p;

        }else if(p->data<=x){
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->next=p;


            if(q==NULL){
                //t->next=p;
                first=t;

            }else{
                q->next=t;
            }
            break;


        }
    }
    if(p==NULL){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        t->next=NULL;
        q->next=t;
        last=t;
    }
    displayLL(first);


}
void correctInsertionSort(int A[],int n){
    int i,x,j;
    for(i=1;i<n;i++){
        j=i-1;
        x=A[i];
        while(j>-1&&A[j]<x){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
    printf("\nInsertion sort");
    display(A,n);
}
void displayLL(struct Node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
void selectionSort(int A[],int n){
    int i,j,k;
    for(i=0;i<n-1;i++){
        for(j=k=i;j<n;j++){
            if(A[j]>A[k])
                k=j;
        }
        swap(&A[k],&A[i]);
    }
    printf("\nSelection Sort");
    display(A,n);
}
int partition(int A[],int l,int h){
    int i=l,j=h,pivot=A[l];
    do{
        do{i++;}while(A[i]<=pivot);
        do{j--;}while(A[j]>pivot);
        if(i<j)
            swap(&A[i],&A[j]);

    }while(i<j);
    swap(&A[l],&A[j]);
    return j;

}
void quickSort(int A[],int l,int h){
    int j;
    if(l<h){
        j=partition(A,l,h);
        quickSort(A,l,j);
        quickSort(A,j+1,h);
    }

}
void display(int A[],int n){
    int i;
    for(i=1;i<n;i++){
        printf(" %d ",A[i]);
    }
    printf("\n");
}
int main()
{
    int A[]={24,45,12,33,65535},n=5;
    BubbleSort(A,n);
    correctInsertionSort(A,n);
    selectionSort(A,n);
    quickSort(A,0,n-1);
    printf("\nQuick Sort");
    display(A,n);

    //insertionSort(A,n,100);
    //insertionSort(A,n,2);
    //
    return 0;
}
