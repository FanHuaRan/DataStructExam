#include<iostream>
#include<string>
using namespace std;
typedef char datatype;
//初始化堆栈
void Initials(int &top)
{
	top=-1;
}
//入栈
void push(datatype STACK[],int &top, datatype item)
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
int pop(datatype STACK[],int &top, datatype &item)
{
	if(EMPTYS(top))
		return 0;
	else
	{
		item=STACK[top--];
		return 1;
	}
}


//括号符匹配
int Brackets(datatype STACK[],int &top, string E)
{
	Initials(top);//初始化堆栈
	int i=0;
	char item;
	while(i<E.length())//依次读取每一个元素
	{
		
		if(E[i]=='('||E[i]=='['||E[i]=='{')//如果是左括号，做进栈处理
		{
			push(STACK,top,E[i]);
			i++;
		}
		//如果是右括号，则退出栈顶元素与之相匹配：
		else if(E[i]==')')
		{
			if(EMPTYS(top))//首先判断栈是否为空
			{
				printf("不匹配\n");
				return -1;
			}
			else if(pop(STACK,top,item));//退出栈顶元素
			{
				if(item=='(')
				{
					i++;
				}
				else
				{
					printf("不匹配\n");
					return -1;
				}
			}

		}//针对于())这种情况，因为item是引用传递，虽然最后退栈不成功，return 0,但是item之前被修改成为了‘(',所以匹配进去还是成功，所以实现判断堆栈是否为空         
		
		else if(E[i]==']')
		{
			if(EMPTYS(top))
			{
				printf("不匹配\n");
				return -1;
			}
			else if(pop(STACK,top,item));
			{
				if(item=='[')
				{
					i++;
				}
				else
				{
					printf("不匹配\n");
					return -1;
				}
			}
		}
		else if(E[i]=='}')
		{
			if(EMPTYS(top))
			{
				printf("不匹配\n");
				return -1;
			}
			else if(pop(STACK,top,item));
			{
				if(item=='{')
				{
					i++;
				}
				else
				{
					printf("不匹配\n");
					return -1;
				}
			}
		}
	}
		if(EMPTYS(top))//判断栈是否为空
		{	printf("匹配成功\n");//栈为空则匹配成功
		    return 1;
		}
		else
		{
			printf("不匹配\n");//否则匹配失败
			return -1;
		}
}




void Fun()
{
	printf("请输入你想匹配的括号：");
	string bracket;
	cin>>bracket;
	datatype STACK[1000];
	int top;
	Initials(top);
	Brackets(STACK,top,bracket);
	Fun();
}
void main()
{
	Fun();
}