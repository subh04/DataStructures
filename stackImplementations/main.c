#include <stdio.h>
#include <stdlib.h>
struct stack{
    struct Node  **s;
    int top;
    int size;
};
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
    printf("\n");
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
void isEmpty(struct stack st){
    if(st.top==-1){
        printf("\nno elements in the stack yet");
    }else{
        printf("\nstack is not empty");
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
int main()
{
    struct stack st;
    int pos;
    printf("enter the size of the stack ");
    scanf("%d",&st.size);
    st.s=(struct stack *)malloc(st.size*sizeof(int));
    st.top=-1;
    push(&st,2);
    push(&st,4);
    push(&st,6);
    push(&st,8);
    push(&st,10);
    //push(&st,12);
    display(st);
    pop(&st);
    display(st);
    printf("\nenter the position of the index you wanna see ");
    scanf("%d",&pos);
    printf("\nthe element in the given index %d is %d",pos,peek(st,pos));
    stackTop(st);
    isEmpty(st);
    push(&st,12);
    isFull(st);
    display(st);
    return 0;
}
