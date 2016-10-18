#include<iostream>
#include<string>
using namespace std;
#define M 1000
typedef char datatype;
typedef struct node
{
	datatype data;
	struct node *lchild;
	struct node *rchild;
}BTNode,*BTREE;

//���ù��������������
void Creat(string E,BTREE &T)
{
	BTREE p,STACK[M];//����һ����ջ����Ÿ��ڵ�ĵ�ַ
	T=NULL;
	char ch;
	int i=0,top=-1,flag;//flagΪ��־
	124p
	while(i<E.length())
	{
		ch=E[i];
		 if(ch=='(')
		{
			STACK[++top]=p;//һ���ӱ�ʼ��������ַ��ջ
			flag=1;//��־λ��Ϊ1
		}
		else if(ch==')')
		{
			top--;//һ���ӱ���� ���ڵ���ջ
		}
		else if(ch==',')
		{
			flag=0;//��־λ��Ϊ0
		}
		else
		{
			p=(BTREE)malloc(sizeof(BTNode));//����һƬ�ڴ�
			p->data=ch;
			p->lchild=NULL;
			p->rchild=NULL;
			if(T==NULL)
			{
				T=p;
			}
			else if(flag==1)//֤���ý��ӦΪ���ӽ��
			{
				STACK[top]->lchild=p;
			}
			else//
			{
				STACK[top]->rchild=p;//���Һ��ӽ��
			}
		}
		i++;
	}
}

void visit(BTREE p)
{
	if(p!=NULL)
		printf("%c",p->data);
}
//ǰ�����;
void PREORDER(BTREE T)
{
	BTREE p=T,STACK[M];
	int top=-1;
	if(T!=NULL)
	{
		while(p!=NULL||top!=-1)
		{
			while(p!=NULL)
			{
				visit(p);
				STACK[++top]=p;//����ַ��ջ
				p=p->lchild;//����������
			}
			p=STACK[top--];//����ַ��ջ
			p=p->rchild;//����������
		}
	}
}
//���������
void INOROER(BTREE T)
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
	  visit(p);//���ʽ��
	  p=p->rchild;//����������
	}
}
}
//���������
void POSTORDER(BTREE T)
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
				visit(p);
				p=NULL;
			}
		}
	}
}
void Fun()
{
	BTREE T=NULL;
	printf("����������");
	string value;
	cin>>value;
	Creat(value,T);
	printf("ǰ����������");
	PREORDER(T);
	printf("\n");

	printf("������������");
	INOROER(T);
	printf("\n");
	printf("������������");
	POSTORDER(T);
	printf("\n");
}
void main()
{
	Fun();
	system("pause");
}

