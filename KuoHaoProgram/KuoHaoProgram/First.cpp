#include<iostream>
#include<string>
using namespace std;
typedef char datatype;
//��ʼ����ջ
void Initials(int &top)
{
	top=-1;
}
//��ջ
void push(datatype STACK[],int &top, datatype item)
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


//���ŷ�ƥ��
int Brackets(datatype STACK[],int &top, string E)
{
	Initials(top);//��ʼ����ջ
	int i=0;
	char item;
	while(i<E.length())//���ζ�ȡÿһ��Ԫ��
	{
		
		if(E[i]=='('||E[i]=='['||E[i]=='{')//����������ţ�����ջ����
		{
			push(STACK,top,E[i]);
			i++;
		}
		//����������ţ����˳�ջ��Ԫ����֮��ƥ�䣺
		else if(E[i]==')')
		{
			if(EMPTYS(top))//�����ж�ջ�Ƿ�Ϊ��
			{
				printf("��ƥ��\n");
				return -1;
			}
			else if(pop(STACK,top,item));//�˳�ջ��Ԫ��
			{
				if(item=='(')
				{
					i++;
				}
				else
				{
					printf("��ƥ��\n");
					return -1;
				}
			}

		}//�����())�����������Ϊitem�����ô��ݣ���Ȼ�����ջ���ɹ���return 0,����item֮ǰ���޸ĳ�Ϊ�ˡ�(',����ƥ���ȥ���ǳɹ�������ʵ���ж϶�ջ�Ƿ�Ϊ��         
		
		else if(E[i]==']')
		{
			if(EMPTYS(top))
			{
				printf("��ƥ��\n");
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
					printf("��ƥ��\n");
					return -1;
				}
			}
		}
		else if(E[i]=='}')
		{
			if(EMPTYS(top))
			{
				printf("��ƥ��\n");
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
					printf("��ƥ��\n");
					return -1;
				}
			}
		}
	}
		if(EMPTYS(top))//�ж�ջ�Ƿ�Ϊ��
		{	printf("ƥ��ɹ�\n");//ջΪ����ƥ��ɹ�
		    return 1;
		}
		else
		{
			printf("��ƥ��\n");//����ƥ��ʧ��
			return -1;
		}
}




void Fun()
{
	printf("����������ƥ������ţ�");
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