#include<iostream>
using namespace std;

//���������
typedef struct node
{
	struct node *link;
	void *data;
}Node,*LinkList;

//����ͷ���
LinkList CreatHead()
{
	LinkList p=(LinkList)malloc(sizeof(Node));
	p->link=NULL;
	return p;
}
//��������
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
//�������
void OutPut(LinkList list)
{
	printf("***�����������\n");
	LinkList r=list;
	int lenth=0;
	while(r->link!=NULL)
	{
		lenth++;
		r=r->link;
		printf("%d ",r->data);
	}
	printf("\n�����ȣ�%d\n",lenth);
}
//����β������
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
//�����Ӧλ�ò���
void InsertoJPostion(LinkList list,int j,void*item)
{
	LinkList r=list;
	if(j<1)
	{
		printf("����λ�÷Ƿ�!\n");
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
//ɾ��ֵ��ͬ�Ķ���ڵ�,listΪ��������
void DeleteSameNode(LinkList list)
{
	LinkList p,r,q; 
	p=list->link;//����ͷ���
	while(p!=NULL)
	{
		q=p; //qָ��ǰ���ȽϽ�㣨ֵ������p��ָ���ֵ��ͬ����ǰһ�����
		r=p->link; //r����ָ��ǰ���ȽϵĽ�㣬ֵ��ͬ��ý�㱻ɾ��
		while(r!=NULL)
		{
			if(p->data == r->data) //ֵ��ͬ��ɾ���ýڵ㣬ָ��ָ����һ���ڵ�
			{
				q->link=r->link;
				free(r);
				r=q->link;
			}
			else    //ֵ����ͬ��ָ��ֱ��ָ����һ���ڵ�
			{
				q=r;
				r=r->link;
			}			
		}
		p=p->link;//������һ������Ƿ����ֵ��ͬ�Ķ�����
	}
}
//�ϲ���������list1��list2Ϊ������������
LinkList UnionLists(LinkList list1,LinkList list2)
{
	LinkList p,r; //����ָ��p,r�ֱ�ָ��list1,list2���׽��
	p=list1->link;
	r=list2->link;
	LinkList retList=CreatHead();//��ʼ���ϲ��������,(����һ������)
	int plist1_length=0;//��¼list1�ĳ���
	while(p!=NULL) //��list1�����н����ӵ�retListβ��
	{
		plist1_length++;
		InsertoTail(retList,p->data);//��p��data����retlist��β��
		p=p->link;
	}

	int plist2_length=0;//��¼list2�ĳ���
	while(r!=NULL)
	{
		plist2_length++;
		if(plist2_length<=plist1_length) //���list2����С��list1����
		{
			InsertoJPostion(retList,plist2_length*2,r->data);//��r��data����retlist��ż��λ��
		}
		else //���list2���ȴ���list1���ȣ��򽫶�������뵽retList��β��
		{
			InsertoTail(retList,r->data);//��r��data����retlist��β��
		}
		r=r->link;
	}
	return retList;
}
//��������
void ForEach(LinkList list,void *Deal(Node *))
{
	LinkList r=list->link;
	while(r!=NULL)
	{
		Deal(r);
		r=r->link;
	}
}