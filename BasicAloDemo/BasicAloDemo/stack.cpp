#include<iostream>
#include<string>
using namespace std;
//初始化堆栈
void Initials(int &top)
{
	top=-1;
}
//入栈
void push(void *STACK[],int &top, void *item)
{
	STACK[++top]=item;
}
//判断栈是否为空
int EMPTYS(int top)
{
	int flag=top>-1?0:1;
	return flag;
}
//出栈
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
	if(EMPTYS(top))//首先判断栈是否为空
	{
		printf("不匹配\n");
		return 0;
	}
	else if(pop(STACK,top,(void**)&item));//退出栈顶元素
	{
		if(*item==right)
		{
			return 1;
		}
		else
		{
			printf("不匹配\n");
			return 0;
		}
	}
}

//括号符匹配
int Brackets(void *STACK[],int &top, string E)
{
	Initials(top);//初始化堆栈
	int i=0;
	char *item;
	while(i<E.length())//依次读取每一个元素
	{
		if(E[i]=='('||E[i]=='['||E[i]=='{')//如果是左括号，做进栈处理
		{
			push(STACK,top,&E[i]);
			i++;
		}
		//如果是右括号，则退出栈顶元素与之相匹配：
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
	if(EMPTYS(top))//判断栈是否为空
	{	
		printf("匹配成功\n");//栈为空则匹配成功
	    return 1;
	}
	else
	{
		printf("不匹配\n");//否则匹配失败
		return -1;
	}
}
