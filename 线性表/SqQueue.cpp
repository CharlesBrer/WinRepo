#include<cstdio>
#include<cstdlib>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;

#define MAXSIZE 6
typedef struct {
    ElemType* base;
    int front,rear;
}SqQueue;

Status InitQueue(SqQueue &q)
{
    q.base=(ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
    if(!q.base) exit(OVERFLOW);
    front=0; rear=0;
    return OK;
}

Status InQueue(SqQueue &q,ElemType e)
{
    if((q.rear+1)%MAXSIZE==q.front) return ERROR;
    q.base[q.rear]=e;
    q.rear=(q.rear+1)%MAXSIZE;
    return OK;
}

Status DeQueue(SqQueue &q,ElemType &e)
{
    if(q.rear==q.front) return ERROR;
    e=q.base[q.front];
    q.front=(q.front+1)%MAXSIZE;
    return OK;
}
Status GetQueueLength(SqQueue q,int length)
{
    if(q.rear==q.front) return ERROR;
    length=(q.rear-q.front+MAXSIZE)%MAXSIZE;
}

