#include<iostream>
#include<string>
using namespace std;

#define M 1000
//���
typedef struct node
{
	void *data;
	struct node *lchild;
	struct node *rchild;
}BTNode,*BTREE;
//CreateNode
BTREE CreateNode(void *value,BTNode *lchild,BTNode *rchild)
{
	BTREE p=(BTREE)malloc(sizeof(BTNode));//����һƬ�ڴ�
	p->data=value;
	p->lchild=NULL;
	p->rchild=NULL;
	return p;
}
//InsertNode
BTREE InsertNode(BTREE &T,int flag,BTREE STACK[],int top,void* value)
{
	BTREE p=CreateNode(value,NULL,NULL); 
	if(T==NULL)
	{
		T=p;
		return p;
	}
    if(flag==1)//֤���ý��ӦΪ���ӽ��
	{
		STACK[top]->lchild=p;
	}
	else//
	{
		STACK[top]->rchild=p;//���Һ��ӽ��
	}
	return p;
}
//���ù��������������
void CreatBTREE(string E,BTREE &T)
{
	T=NULL;
	BTREE p,STACK[M];//����һ����ջ����Ÿ��ڵ�ĵ�ַ
	int i=0,top=-1,flag;//flagΪ��־
	while(i<E.length())
	{
		char charValue=E[i];
		 if(charValue=='(')
		{
			STACK[++top]=p;//һ���ӱ�ʼ��������ַ��ջ
			flag=1;//��־λ��Ϊ1
		}
		else if(charValue==')')
		{
			top--;//һ���ӱ���� ���ڵ���ջ
		}
		else if(charValue==',')
		{
			flag=0;//��־λ��Ϊ0
		}
		else
		{
			BTREE p=InsertNode(T,flag,STACK,top,&charValue);
		}
		i++;
	}
}
//ǰ�����;
void PREORDER(BTREE T,void Visit(BTREE p))
{
	BTREE p=T,STACK[M];
	int top=-1;
	if(T!=NULL)
	{
		while(p!=NULL||top!=-1)
		{
			while(p!=NULL)
			{
				Visit(p);
				STACK[++top]=p;//����ַ��ջ
				p=p->lchild;//����������
			}
			p=STACK[top--];//����ַ��ջ
			p=p->rchild;//����������
		}
	}
}
//���������
void INOROER(BTREE T,void Visit(BTREE p)
{
	BTREE p,STACK[M];
	int top=-1;
    p=T;
	if(T!=NULL)
	{
		while(p!=NULL||top!=-1)
		{
		   while(p!=NULL)
		  {
			STACK[++top]=p;
			p=p->lchild;//����������
		  }
		  p=STACK[top--];
		  Visit(p);//���ʽ��
		  p=p->rchild;//����������
		}
	}
}
//���������
void POSTORDER(BTREE T,void Visit(BTREE p))
{

	BTREE STACK1[M],p=T;
	int STACK2[M],flag,top=-1;//flag=1��ʾ���ʣ�flag=0��ʾ�ݲ�����
	if(T!=NULL)//�ݹ�˼·�����ν�ջ
	{
		while(p!=NULL||top!=-1)
		{
			while(p!=NULL)
			{
			  STACK1[++top]=p;//��p��ָ����ַ��ջ
			  STACK2[top]=0;//��־0��ջ
			  p=p->lchild;//��pָ�������ӽ��
			}
			p=STACK1[top];
			flag=STACK2[top--];
			if(flag==0)
			{
				STACK1[++top]=p;
				STACK2[top]=1;
				p=p->rchild;
            }
			else{
				Visit(p);
				p=NULL;
			}
		}
	}
}


