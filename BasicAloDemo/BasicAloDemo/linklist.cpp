#include<iostream>
using namespace std;

//定义链结点
typedef struct node
{
	struct node *link;
	void *data;
}Node,*LinkList;

//创建头结点
LinkList CreatHead()
{
	LinkList p=(LinkList)malloc(sizeof(Node));
	p->link=NULL;
	return p;
}
//求链表长度
int GetLenth(LinkList list)
{
	LinkList r=list;
	int i=0;
	while(r->link!=NULL)
	{
		i++;
		r=r->link;
	}
	return i;
}
//输出链表
void OutPut(LinkList list)
{
	printf("***现在输出链表：\n");
	LinkList r=list;
	int lenth=0;
	while(r->link!=NULL)
	{
		lenth++;
		r=r->link;
		printf("%d ",r->data);
	}
	printf("\n链表长度：%d\n",lenth);
}
//链表尾部插入
void InsertoTail(LinkList list,void*item)
{
	LinkList p=(LinkList)malloc(sizeof(Node));
	p->data=item;
	p->link=NULL;
	LinkList r=list;
	while(r->link!=NULL)
	{
		r=r->link;
	}
	r->link=p;
}
//链表对应位置插入
void InsertoJPostion(LinkList list,int j,void*item)
{
	LinkList r=list;
	if(j<1)
	{
		printf("插入位置非法!\n");
		return;
	}
	if(j>GetLenth(list))
	{
		InsertoTail(list,item);
		return;
	}
	else
	{
		LinkList p=(LinkList)malloc(sizeof(Node));
	    p->data=item;
	    p->link=NULL;
		for(int i=1;i<j;i++)
		{
			r=r->link;
		}
		p->link=r->link;
		r->link=p;
	}
}
//删除值相同的多余节点,list为传入链表
void DeleteSameNode(LinkList list)
{
	LinkList p,r,q; 
	p=list->link;//跳过头结点
	while(p!=NULL)
	{
		q=p; //q指向当前被比较结点（值可能与p所指结点值相同）的前一个结点
		r=p->link; //r总是指向当前被比较的结点，值相同则该结点被删除
		while(r!=NULL)
		{
			if(p->data == r->data) //值相同，删除该节点，指针指向下一个节点
			{
				q->link=r->link;
				free(r);
				r=q->link;
			}
			else    //值不相同，指针直接指向下一个节点
			{
				q=r;
				r=r->link;
			}			
		}
		p=p->link;//分析下一个结点是否存在值相同的多余结点
	}
}
//合并两个链表，list1和list2为两个传入链表
LinkList UnionLists(LinkList list1,LinkList list2)
{
	LinkList p,r; //定义指针p,r分别指向list1,list2的首结点
	p=list1->link;
	r=list2->link;
	LinkList retList=CreatHead();//初始化合并后的链表,(创建一个链表)
	int plist1_length=0;//记录list1的长度
	while(p!=NULL) //将list1的所有结点添加到retList尾部
	{
		plist1_length++;
		InsertoTail(retList,p->data);//将p的data插入retlist的尾部
		p=p->link;
	}

	int plist2_length=0;//记录list2的长度
	while(r!=NULL)
	{
		plist2_length++;
		if(plist2_length<=plist1_length) //如果list2长度小于list1长度
		{
			InsertoJPostion(retList,plist2_length*2,r->data);//将r的data插入retlist的偶数位置
		}
		else //如果list2长度大于list1长度，则将多余结点插入到retList的尾部
		{
			InsertoTail(retList,r->data);//将r的data插入retlist的尾部
		}
		r=r->link;
	}
	return retList;
}
//遍历操作
void ForEach(LinkList list,void *Deal(Node *))
{
	LinkList r=list->link;
	while(r!=NULL)
	{
		Deal(r);
		r=r->link;
	}
}