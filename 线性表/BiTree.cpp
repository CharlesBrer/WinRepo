#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<queue>

using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -1

typedef int Status;
typedef char ElemType;

typedef struct BiTNode{
    ElemType data;
    struct BiTNode* lchild,* rchild;
}BiTNode,*BiTree;
//按先序输入二叉树节点值，#代表空树
Status createBiTree(BiTree &T)
{
    ElemType data ;
    cin>>data;
    if(data=='#')
    {
        T=NULL;
    }
    else
    {
        T=(BiTree)malloc(sizeof(BiTNode));
        T->data=data;
        createBiTree(T->lchild);
        createBiTree(T->rchild);
    }
    return OK;
}
//先序遍历二叉树的递归算法
    Status preOrderTraverse(BiTree T)
    {
        if(T)
        {
            cout<<T->data<<"\t";
            preOrderTraverse(T->lchild);
            preOrderTraverse(T->rchild);
        }
    }
//中序 遍历二叉树的递归算法
Status inOrderTraverse(BiTree T)
    {
        if(T)
        {
            inOrderTraverse(T->lchild);
            cout<<T->data<<"\t";
            inOrderTraverse(T->rchild);
        }
    }
//后序遍历二叉树的递归算法
Status postOrderTraverse(BiTree T)
    {
        if(T)
        {
            postOrderTraverse(T->lchild);
            postOrderTraverse(T->rchild);
            cout<<T->data<<"\t";
        }
    }
//层序遍历二叉树
/*
需要用到队列辅助实现
从左向右，从上到下，依次入队
*/
Status levelOrderTraverse(BiTree T)
{
    if(T)
    {
        queue<BiTree> q;
        BiTree p;
        q.push(T);
        while(!q.empty()){
            p=q.front();
            cout<<p->data<<"\t";
            q.pop();
            if(p->lchild) q.push(p->lchild);
            if(p->rchild) q.push(p->rchild);

        }
    }
}
int main(){
    BiTree T;
    createBiTree(T);
    preOrderTraverse(T);
    cout<<endl;
    inOrderTraverse(T);
    cout<<endl;
    postOrderTraverse(T);
    cout<<endl;
    levelOrderTraverse(T);
return 0;
}
