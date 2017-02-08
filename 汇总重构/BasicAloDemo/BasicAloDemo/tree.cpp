#include<iostream>
#include<string>
using namespace std;

#define M 1000
//结点
typedef struct node
{
	void *data;
	struct node *lchild;
	struct node *rchild;
}BTNode,*BTREE;
//CreateNode
BTREE CreateNode(void *value,BTNode *lchild,BTNode *rchild)
{
	BTREE p=(BTREE)malloc(sizeof(BTNode));//开辟一片内存
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
    if(flag==1)//证明该结点应为左孩子结点
	{
		STACK[top]->lchild=p;
	}
	else//
	{
		STACK[top]->rchild=p;//作右孩子结点
	}
	return p;
}
//利用广义表建立二叉树：
void CreatBTREE(string E,BTREE &T)
{
	T=NULL;
	BTREE p,STACK[M];//定义一个堆栈来存放父节点的地址
	int i=0,top=-1,flag;//flag为标志
	while(i<E.length())
	{
		char charValue=E[i];
		 if(charValue=='(')
		{
			STACK[++top]=p;//一个子表开始，父结点地址进栈
			flag=1;//标志位设为1
		}
		else if(charValue==')')
		{
			top--;//一个子表结束 父节点退栈
		}
		else if(charValue==',')
		{
			flag=0;//标志位设为0
		}
		else
		{
			BTREE p=InsertNode(T,flag,STACK,top,&charValue);
		}
		i++;
	}
}
//前序遍历;
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
				STACK[++top]=p;//结点地址进栈
				p=p->lchild;//访问左子树
			}
			p=STACK[top--];//结点地址退栈
			p=p->rchild;//访问右子树
		}
	}
}
//中序遍历：
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
			p=p->lchild;//访问左子树
		  }
		  p=STACK[top--];
		  Visit(p);//访问结点
		  p=p->rchild;//访问右子树
		}
	}
}
//后序遍历：
void POSTORDER(BTREE T,void Visit(BTREE p))
{

	BTREE STACK1[M],p=T;
	int STACK2[M],flag,top=-1;//flag=1表示访问，flag=0表示暂不访问
	if(T!=NULL)//递归思路，两次进栈
	{
		while(p!=NULL||top!=-1)
		{
			while(p!=NULL)
			{
			  STACK1[++top]=p;//将p所指结点地址进栈
			  STACK2[top]=0;//标志0进栈
			  p=p->lchild;//将p指向其左孩子结点
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


