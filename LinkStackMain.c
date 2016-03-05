#include <stdio.h>
#include <stdlib.h>
#include"LinkStack.h"
/*
�ļ����ƣ���ջ�Ļ�������
ʱ�䣺2014-1-26 17:54
˵���� ��ջ�Ļ�������
*/ 


int main(int argc, char *argv[]) 
{
	LinkStack S;
	SElemType a;
	int i=0;
	if(LinkStackInit(&S)==OK)
	{
		printf("\n��ǰջ�ĳ���Ϊ:%d\n",LinkStackLength(S));	
	}
	
	for(i=0;i<10;i++)
		LinkStackPush(&S,i);
	printf("\n��ǰջ�ĳ���Ϊ:%d\n",LinkStackLength(S));
	printf("\n��ǰ��ջ����Ϊ:\n");
	LinkStackTraverse(S);
	
	LinkStackGetTop(S,&a);
	printf("a=%d\n",a);
	
	LinkStackPop(&S,&a);
	
	printf("\n��ǰջ�ĳ���Ϊ:%d\n",LinkStackLength(S));
	printf("\n��ǰ��ջ����Ϊ:\n");
	LinkStackTraverse(S);
	printf("a=%d\n",a);	
	
	LinkStackClear(&S);
	printf("\n��ǰջ�ĳ���Ϊ:%d\n",LinkStackLength(S));
	printf("\n��ǰ��ջ����Ϊ:\n");
	LinkStackTraverse(S);	
	 
	return 0;
}
