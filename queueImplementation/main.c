#include <stdio.h>
#include <stdlib.h>
struct Queue{
    int front;
    int rear;
    int size;
    int *Q;
};
void enqueue(struct Queue *q,int x){
    if(q->rear==q->size-1){
        printf("cannot enter,the queue is full\n");
    }else{
        q->rear++;
        q->Q[q->rear]=x;
    }
}
int dequeue(struct Queue *q){
    int x=-9999;
    if(q->front==q->rear){
        printf("nothing to delete\n");
    }else{
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}
void display(struct Queue *q){
    int i;
    if(q->front==q->rear){
        printf("\nNothing to display");
    }
    for(i=q->front+1;i<=q->rear;i++){
        printf("%d ",q->Q[i]);
    }
    printf("\n");
}
int main()
{
    struct Queue q;
    printf("enter the size\n");
    scanf("%d",&q.size);
    q.Q=(int *)malloc(q.size*sizeof(int));
    q.front=q.rear=-1;
    enqueue(&q,2);

    enqueue(&q,3);

    enqueue(&q,3);

    display(&q);

    dequeue(&q);

    display(&q);

    enqueue(&q,3);
    enqueue(&q,3);
    enqueue(&q,3);
    display(&q);

    return 0;
}
