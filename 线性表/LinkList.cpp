#include<cstdio>
#include<cstdlib>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode* next;
} LNode,*LinkList;

Status InitList(LinkList &L)
{
    L=(LinkList)malloc(sizeof(LNode));
    if(!L) exit(OVERFLOW);
    L->data=0;
    L->next=NULL;
}//InitList

Status InsertElem(LinkList &L,int i,ElemType e)
{//ָ��λ��֮ǰ����Ԫ��
    LinkList *newNode,*p=L;
    int j=0;
    while(p->next&&j<i-1)
    {
        p=p->next; ++j;
    }
    if(p->next||j>i-1) return ERROR;
    newNode=(LinkList)malloc(sizeof(LNode));
    newNode->next=p->next;
    p->next=newNode;
    newNode->data=e;
    return OK;
}

Status DeleteElem(LinkList &L,int i,ElemType &e)
{//ɾ��ָ��λ�õ�Ԫ��
    LinkList *q,*p=L;
    int j=0;
    while(p->next&&j<i-1)
    {
        p=p->next; ++j;
    }
    if(p->next||j>i-1) return ERROR;
    q=p->next; e=q->data;
    p->next=q->next;
    free(q);
    return OK;
}

Status GetElem(LinkList &L,int i,ElemType &e)
{//ȡԪ��
    LinkList *p=L;
    int j=0;
    while(p&&j<i)
    {
        p=p->next; ++j;
    }
    if(p||j>i) return ERROR;
    e=p->data;
    return OK;
}

