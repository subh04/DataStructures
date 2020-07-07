#include <stdio.h>
#include <stdlib.h>
struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root=NULL,*rootNew=NULL;
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
struct Node * rInsert(struct Node * p,int key){
    struct Node *t=NULL;
    if(p==NULL){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=key;
        t->lchild=t->rchild=NULL;
        return t;
    }
    if(key<p->data)
        p->lchild=rInsert(p->lchild,key);
    else if(key>p->data)
        p->rchild=rInsert(p->rchild,key);

    return;
};
int height(struct Node * p){
    int x,y;
    if(p==NULL)
        return 0;
    x=height(p->lchild);
    y=height(p->rchild);
    if(x>y)
        return x+1;
    else
        return y+1;
}
struct Node * InPre(struct Node * p){
    while(p!=NULL&&p->rchild!=NULL)
        p=p->rchild;
    return p;
}
struct Node * InSucc(struct Node * p){
    while(p!=NULL&&p->lchild!=NULL)
        p=p->lchild;
    return p;
}
struct Node * delete(struct Node *p,int key){
    struct Node *q=NULL;
    if(p==NULL)
        return NULL;
    if(p->lchild==NULL&&p->rchild==NULL){
        if(p==root){
            root=NULL;
        }
        free(p);
        return NULL;

    }
    if(key<p->data)
        p->lchild=delete(p->lchild,key);
    else if(key>p->data)
        p->rchild=delete(p->rchild,key);
    else{
        if(height(p->lchild)>height(p->rchild)){
            q=InPre(p->lchild);
            p->data=q->data;
            p->lchild=delete(p->lchild,q->data);
        }else{
            q=InSucc(p->rchild);
            p->data=q->data;
            p->rchild=delete(p->rchild,q->data);
        }
    }
    return p;
}
int main()
{
    insert(30);
    insert(20);
    insert(40);
    insert(10);
    insert(25);
    insert(35);
    insert(45);
    insert(42);
    insert(43);
    inorder(root);
    //printf("\n");
    search(root,-2);
    search(root,20);
    search(root,111);
    //printf("Hello world!\n");
    rootNew=rInsert(rootNew,30);
    rInsert(rootNew,20);
    rInsert(rootNew,40);
    rInsert(rootNew,10);
    rInsert(rootNew,25);
    rInsert(rootNew,35);
    rInsert(rootNew,45);
    rInsert(rootNew,42);
    rInsert(rootNew,43);
    inorder(rootNew);
    search(root,20);
    delete(root,42);
    printf("after deletion\n");
    inorder(root);
    //Insert(rootNew,30);
    return 0;
}
