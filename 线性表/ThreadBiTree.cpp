#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;

typedef char ElemType;

typedef struct TBNode
{
    ElemType data;
    int ltag,rtag;
    struct TBNode* lchild;
    struct TBNode* rchild;
}TBNode,*TBiTree;

Status createThreadBiTree(TBiTree &T)
{
    ElemType ch;
    cin>>ch;
    if(ch=='#') T=NULL;
    else {
        T->data=ch;
        createThreadBiTree(T->lchild); T->ltag=(T->lchild)?0:1;
        createThreadBiTree(T->rchild); T->rtag=(T->rchild)?0:1;
    }
    return OK;
}

Status inOrderTraverse(TBiTree T)
{
    if(T==NULL) return ERROR;
        inOrderTraverse(T->lchild);
        cout<<T->data<<" "<<T->ltag<<" "<<T->rtag<<endl;
        inOrderTraverse(T->rchild);
    return OK;
}

int main(){
TBiTree T;
createThreadBiTree(T);

inOrderTraverse(T);


return 0;
}
