#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
}*first=NULL,*second=NULL; //first is globally available as a pointer to access this now we have to use -> arrow

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
int Maximum(struct Node *p){
    int max=-32768;
    while(p!=NULL){
        if(p->data>max){
            max=p->data;
            p=p->next;
        }
    }
    return max;
}
int RMaximum(struct Node *p){
    int static max=-32768;
    if(p!=NULL){
        if(p->data>max){
            max=p->data;
            RMaximum(p->next);
            }else{
                RMaximum(p->next);
            }
    }
    return max;
}
void linearSearchLL(struct Node *p,int key){
    while(p!=NULL){
        if(p->data==key){
            printf("found AT %d",p);
            break;
        }else{
            p=p->next;
        }
    }
    if(p==NULL){
    printf("not found");
    }
}
void RLinearSearch(struct Node *p,int key){
    if(p!=NULL){
        if(p->data==key){
            printf("found AT %d",p);
        }else{
            RLinearSearch(p->next,key);
        }
    }
    else{
        printf("not found");
    }
}
void improvedLinearSearchUsingMoveToHeader(struct Node *p,int key){
        struct Node *q=NULL;
        if(p==NULL){
            return;
        }
        if(p->data==key){
            printf("found");
            return;
        }
        while(p!=NULL){
            if(p->data==key){
                q->next=p->next;
                p->next=first;
                first=p;
                printf("found AT %d",p);
                break;
            }else{
                q=p;
                p=p->next;
            }
        }
        if(p==NULL){
            printf("not found");
        }
}
void insert(struct Node *p,int afterPos,int data){
    int i;
    if(afterPos<0||afterPos>countNodes(p))
        return;
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=data;
    if(afterPos==0){
        t->next=first;  /*------------*/
        first=t;
    }else{
        for(i=0;i<afterPos-1;i++){
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }

}
/*
void insertInEnd(struct Node *p,int data){
    struct Node *t,*last;
    int i;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=data;
    if(p==NULL)
        first=last=t;
    else{
        while(p!=NULL){
            p=p->next;
        }
        if(p==NULL){
            last=p;

        }
        last->next=t;
        last=t;
    }


}
*/
void insertInSorted(struct Node *p,int data){
    struct Node *q=NULL,*t;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=data;
    t->next=NULL;
    if(p==NULL){

        first=t;
        return;

    }
    if(p->data>data){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=data;
        t->next=first;
        first=t;

        return;

    }
    while(p!=NULL && p->data<data){
        q=p;
        p=p->next;
    }
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=data;
    t->next=q->next;
    q->next=t;


}
void deleteFromLL(struct Node *p,int pos){
    struct Node *q=NULL;
    int i;
    if(p==NULL){
        printf("nothing to delete\n");
        return;
    }
    if(pos<0 || pos>countNodes(p)){
        printf("\ninvalid position");
        return;
    }
    if(pos==1){

        first=p->next;
        free(p);
    }else{
        for(i=0;i<pos-1;i++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        free(p);

    }
}
void isSorted(struct Node *p){
        int x=-32768;
        if(p==NULL){
            printf("nothing to check\n");
            return;
        }
        while(p!=NULL){
            if(p->data>=x){
                x=p->data;
                p=p->next;
            }else{
                printf("\nthe list is not sorted\n");
                return;
            }

        }
        printf("\nlist is sorted");
}
void removeRedundant(struct Node *p){
    struct Node *q=p->next;
    if(p==NULL){
        printf("nothing to check");
        return;
    }
    while(q!=NULL){
        if(p->data==q->data){
            p->next=q->next;
            free(q);
            q=p->next;
        }else{
            p=q;
            q=q->next;

        }
    }
}

void reverseElements(struct Node *p){
    int A[countNodes(p)];
    int i;
    for(i=0;i<countNodes(first);i++){
        A[i]=p->data;
        p=p->next;
    }
    printf("\nprinting array\n");
    p=first;
    for(i=0;i<countNodes(p);i++){
        printf("%d ",A[i]);
    }
    printf("\n");
    for(i=countNodes(first)-1;i>=0;i--){
        p->data=A[i];
        p=p->next;
    }
    p=first;
    printf("\nreversed using elements\n");
    display(p);
}
void reverseLinksUsingSlidingPointers(struct Node *p){
    struct Node *q=NULL,*r=NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
    printf("\nreversed using links\n");
    display(first);
}
void RReverse(struct Node *q,struct Node *p){
    if(p!=NULL){
        RReverse(p,p->next);
        p->next=q;

    }else{
        first=q;

    }
    //printf("\nrecursive reversing\n");
    //display(first);


}
void concatenate(struct Node *p){
    int B[]={900,1000,2000};
    struct Node *t,*last,*q=NULL;
    int i,n=3;
    second=(struct Node*)malloc(sizeof(struct Node));
    second->data=B[0];
    second->next=NULL;
    last=second;
    for(i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=B[i];
        t->next=NULL;
        last->next=t;//here when it links with the new node
        last=t;

    }
    //printf("\n");
    //display(second);
    while(p!=NULL){
        q=p;
        p=p->next;
    }

        q->next=second;


    printf("\nconcatenated linked list\n");
    display(first);

}
int main()
{
    struct Node *q=NULL;

    int A[]={3,5,7,10,15};
    int key,key2,key3,afterPos;
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
    printf("\nthe max element is %d",Maximum(first));
    printf("\nthe max element using recursion is %d",RMaximum(first));
    printf("\nplease enter a key to find ");
    scanf("%d",&key);
    linearSearchLL(first,key);
    printf("\nplease enter a key to find using recursion ");
    scanf("%d",&key2);
    RLinearSearch(first,key2);
    printf("\nplease enter a key to find using improved search ");
    scanf("%d",&key3);
    improvedLinearSearchUsingMoveToHeader(first,key3);
    printf("\n");
    display(first);
    printf("\nplease enter a key to find using improved search ");
    scanf("%d",&key3);
    improvedLinearSearchUsingMoveToHeader(first,key3);
    printf("\n");
    display(first);
    printf("enter position after which to enter ");
    scanf("%d",&afterPos);
    insert(first,afterPos,3);
    printf("\n");
    display(first);
    printf("enter position after which to enter ");
    scanf("%d",&afterPos);
    insert(first,afterPos,5);
    printf("\n");
    display(first);
    printf("\ninserted after node %d",afterPos);
    //insertInEnd(first,400);
    //printf("\n");
    //display(first);
    insertInSorted(first,2);
    printf("\n");
    display(first);
    deleteFromLL(first,-1);
    printf("\nafter deletion\n");
    display(first);
    deleteFromLL(first,4);
    printf("\nafter deletion\n");
    display(first);
    isSorted(first);
    printf("\n");
    display(first);
    //removeRedundant(first);
    //printf("\n");
    //display(first);
    printf("\n");

    printf("\n%d",countNodes(first));
    reverseElements(first);
    printf("\n");
    reverseLinksUsingSlidingPointers(first);
    printf("\n");
    RReverse(q,first);
    printf("\nreversed using recursion\n");
    display(first);
    concatenate(first);
    //display(first);
    return 0;
}
