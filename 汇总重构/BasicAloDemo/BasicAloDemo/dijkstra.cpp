#include<iostream>
using namespace std;
#define MAXDIS 100000;
 //cost是邻接矩阵,v是起始点，n是顶点数量,dist是最短权值,pos是path index
int **SHORTEST_PATH(int **cost,int v,int n,int*dist,int *pos)
{
	int **path=new int*[n];
	int *flagArray=new int[n];//标志数组
	for(int i=0;i<n;i++)//初始化
	{
		path[i]=new int[n];
		flagArray[i]=0;
		dist[i]=cost[v][i];
		path[i][0]=v;
		pos[i]=0;
	}
	flagArray[v]=1;
	int count=1;
	//控制循环n-1次
	while(count<n)
	{
		int u;
		int temp=MAXDIS;
		for(int i=0;i<n;i++)//寻找没找到最短路径的当前路径权值最小的顶点
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
		for(int i=0;i<n;i++)//寻找与u直接联通但没有确定最短路径的顶点,修改权值和路径
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
///构建图
void BuildTable(int **cost,int n,int v)
{
	printf("请依次输入顶点偶对：\n");
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
//输出最短路径
void OutPutShortPath(int **path,int *dist,int *pos,int v,int n)
{
	printf("最短路径如下：\n");
	for(int i=0;i<n;i++)
	{
		printf("%d顶点到%d的最短距离:",v,i);
		for(int j=0;j<pos[i]+1;j++)
		{
			printf("%d,",path[i][j]);
		}
		printf("     最短距离：%d\n",dist[i]);
	}
}