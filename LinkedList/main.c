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
int main()
{

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
    insert(first,afterPos,100);
    printf("\n");
    display(first);
    printf("enter position after which to enter ");
    scanf("%d",&afterPos);
    insert(first,afterPos,999);
    printf("\n");
    display(first);
    printf("\ninserted after node %d",afterPos);
    //insertInEnd(first,400);
    //printf("\n");
    //display(first);
    insertInSorted(first,2);
    printf("\n");
    display(first);
    return 0;
}
