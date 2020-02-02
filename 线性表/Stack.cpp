#include<cstdio>
#include<cstdlib>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;

#define INIT_STACK_SIZE 5
#define STACKINCREAMENT 2

typedef struct
{
    ElemType* base,*top;
    int stacksize;
} Stack;

Status InitStack(Stack &s)
{
    s.base = (ElemType*)malloc(sizeof(ElemType)*INIT_STACK_SIZE);
    if(!s.base)
        exit(OVERFLOW);
    s.top=s.base;
    s.stacksize=INIT_STACK_SIZE;
}

Status Push(Stack &s,ElemType e)
{
    if(s.stacksize<=(s.top-s.base))
    {
        ElemType *newbase = (ElemType*)realloc(s.base,sizeof(ElemType)*(s.stacksize+STACKINCREAMENT));
        if(!newbase) exit(OVERFLOW);
        s.base=newbase;
        s.top=s.base+s.stacksize;
        s.stacksize+=STACKINCREAMENT;
    }
    *(s.top++)=e;

    return OK;
}


Status Pull(Stack &s,ElemType &e)
{
    if(s.base==s.top) return ERROR;
    e=*(s.top--);
    return OK;
}

Status GetTop(Stack s,ElemType &e)
{
    if(s.base==s.top) return ERROR;
    e=*(s.top);
    return OK;
}
