#include<iostream>
using namespace std;

 //cost���ڽӾ���,v����ʼ�㣬n�Ƕ���������path�����·����dist�����Ȩֵ,pos�����·�������Ķ������
void SHORTEST_PATH(int **cost,int v,int n,int **path,int*dist,int *pos)
{
	int k;
	int i=0,u,count;
	int *s=new int[n];//��־����
	for(i=0;i<n;i++)//��ʼ��
	{
		s[i]=0;
		dist[i]=cost[v][i];
		path[i][0]=v;
		pos[i]=0;
	}
	s[v]=1;
	count=1;
	//����ѭ��n-1��
	while(count<n)
	{
		int temp=10000;
		for(i=0;i<n;i++)//Ѱ��û�ҵ����·���ĵ�ǰ·��Ȩֵ��С�Ķ���
		{
			if(s[i]==0&&dist[i]<temp)
			{
				u=i;
				temp=dist[i];
			}
		}
		s[u]=1;
		path[u][++pos[u]]=u;
       //   path[w]=path[u];
		for(i=0;i<n;i++)//Ѱ����uֱ����ͨ��û��ȷ�����·���Ķ���,�޸�Ȩֵ��·��
		{
			if(s[i]==0&&dist[u]+cost[u][i]<dist[i])
			{
				dist[i]=dist[u]+cost[u][i];
				for(k=0;k<=pos[u];k++)
					path[i][k]=path[u][k];
				pos[i]=pos[u];
			}
		}
		count++;
	}
}
///����ͼ
void BuildTable(int **cost,int n,int v)
{
	printf("���������붥��ż�ԣ�\n");
	for(int i=0;i<v;i++)
	{
		int p1=0;
		int p2=0;
		int quanzhi=0;
		cin>>p1;
		cin>>p2;
		cin>>quanzhi;
		cost[p1][p2]=quanzhi;
		cost[p2][p1]=quanzhi;
	}
}
//������·��
void OutPutShortPath(int **path,int *dist,int *pos,int v,int n)
{
	printf("���·�����£�\n");
	for(int i=0;i<n;i++)
	{
		printf("%d���㵽%d����̾���:",v,i);
		for(int j=0;j<pos[i]+1;j++)
		{
			printf("%d,",path[i][j]);
		}
		printf("     ��̾��룺%d\n",dist[i]);
	}
}
void Fun()
{
	printf("�����붥��������");
	int n=0;
	cin>>n;
	printf("������ߵ�������");
	int count=0;
	cin>>count;
	int **cost;
	//��ʼ���ڽӾ���
	cost=new int*[n];
	for(int i=0;i<n;i++)
	{
		cost[i]=new int[n];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cost[i][j]=0;
		}
	}
	BuildTable(cost,n,count);
	int v=0;
	printf("��������㣺");
	cin>>v;
	//����ʼ������
	int **path=new int*[n];
	for(int i=0;i<n;i++)
	{
		path[i]=new int[n];
	}
	int *dist=new int[n];
	int *pos=new int[n];//��¼����
	SHORTEST_PATH(cost,v,n,path,dist,pos);
	OutPutShortPath(path,dist,pos,v,n);
}  
void main()
{
	Fun();
	system("pause");
}