#include <stdio.h>
#include <stdlib.h>
struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root=NULL;
void insert(int key){
    struct Node *p,*t=root,*q;
    if(root==NULL){
        p=(struct Node *)malloc(sizeof(struct Node));
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;
        return;
    }
    while(t!=NULL){
        q=t;
        if(key>t->data){
            t=t->rchild;
            //return;
            }
        else if(key<t->data){
            t=t->lchild;
            //return;
            }
        else{
            printf("the values %d you wanna insert already exists\n");
            //return;
            }
    }
    p=(struct Node *)malloc(sizeof(struct Node));
    p->data=key;
    p->lchild=p->rchild=NULL;
    if(key<q->data)
        q->lchild=p;
    else
        q->rchild=p;


}
void inorder(struct Node *p){
    if(p!=NULL){
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}
void search(struct Node *p,int key){
    if(root==NULL)
        printf("\nthe tree is empty,nothing to find");
    while(p!=NULL){
        if(p->data==key){
            printf("\nelement %d found in the tree\n",p->data);
            return;
        }else if(key>p->data){
            p=p->rchild;
        }else{
            p=p->lchild;
        }
    }
    printf("\nkey not found\n");
}
int main()
{
    insert(20);
    insert(32);
    insert(2);
    insert(89);
    insert(54);
    insert(-2);
    inorder(root);
    //printf("\n");
    search(root,-2);
    search(root,20);
    search(root,111);
    //printf("Hello world!\n");
    return 0;
}
