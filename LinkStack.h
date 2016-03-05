#ifndef _LinkStack_H
#define _LinkStack_H

#define Bool int
#define True (1)
#define False (0) 
#define OK (1)
#define Error (0)

typedef int SElemType;

typedef struct StackNode
{
	SElemType data;
	struct StackNode*next;
}StackNode,*LinkStackPtr;

typedef struct LinkStack
{
	LinkStackPtr top;
	int length;/*��ջ����*/ 
}LinkStack;

/*����һ������ͷ���Ŀ�ջS*/
Bool LinkStackInit(LinkStack*S);
/*����һ����ջS*/
Bool LinkStackDestroy(LinkStack*S);
/*���һ����ջS*/
Bool LinkStackClear(LinkStack*S);
/*��ջ�п�*/
Bool LinkStackIsEmpty(LinkStack S);
/*��ȡ��ջ����*/
int LinkStackLength(LinkStack S);
/*��ȡջ��Ԫ��*/
void LinkStackGetTop(LinkStack S,SElemType *e);
/*��ջ*/
void LinkStackPush(LinkStack *S,SElemType e);
/*��ջ*/
void LinkStackPop(LinkStack *S,SElemType *e); 
 /*��ջ�ı���*/
void LinkStackTraverse(LinkStack S);

#endif
