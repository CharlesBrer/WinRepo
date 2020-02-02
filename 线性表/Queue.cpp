#include<cstdio>
#include<cstdlib>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;

typedef struct QNode
{
    ElemType data;
    struct QNode* next;
}QNode,*Queueptr;
typedef struct {
    Queueptr rear,front;
}LinkQueue;

Status InitQueue(LinkQueue &q)
{
    q.front=q.rear=(Queueptr)malloc(sizeof(QNode));
    if(!q.front) exit(OVERFLOW);
    q.front->next=NULL;
    q.front->data=0;
    return OK;
}

Status Enqueue(LinkQueue &q,ElemType e)
{
    Queueptr newNode = (Queueptr)malloc(sizeof(QNode));
    if(!newNode) exit(OVERFLOW);
    q.rear->next=newNode;
    q.rear=newNode;
    q.rear->data=e;
    return OK;
}

Status DeQueue(LinkQueue &q,ElemType &e)
{
    if(q.front==q.rear) return ERROR;
    Queueptr p=q.front->next;
    e=p->data;
    q.front->next=p->next;
    if(q.rear==p) q.rear=q.front;
    free(p);
    return OK;
}

int main(){
    printf("af");

return 0;
}
