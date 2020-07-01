#include <stdio.h>
#include <stdlib.h>
struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};
void create(struct Queue *q){
    printf("enter the size of the queue\n");
    scanf("%d",&q->size);
    q->front=q->rear=0;
    q->Q=(int *)malloc(q->size*sizeof(int));
}
void enqueue(struct Queue *q,int x){
    if((q->rear+1)%q->size==q->front){
        printf("stack is full\n");
    }else{
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}
void dequeue(struct Queue *q){
    if(q->front==q->rear){
        printf("stack is empty,nothing to delete\n");

    }else{
        q->front=(q->front+1)%q->size;

    }
}
void display(struct Queue *q){
    int i=q->front+1;
    if(q->front==q->rear){
        printf("nothing to display\n");
    }else{
        do{
            printf("%d ",q->Q[i]);
            i=(i+1)%q->size;
        }while(i!=(q->rear+1)%q->size);

        printf("\n");
    }
}
int main()
{
    struct Queue q;
    create(&q);
    enqueue(&q,1);
    enqueue(&q,2);
    enqueue(&q,3);
    enqueue(&q,4);
    dequeue(&q);
    enqueue(&q,5);
    display(&q);
    return 0;
}
