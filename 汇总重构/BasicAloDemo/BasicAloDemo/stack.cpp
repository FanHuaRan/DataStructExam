#include<iostream>
#include<string>
using namespace std;
//��ʼ����ջ
void Initials(int &top)
{
	top=-1;
}
//��ջ
void push(void *STACK[],int &top, void *item)
{
	STACK[++top]=item;
}
//�ж�ջ�Ƿ�Ϊ��
int EMPTYS(int top)
{
	int flag=top>-1?0:1;
	return flag;
}
//��ջ
int pop(void *STACK[],int &top, void **item)
{
	if(EMPTYS(top))
		return 0;
	else
	{
		item=&STACK[top--];
		return 1;
	}
}
//judge Right SymbolIsRight
int RSymbolIsRight(int top,void *STACK[],char right)
{
	char *item=NULL;
	if(EMPTYS(top))//�����ж�ջ�Ƿ�Ϊ��
	{
		printf("��ƥ��\n");
		return 0;
	}
	else if(pop(STACK,top,(void**)&item));//�˳�ջ��Ԫ��
	{
		if(*item==right)
		{
			return 1;
		}
		else
		{
			printf("��ƥ��\n");
			return 0;
		}
	}
}

//���ŷ�ƥ��
int Brackets(void *STACK[],int &top, string E)
{
	Initials(top);//��ʼ����ջ
	int i=0;
	char *item;
	while(i<E.length())//���ζ�ȡÿһ��Ԫ��
	{
		if(E[i]=='('||E[i]=='['||E[i]=='{')//����������ţ�����ջ����
		{
			push(STACK,top,&E[i]);
			i++;
		}
		//����������ţ����˳�ջ��Ԫ����֮��ƥ�䣺
		else if(E[i]==')')
		{
			if(RSymbolIsRight(top,STACK,')'))
			{
				i++;
			}
			else return -1;
		}
		else if(E[i]==']')
		{
			if(RSymbolIsRight(top,STACK,']'))
			{
				i++;
			}
			else return -1;
		}
		else if(E[i]=='}')
		{
			if(RSymbolIsRight(top,STACK,'}'))
			{
				i++;
			}
			else return -1;
		}
	}
	if(EMPTYS(top))//�ж�ջ�Ƿ�Ϊ��
	{	
		printf("ƥ��ɹ�\n");//ջΪ����ƥ��ɹ�
	    return 1;
	}
	else
	{
		printf("��ƥ��\n");//����ƥ��ʧ��
		return -1;
	}
}
