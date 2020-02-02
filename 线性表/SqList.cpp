#include<cstdio>
#include<cstdlib>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;

#define INIT_LIST_SIZE 5
#define LISTINCREAMENT 2

typedef struct {
    ElemType *elem;
    int length;
    int listsize;
}SqList;
Status initList(SqList &L)
{
     L.elem=(ElemType*)malloc(sizeof(ElemType)*INIT_LIST_SIZE);
     if(!L.elem) exit(OVERFLOW);
     L.length=0;
     L.listsize=INIT_LIST_SIZE;
     return 0;
}// init_List

Status InsertElem(SqList &L,int i,ElemType e)
{
    ElemType *newbase,*q,*p;
    if(i>L.length+1||i<1) return ERROR;
    if(L.length>=L.listsize){
        newbase=(ElemType*)realloc(L.elem,sizof(ElemType)*(L.listsize+LISTINCREAMENT));
        if(!newbase) exit(OVERFLOW);
        L.elem=newbase;
        L.listsize+=LISTINCREAMENT;
    }//if
    q=&(L.elem[i-1]);
    for(p=&(L.elem[L.length-1]);p>=q;--p) *(p+1)=*p;
    //qȷ������λ�㣬p��λ����ĩ������ƶ����ټ�С��ֱ��������λ������ݺ���һλѭ��ֹͣ
    *q=e;//��e����
    L.length++;
    return OK;
}//insertElem

Status DeleteElem(SqList &L,int i,ElemType &e)
{
    ElemType *p,*q;
    if(i>L.length||i<1||) return ERROR;

    q=&(L.elem[i-1]);//ɾ��λ��
    e=L.elem[i-1];
    p=L.elem+L.length-1;//��¼��β
    for(++q;q<=p;q++) *(q-1)=*q;//��ɾ��λ�õĺ��λ�ÿ�ʼ������ֱ����β������Ԫ�ض��õ��ƶ�
    --L.length;
    return OK;
}//deleteElem

Status DestoryList(SqList &L)
{
    if(!L.elem) return ERROR;
    free(L.elem);
    L.length=0;
    L.listsize=0;
}//�������Ա�

Status ClearList(SqList &L)
{//����˳���Ϊ�ձ�
    if(!L.elem) return ERROR;
    L.length=0;
}//clear

Status isEmpty(SqList L)
{
    if(!L.elem||L.length>0) return ERROR;
    return OK;
}//isEmpty

