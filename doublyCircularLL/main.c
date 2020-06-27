#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *prev;
    struct Node *next;
    int data;
}*head,*last;
void create(int A[],int n){
    struct Node *t;
    head=(struct Node *)malloc(sizeof(struct Node));
    int i;
    head->data=A[0];
    head->next=head;
    head->prev=head;
    last=head;
    for(i=1;i<n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=head;
        head->prev=t;
        t->prev=last;
        last->next=t;

        last=t;



    }

}
void insert(struct Node *h,int pos,int data){
    struct Node *t;
    if(pos==0){
        if(h==NULL){
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=data;
            t->next=t;
            t->prev=t;
            head=t;
        }

        h=head->prev;

        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=data;
        h->next=t;
        t->prev=h;
        t->next=head;
        head->prev=t;
        head=t;

    }else{
        int i;
        for(i=0;i<pos-1;i++){
            h=h->next;
        }
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=data;
        t->next=h->next;
        h->next->prev=t;
        t->prev=h;
        h->next=t;

    }
}
void display(struct Node *h){
    do{
        printf("%d ",h->data);
        h=h->next;
    }while(h!=head);
}
void displayRev(struct Node *h){
    do{
        printf("%d ",h->data);
        h=h->prev;
    }while(h!=head);

}
void deleteElement(struct Node *h,int pos){
    int i;
    if(pos==1){
        head=head->next;
        h->prev->next=head;
        head->prev=h->prev;

        free(h);
    }else{
        for(i=0;i<pos-1;i++){
            h=h->next;
        }
        h->prev->next=h->next;
        h->next->prev=h->prev;
        free(h);
    }
}

int main()
{
    int A[]={2,4,7,9,10};
    create(A,5);
    display(head);
    insert(head,0,999);
    printf("\n");
    display(head);
    insert(head,2,1111);
    printf("\n");
    display(head);
    deleteElement(head,2);
    printf("\n");
    display(head);
    deleteElement(head,1);
    printf("\n");
    display(head);
    return 0;
}
