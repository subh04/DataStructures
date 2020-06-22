#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
}*first=NULL; //first is globally available as a pointer to access this now we have to use -> arrow

void create(int A[],int n){
    int i;
    struct Node *t,*last;
    first=(struct Node*)malloc(sizeof(struct Node));

    first->data=A[0];
    first->next=NULL;
    last=first; //last sees the address inside of first
    for(i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;//here when it links with the new node
        last=t;

    }
}
void display(struct Node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }

}

void recursiveDisplay(struct Node *p){
    if(p!=NULL){
        printf("%d ",p->data);
        recursiveDisplay(p->next);
    }

}



void reverseRecursiveDisplay(struct Node *p){
    if(p!=NULL){

        reverseRecursiveDisplay(p->next);
        printf("%d ",p->data);

    }

}
int countNodes(struct Node *p){
    int c=0;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    return c;
}
int recursiveCountNodes(struct Node *p){
    static int c=0;
    if(p!=NULL){
        c++;
        recursiveCountNodes(p->next);
    }
    return c;
}
int sumOfElementsR(struct Node *p){
    static int sum=0;
    if(p!=NULL){
        sum=sum+p->data;
        sumOfElementsR(p->next);
    }
    return sum;
}
int sumOfElements(struct Node *p){
    static int sum=0;
    while(p!=NULL){
        sum=sum+p->data;
        p=p->next;
    }
    return sum;
}
int main()
{
    int A[]={3,5,7,10,15};
    create(A,5);
    display(first);
    printf("\n");
    recursiveDisplay(first);
    printf("\n");
    reverseRecursiveDisplay(first);
    printf("\nnumber of elements are %d",countNodes(first));
    printf("\nnumber of elements using recursion are %d",recursiveCountNodes(first));
    printf("\nsum of elements using recursion are %d",sumOfElementsR(first));
    printf("\nsum of elements is %d",sumOfElements(first));
    return 0;
}
