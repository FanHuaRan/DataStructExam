#include<iostream>
using namespace std;

 //cost是邻接矩阵,v是起始点，n是顶点数量，path是最短路径，dist是最短权值,pos是最短路径经过的顶点个数
void SHORTEST_PATH(int **cost,int v,int n,int **path,int*dist,int *pos)
{
	int k;
	int i=0,u,count;
	int *s=new int[n];//标志数组
	for(i=0;i<n;i++)//初始化
	{
		s[i]=0;
		dist[i]=cost[v][i];
		path[i][0]=v;
		pos[i]=0;
	}
	s[v]=1;
	count=1;
	//控制循环n-1次
	while(count<n)
	{
		int temp=10000;
		for(i=0;i<n;i++)//寻找没找到最短路径的当前路径权值最小的顶点
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
		for(i=0;i<n;i++)//寻找与u直接联通但没有确定最短路径的顶点,修改权值和路径
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
void Fun()
{
	printf("请输入顶点数量：");
	int n=0;
	cin>>n;
	printf("请输入边的数量：");
	int count=0;
	cin>>count;
	int **cost;
	//初始化邻接矩阵
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
	printf("请输入起点：");
	cin>>v;
	//各初始化操作
	int **path=new int*[n];
	for(int i=0;i<n;i++)
	{
		path[i]=new int[n];
	}
	int *dist=new int[n];
	int *pos=new int[n];//记录数组
	SHORTEST_PATH(cost,v,n,path,dist,pos);
	OutPutShortPath(path,dist,pos,v,n);
}  
void main()
{
	Fun();
	system("pause");
}