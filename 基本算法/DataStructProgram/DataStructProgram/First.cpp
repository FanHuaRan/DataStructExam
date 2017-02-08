#include<atlstr.h>
#include<string>
#include<iostream>
using namespace std;

typedef int datatype;
 
//���������
typedef struct node{
	datatype data;
	struct node *link;
}BNode,*LinkList;

//����ͷ���

LinkList Creat()
{
	LinkList p=(LinkList)malloc(sizeof(BNode));
	p->link=NULL;
	return p;
}

//����β������

void Inserttotail(LinkList list)
{
	printf("���������������ٸ���㣺");
	int n;
	cin>>n;
	if(n<1) 
	{
		printf("���벻�Ϸ�");
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

//����ͷ������
void Inserttohead(LinkList list)
{
	printf("���������������ٸ���㣺");
	int n;
	cin>>n;
	if(n<1) 
	{
		printf("���벻�Ϸ�");
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


//ɾ����i�������
void deletei(LinkList list)
{
	printf("����������ɾ���Ľ��λ�ã�");
	int n;
	cin>>n;
	if(n<1)
    {
		printf("������㲻���ڣ�\n");
	     return ;
	}
	LinkList p=list,r;
	for(int i=0;i<n;i++)
	{
		r=p;
		p=p->link;
		if(p==NULL)
		{
			printf("������㲻���ڣ�");
			return;
		}
	}
	r->link=p->link;
	free(p);
}
void Convertto2()
{
	printf("����������ת��Ϊ2���Ƶ���:");
	int item;
	cin>>item;
	printf("��Ӧ�Ķ���������");
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
	printf("�Ƿ������(y/n)");
	string flag;
	cin>>flag;
	if(flag=="y") Convertto2();
	else if(flag=="n") 
	{
			printf("�㷨����\n");
			return;
	}
	else 
	{
		printf("�������Ĭ�ϼ���\n"); Convertto2();
	}

}
void Convertto8()
{
	printf("����������ת��Ϊ8���Ƶ���:");
	int item;
	cin>>item;
	printf("��Ӧ�Ķ���������");
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
	printf("�Ƿ������(y/n)");
	string flag;
	cin>>flag;
	if(flag=="y") Convertto2();
	else if(flag=="n") 
	{
			printf("�㷨����\n");
			return;
	}
	else 
	{
		printf("�������Ĭ�ϼ���\n"); Convertto2();
	}

}

void PiPei()
{
	while(1)
	{
		printf("����������ƥ������ţ�");
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
				{printf("��ƥ��\n"); return;}
				}
				else {printf("��ƥ�䣡\n"); return;}
			}
			else if(temp==']')
			{
				if(top>-1)
				{
				temp=stack[top--];
				if(temp=='[') ;
				else
				{printf("��ƥ��\n"); return;}
				}
				else {printf("��ƥ�䣡\n"); return;}
			}
			else if(temp=='}')
			{
				if(top>-1)
				{
				temp=stack[top--];
				if(temp=='{') ;
				else
				{printf("��ƥ��\n"); return;}
				}
				else {printf("��ƥ�䣡\n"); return;}
			}
		}
		if(top==-1) printf("ƥ��ɹ���\n");
	}
}
void Pipei()
{
	PiPei();
	printf("�Ƿ����(y/n)");
	string flag;
	cin>>flag;
	if(flag=="y") PiPei();
	else if(flag=="n") 
	{
		printf("�㷨����\n"); return;
	}
	else
	{
		printf("�������Ĭ�ϼ�����");
		PiPei();
	}
}
void Put(LinkList list)
{
	printf("���������������\n");
	LinkList p=list->link;
	int k=0;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->link;
        k++;
	}
	printf("������:%d\n",k);
}

void LianBiao()
{
	LinkList list=Creat();
	while(1)
	{
		printf("��ѡ������Ҫ���еĲ�����\n");
		printf("1.����β������\n2.����ͷ������\n3.ɾ����㣺\n");
		int i;
		cin>>i;
		if(i==1) Inserttotail(list);
		else if(i==2) Inserttohead(list);
		else if(i==3) deletei(list);
		else printf("���벻�Ϸ���\n");
		Put(list);
		string flag;
		printf("���������(y/n)\n");
		cin>>flag;
		if(flag=="n") break;
		else if(flag=="y") ;
		else printf("�������Ĭ�ϼ���\n");
   }
	printf("�㷨����\n");
}
////ϡ��������Ԫ����㷨
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
	printf("������������е��㷨:\n");
	printf("1.�������\n2.ת��2����\n3.ת��8����\n4.���ŷ�ƥ��\n");
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

	