#include<atlstr.h>
#include<string>
#include<iostream>
using namespace std;

typedef int datatype;
 
//定义链结点
typedef struct node{
	datatype data;
	struct node *link;
}BNode,*LinkList;

//创建头结点

LinkList Creat()
{
	LinkList p=(LinkList)malloc(sizeof(BNode));
	p->link=NULL;
	return p;
}

//链表尾部插入

void Inserttotail(LinkList list)
{
	printf("请输入你想插入多少个结点：");
	int n;
	cin>>n;
	if(n<1) 
	{
		printf("输入不合法");
		return ;
	}
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
	LinkList r=list;
	while(r->link!=NULL)
	{
		r=r->link;
	}
	LinkList p=(LinkList)malloc(sizeof(BNode));
	p->data=temp;;
	p->link=NULL;
	r->link=p;
	}
}

//链表头部插入
void Inserttohead(LinkList list)
{
	printf("请输入你想插入多少个结点：");
	int n;
	cin>>n;
	if(n<1) 
	{
		printf("输入不合法");
		return ;
	}
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
	LinkList p=(LinkList)malloc(sizeof(BNode));
	p->data=temp;;\
	p->link=list->link;
	list->link=p;
	}
}


//删除第i个链结点
void deletei(LinkList list)
{
	printf("请输入你想删除的结点位置：");
	int n;
	cin>>n;
	if(n<1)
    {
		printf("该链结点不存在！\n");
	     return ;
	}
	LinkList p=list,r;
	for(int i=0;i<n;i++)
	{
		r=p;
		p=p->link;
		if(p==NULL)
		{
			printf("该链结点不存在！");
			return;
		}
	}
	r->link=p->link;
	free(p);
}
void Convertto2()
{
	printf("请输入你想转化为2进制的数:");
	int item;
	cin>>item;
	printf("对应的二进制数：");
	int stack[100];
	int top=-1;
	while(item!=0)
	{
		stack[++top]=item%2;
		item/=2;
	}

	while(top>-1)
	{
		printf("%d",stack[top]);
		top--;
	}
	printf("\n");
	printf("是否继续？(y/n)");
	string flag;
	cin>>flag;
	if(flag=="y") Convertto2();
	else if(flag=="n") 
	{
			printf("算法结束\n");
			return;
	}
	else 
	{
		printf("输入错误！默认继续\n"); Convertto2();
	}

}
void Convertto8()
{
	printf("请输入你想转化为8进制的数:");
	int item;
	cin>>item;
	printf("对应的二进制数：");
	int stack[100];
	int top=-1;
	while(item!=0)
	{
		stack[++top]=item%8;
		item/=8;
	}

	while(top>-1)
	{
		printf("%d",stack[top]);
		top--;
	}
	printf("\n");
	printf("是否继续？(y/n)");
	string flag;
	cin>>flag;
	if(flag=="y") Convertto2();
	else if(flag=="n") 
	{
			printf("算法结束\n");
			return;
	}
	else 
	{
		printf("输入错误！默认继续\n"); Convertto2();
	}

}

void PiPei()
{
	while(1)
	{
		printf("请输入你想匹配的括号：");
		string item;
		cin>>item;
		char stack[100];
		int top=-1;
		char temp;
		for(int i=0;i<item.length();i++)
		{
			temp=item[i];
			if(temp=='('|temp=='['|temp=='{')
				stack[++top]=temp;
			else if(temp==')')
			{
				if(top>-1)
				{
				temp=stack[top--];
				if(temp=='(') ;
				else
				{printf("不匹配\n"); return;}
				}
				else {printf("不匹配！\n"); return;}
			}
			else if(temp==']')
			{
				if(top>-1)
				{
				temp=stack[top--];
				if(temp=='[') ;
				else
				{printf("不匹配\n"); return;}
				}
				else {printf("不匹配！\n"); return;}
			}
			else if(temp=='}')
			{
				if(top>-1)
				{
				temp=stack[top--];
				if(temp=='{') ;
				else
				{printf("不匹配\n"); return;}
				}
				else {printf("不匹配！\n"); return;}
			}
		}
		if(top==-1) printf("匹配成功！\n");
	}
}
void Pipei()
{
	PiPei();
	printf("是否继续(y/n)");
	string flag;
	cin>>flag;
	if(flag=="y") PiPei();
	else if(flag=="n") 
	{
		printf("算法结束\n"); return;
	}
	else
	{
		printf("输入错误！默认继续！");
		PiPei();
	}
}
void Put(LinkList list)
{
	printf("现在输出链表结果：\n");
	LinkList p=list->link;
	int k=0;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->link;
        k++;
	}
	printf("链表长度:%d\n",k);
}

void LianBiao()
{
	LinkList list=Creat();
	while(1)
	{
		printf("请选择你想要进行的操作：\n");
		printf("1.链表尾部插入\n2.链表头部插入\n3.删除结点：\n");
		int i;
		cin>>i;
		if(i==1) Inserttotail(list);
		else if(i==2) Inserttohead(list);
		else if(i==3) deletei(list);
		else printf("输入不合法！\n");
		Put(list);
		string flag;
		printf("还想继续？(y/n)\n");
		cin>>flag;
		if(flag=="n") break;
		else if(flag=="y") ;
		else printf("输入错误！默认继续\n");
   }
	printf("算法结束\n");
}
////稀疏矩阵的三元组表算法
typedef struct 
{
	int rowKey;
	int colKey;
	int value;
}TMode;
typedef struct
{
	int rowCount;
	int colCount;
	int noZero;
	TMode data;
}TMatix;

void test()
{
	printf("请输入你想进行的算法:\n");
	printf("1.链表操作\n2.转换2进制\n3.转换8进制\n4.括号符匹配\n");
	int n;
	cin>>n;
	if(n==1) LianBiao();
	else  if(n==2) Convertto2();
	else  if(n==3) Convertto8();
	else if(n==4) Pipei();
	test();
}
void main()
{
	test();
	system("pause");
}

	