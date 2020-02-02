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
//����������������ڵ�ֵ��#�������
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
//��������������ĵݹ��㷨
    Status preOrderTraverse(BiTree T)
    {
        if(T)
        {
            cout<<T->data<<"\t";
            preOrderTraverse(T->lchild);
            preOrderTraverse(T->rchild);
        }
    }
//���� �����������ĵݹ��㷨
Status inOrderTraverse(BiTree T)
    {
        if(T)
        {
            inOrderTraverse(T->lchild);
            cout<<T->data<<"\t";
            inOrderTraverse(T->rchild);
        }
    }
//��������������ĵݹ��㷨
Status postOrderTraverse(BiTree T)
    {
        if(T)
        {
            postOrderTraverse(T->lchild);
            postOrderTraverse(T->rchild);
            cout<<T->data<<"\t";
        }
    }
//�������������
/*
��Ҫ�õ����и���ʵ��
�������ң����ϵ��£��������
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
