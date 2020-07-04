#include <stdio.h>
#include <stdlib.h>
struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root=NULL;
struct Queue{
    int size;
    int front;
    int rear;
    struct Node **Q;
};
void createQueue(struct Queue *q,int size){
    q->size=size;
    q->front=q->rear=0;
    q->Q=(struct Node **)malloc(q->size*sizeof(struct Node *));
}
void enqueue(struct Queue *q,struct Node * x){
    if((q->rear+1)%q->size==q->front){
        printf("queue is full");
    }else{
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}
struct Node * dequeue(struct Queue *q){
    struct Node *x=NULL;
    if(q->front==q->rear){
        printf("queue is empty");
    }else{

        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;

}
int isEmpty(struct Queue q){
    if(q.front==q.rear){
        return 1;
    }else
        return 0;
}
void createTree(){
    struct Node *p,*t;
    int x;
    struct Queue q;
    createQueue(&q,100);
    printf("enter the values of the root\n");
    scanf("%d",&x);
    if(x!=-1){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        t->lchild=t->rchild=NULL;
        root=t;
        enqueue(&q,root);
    }
    while(!isEmpty(q)){
        p=dequeue(&q);
        printf("enter the value of the left child of %d ",p->data);
        scanf("%d",&x);
        if(x!=-1){
           t=(struct Node *)malloc(sizeof(struct Node));
           t->data=x;
           t->lchild=t->rchild=NULL;
           p->lchild=t;
           enqueue(&q,t);
        }
        printf("enter the value of the right child of %d ",p->data);
        scanf("%d",&x);
        if(x!=-1){
           t=(struct Node *)malloc(sizeof(struct Node));
           t->data=x;
           t->lchild=t->rchild=NULL;
           p->rchild=t;
           enqueue(&q,t);
        }

    }
}
void preorder(struct Node *p){

    if(p!=NULL){
        printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);

    }
}
void inorder(struct Node *p){

    if(p!=NULL){

        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);

    }
}
void postorder(struct Node *p){
    //printf("POSTORDER TRAVERSAL\n");
    if(p!=NULL){

        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ",p->data);

    }
}
int main()
{
    createTree();

    printf("PREORDER TRAVERSAL\n");
    preorder(root);
    printf("\nINORDER TRAVERSAL\n");
    inorder(root);
    printf("\nPOSTORDER TRAVERSAL\n");
    postorder(root);
    //sprintf("Hello world!\n");
    return 0;
}
