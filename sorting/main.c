#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
}*first=NULL,*last=NULL;
void swap(int *a,int *b){
    int temp;

        temp=*a;
        *a=*b;
        *b=temp;

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
    int i=l,j=h+1,pivot=A[l];
    do{
        do{i++;}while(A[i]>=pivot&&i<h);
        do{j--;}while(A[j]<pivot&&j>l);
        if(i<j)
            swap(&A[i],&A[j]);


    }while(i<j);
    swap(&A[l],&A[j]);

    return j;

}
void quickSort(int A[],int l,int h){
    int x;
    if(l<h){
        x=partition(A,l,h);
        quickSort(A,l,x);
        quickSort(A,x+1,h);
    }

}
void singleListMerge(int A[],int l,int mid,int h){
    int *B=(int *)malloc((h+1)*sizeof(int));
    int i=l,j=mid+1,k=l;
    while(i<=mid&&j<=h){
        if(A[i]>A[j]){
            B[k]=A[i];
            k++;
            i++;
        }else{
            B[k]=A[j];
            k++;
            j++;
        }
    }
    for(;i<=mid;i++){
        B[k]=A[i];
        k++;
    }
    for(;j<=h;j++){
        B[k]=A[j];
        k++;
    }
    for(i=l;i<=h;i++){
        A[i]=B[i];
    }
}
void IMergeSort(int A[],int n){
    int p,i,l,mid,h;
    for(p=2;p<=n;p=p*2){
        for(i=0;i+p-1<n;i=i+p){
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            singleListMerge(A,l,mid,h);
        }
    }
    if(p/2<n)
        singleListMerge(A,0,p/2-1,n-1);
    printf("\nIterative Merge sort");
    display(A,n);
}
void shellSort(int A[],int n){
    int gap,i,j,temp,flag=0,x,y;
    for(gap=(n-1)/2;gap>=1;gap=gap/2){
        for(i=gap;i<n;i++){
            x=i;
            temp=A[i];
            j=i-gap;
            while(j>=0&&A[j]<temp){


                //flag=0;
                A[x]=A[j];
                x=x-gap;
                j=j-gap;




            }
            A[j+gap]=temp;

        }
    }

}
void display(int A[],int n){
    int i;
    for(i=0;i<n;i++){
        printf(" %d ",A[i]);
    }
    printf("\n");
}
int main()
{
    int A[]={8,7,6,5,4,3,2,1},n=8;

    BubbleSort(A,n);
    correctInsertionSort(A,n);
    selectionSort(A,n);
    quickSort(A,0,n-1);
    printf("\nQuick Sort");
    display(A,n);

    IMergeSort(A,n);

    shellSort(A,n);
    printf("\nShell Sort");
    display(A,n);

    return 0;
}
