#include<iostream>
using namespace std;
#define MAXDIS 100000;
 //cost���ڽӾ���,v����ʼ�㣬n�Ƕ�������,dist�����Ȩֵ,pos��path index
int **SHORTEST_PATH(int **cost,int v,int n,int*dist,int *pos)
{
	int **path=new int*[n];
	int *flagArray=new int[n];//��־����
	for(int i=0;i<n;i++)//��ʼ��
	{
		path[i]=new int[n];
		flagArray[i]=0;
		dist[i]=cost[v][i];
		path[i][0]=v;
		pos[i]=0;
	}
	flagArray[v]=1;
	int count=1;
	//����ѭ��n-1��
	while(count<n)
	{
		int u;
		int temp=MAXDIS;
		for(int i=0;i<n;i++)//Ѱ��û�ҵ����·���ĵ�ǰ·��Ȩֵ��С�Ķ���
		{
			if(flagArray[i]==0&&dist[i]<temp)
			{
				u=i;
				temp=dist[i];
			}
		}
		flagArray[u]=1;
		path[u][++pos[u]]=u;
       //   path[w]=path[u];
		for(int i=0;i<n;i++)//Ѱ����uֱ����ͨ��û��ȷ�����·���Ķ���,�޸�Ȩֵ��·��
		{
			if(flagArray[i]==0&&dist[u]+cost[u][i]<dist[i])
			{
				dist[i]=dist[u]+cost[u][i];
				for(int k=0;k<=pos[u];k++)
				{
					path[i][k]=path[u][k];
				}
				pos[i]=pos[u];
			}
		}
		count++;
	}
	return path;
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