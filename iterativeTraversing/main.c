#include <stdio.h>
#include <stdlib.h>
struct stack{
    struct Node  **s;
    int top;
    int size;
};
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
void push(struct stack *st,struct Node * x){
    if(st->top==st->size-1){
        printf("stack overflow\n");
    }else{
        st->top++;
        st->s[st->top]=x;
    }
}
void display(struct stack st){
    int i;
    for(i=st.top;i>=0;i--){
        printf("%d ",st.s[i]);
    }
}
struct Node * pop(struct stack *st){
    struct Node * x =NULL;
    if(st->top==-1){
        printf("\nnothing to delete");
    }else{
        x=st->s[st->top];
        st->top--;
    }
    //printf("\n");
    return x;
}
int peek(struct stack st,int index){
    if(st.top-index+1<0){
        printf("\ninvalid index");
        return 0;
    }else{
        return st.s[st.top-index+1];
    }
}
void stackTop(struct stack st){
    if(st.top==-1){
        printf("\nstack has no elements yet");
    }else{
        printf("\nthe top element is %d",st.s[st.top]);
    }
}
int isEmptyStack(struct stack st){
    if(st.top==-1){
        //printf("\nno elements in the stack yet");
        return 1;
    }else{
       // printf("\nstack is not empty");
        return 0;
    }
}
void isFull(struct stack st){
    if(st.top==st.size-1){
        printf("\nstack is full");
    }else{
        printf("\nstack is not full");
    }
    printf("\n");
}
void Ipreorder(struct Node *p){
    struct stack stk;
    stk.size=20;
    stk.s=(struct Node **)malloc(stk.size*sizeof(struct Node*));
    stk.top=-1;
    while(p!=NULL||!isEmptyStack(stk)){
        if(p!=NULL){
            printf("%d ",p->data);
            push(&stk,p);
            p=p->lchild;
        }else{
            p=pop(&stk);
            p=p->rchild;
        }
    }
}
void Iinorder(struct Node *p){
    struct stack stk;
    stk.size=20;
    stk.s=(struct Node **)malloc(stk.size*sizeof(struct Node*));
    stk.top=-1;
    while(p!=NULL||!isEmptyStack(stk)){
        if(p!=NULL){
            push(&stk,p);
            p=p->lchild;
        }else{
            p=pop(&stk);
            printf("%d ",p->data);
            p=p->rchild;
        }
    }
}
void IPostnorder(struct Node *p){
    struct stack stk;
    long int temp;
    stk.size=20;
    stk.s=(struct Node **)malloc(stk.size*sizeof(struct Node*));
    stk.top=-1;
    while(p!=NULL||!isEmptyStack(stk)){
        if(p!=NULL){
            push(&stk,p);
            p=p->lchild;
        }else{
            temp=pop(&stk);
            if(temp>0){
                push(&stk,-temp);
                p=((struct Node *)temp)->rchild;
            }else{
                printf("%d ",((struct Node *)(-temp))->data);
                p=NULL;
            }
        }
    }
}
int main()
{

    int pos;
    createTree();
    printf("PREORDER TRAVERSAL\n");
    preorder(root);
    printf("\nINORDER TRAVERSAL\n");
    inorder(root);
    printf("\nPOSTORDER TRAVERSAL\n");
    postorder(root);
    printf("\nITERATIVE PREORDER TRAVERSAL\n");
    Ipreorder(root);
    printf("\nITERATIVE INORDER TRAVERSAL\n");
    Iinorder(root);
    printf("\nITERATIVE POSTORDER TRAVERSAL\n");
    IPostnorder(root);

    return 0;
}
