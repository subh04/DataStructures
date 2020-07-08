#include <stdio.h>
#include <stdlib.h>
struct Node{
    struct Node *lchild;
    struct Node *rchild;
    int data;
    int h;
}*root=NULL;
struct Node *LLRo(struct Node *p){
    struct Node *pl=p->lchild;
    struct Node *plr=p->lchild->rchild;
    pl->rchild=p;
    p->lchild=plr;
    p->h=HeightNode(p);
    pl->h=HeightNode(pl);
    if(root==p)
        root=pl;
    return pl;

}
struct Node * RInsert(struct Node *p,int key){
    struct Node *t=NULL;
    if(p==NULL){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=key;
        t->lchild=t->rchild=NULL;
        t->h=1;
        return t;
    }
    if(key<p->data)
        p->lchild=RInsert(p->lchild,key);
    else if(key>p->data)
        p->rchild=RInsert(p->rchild,key);
    p->h=HeightNode(p);
    if(balanceFactor(p)==2&&balanceFactor(p->lchild)==1)
        return LLRo(p);
    return p;
}
int HeightNode(struct Node *p){
    int leftHeight,rightHeight;
    if(p==NULL){
        return 0;

    }
    leftHeight=HeightNode(p->lchild);
    rightHeight=HeightNode(p->rchild);
    if(leftHeight>rightHeight)
        return leftHeight+1;
    else
        return rightHeight+1;
}
int balanceFactor(struct Node *p){
    int leftHeight,rightHeight;
    if(p==NULL){
        return 0;

    }
    leftHeight=HeightNode(p->lchild);
    rightHeight=HeightNode(p->rchild);
    return leftHeight-rightHeight;

}


int main()
{
    struct Node *firstNode=NULL;
    root=RInsert(root,5);
    RInsert(root,3);
    RInsert(root,1);
    return 0;
}
