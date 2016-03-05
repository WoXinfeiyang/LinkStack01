#include<stdio.h>
#include<malloc.h>
#include"LinkStack.h"


/*
typedef struct StackNode
{
	SElemType data;
	struct StackNode*next;
}StackNode,*LinkStackPtr;

typedef struct LinkStack
{
	LinkStackPtr top;
	int length; 
}LinkStack;
*/

/*
�������ƣ�LinkStackInit(LinkStack*S)
��������:S------ָ����ջ��ָ��
����˵���� ����һ������ͷ���Ŀ�ջS��S->top�ڴ˱�ʾָ��ջ��Ԫ�ص�ָ�룬
���൱��ͷ������൱�ڵ������е�һ����㣬����ջ�����ڵ������ͷ�� 
*/
Bool LinkStackInit(LinkStack*S)
{
	S->top=(LinkStackPtr)malloc(sizeof(StackNode));
	if(!S->top)
	{
		printf("\n��ջ����ʧ��!\n");
		return False;
	}
	/*��ʼ��ջ*/
	S->top=NULL;/*��ջ��ʼ��Ϊ��*/ 
	S->length=0;
	return OK;
}
/*����һ����ջS*/
Bool LinkStackDestroy(LinkStack*S)
{
	LinkStackPtr ptarget,pnext;/*����2��ָ����ջ����ָ�����*/
	pnext=S->top;
	while(pnext)
	{
		ptarget=pnext;
		pnext=pnext->next;
		free(ptarget);	
		S->length--;
	}
	if(!S->length)
		return OK;
	else
		return Error;	
}

/*���һ����ջS*/
Bool LinkStackClear(LinkStack*S)
{
	LinkStackPtr ptarget,pnext;/*����2��ָ����ջ����ָ�����*/
	
	pnext=S->top->next;
	while(pnext)
	{
		ptarget=pnext;
		pnext=pnext->next;
		free(ptarget);	
		S->length--;
	}
	S->top=NULL;
	S->length--;
	if(!S->length)
		return OK;
	else
		return Error;	
	
} 

/*��ջ�п�*/
Bool LinkStackIsEmpty(LinkStack S)
{
	if(!S.length)
		return True;
	else
		return False;
		
}
/*��ȡ��ջ����*/
int LinkStackLength(LinkStack S)
{
	LinkStackPtr p=S.top;
	int length=0;
	while(p)
	{
		length++;
		p=p->next;	
	}
	return length;
	
	//return S.length;
			
}
/*��ȡջ��Ԫ��*/
void LinkStackGetTop(LinkStack S,SElemType *e)
{
	if(!S.top)
	{
		printf("\n��ջΪ�գ��޷���ȡջ��Ԫ��!\n");	
	}
	else
	{
		*e=S.top->data;	
	}		
}
/*��ջ*/
void LinkStackPush(LinkStack *S,SElemType e)
{
	LinkStackPtr node=(LinkStackPtr)malloc(sizeof(StackNode));
	node->data=e;
		
	node->next=S->top;/*���½ڵ�ĺ��ָ��ǰջ��Ԫ��*/
	S->top=node;/*��ջ��ָ���ƶ����½ڵ㴦*/
	
	S->length++;		
}
/*��ջ*/
void LinkStackPop(LinkStack *S,SElemType *e)
{
	LinkStackPtr p;
	if(!S->length)
		return;
	p=S->top;
	*e=S->top->data;
	S->top=S->top->next;
	free(p);
	S->length--;	
}
 /*��ջ�ı���*/
void LinkStackTraverse(LinkStack S)
{
	if(!S.length)
	{
		printf("\n��ǰ����Ϊ�գ��޷���ɱ���!\n");
		return;	
	}
	else
	{
		LinkStackPtr p=S.top;
		while(p)
		{
			printf("%d ",p->data);
			p=p->next;	
		}
		printf("\n");	
	}	
}
