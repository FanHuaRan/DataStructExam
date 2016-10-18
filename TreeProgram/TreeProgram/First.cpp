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

//利用广义表建立二叉树：
void Creat(string E,BTREE &T)
{
	BTREE p,STACK[M];//定义一个堆栈来存放父节点的地址
	T=NULL;
	char ch;
	int i=0,top=-1,flag;//flag为标志
	124p
	while(i<E.length())
	{
		ch=E[i];
		 if(ch=='(')
		{
			STACK[++top]=p;//一个子表开始，父结点地址进栈
			flag=1;//标志位设为1
		}
		else if(ch==')')
		{
			top--;//一个子表结束 父节点退栈
		}
		else if(ch==',')
		{
			flag=0;//标志位设为0
		}
		else
		{
			p=(BTREE)malloc(sizeof(BTNode));//开辟一片内存
			p->data=ch;
			p->lchild=NULL;
			p->rchild=NULL;
			if(T==NULL)
			{
				T=p;
			}
			else if(flag==1)//证明该结点应为左孩子结点
			{
				STACK[top]->lchild=p;
			}
			else//
			{
				STACK[top]->rchild=p;//作右孩子结点
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
//前序遍历;
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
				STACK[++top]=p;//结点地址进栈
				p=p->lchild;//访问左子树
			}
			p=STACK[top--];//结点地址退栈
			p=p->rchild;//访问右子树
		}
	}
}
//中序遍历：
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
		p=p->lchild;//访问左子树
	 }
	  p=STACK[top--];
	  visit(p);//访问结点
	  p=p->rchild;//访问右子树
	}
}
}
//后序遍历：
void POSTORDER(BTREE T)
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
				visit(p);
				p=NULL;
			}
		}
	}
}
void Fun()
{
	BTREE T=NULL;
	printf("请输入广义表：");
	string value;
	cin>>value;
	Creat(value,T);
	printf("前序遍历结果：");
	PREORDER(T);
	printf("\n");

	printf("中序遍历结果：");
	INOROER(T);
	printf("\n");
	printf("后序遍历结果：");
	POSTORDER(T);
	printf("\n");
}
void main()
{
	Fun();
	system("pause");
}

