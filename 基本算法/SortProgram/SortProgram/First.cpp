#include<stdio.h>
#include<stdlib.h>
//冒泡排序
void Bubble_Sort2(int *a,int n)
{
	int i,j;
	int temp;
	int swap;//判断是否交换
	printf("现在是冒泡排序：\n");
	for(i=0;i<n-1;i++)//控制循环次数 n-1次
	{
		swap=0;
		for(j=0;j<n-i-1;j++)//对每次循环进行排序
		{
			//如果前面的值大于后面的值 则交换
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				swap=1;
			}
		}
		if(swap==0) break;//已经没有发生元素交换 则证明此时的数组已经按照从小到大的次序排列，无需再进行排序
									  //break跳出循环，结束排序
		//屏幕输出每步排序结果
			printf("现在是第%d步排序结果：",i+1);
			for(int k=0;k<n;k++)
			{
				printf("%d ",a[k]);
			}
			printf("\n");
		}
}
void main()
{
	int n=0;
	for(int i=0;i<10;i++)
	{
		printf("%d\n",i);
	}

	printf("请输入你想输入的元素个数：");
	scanf("%d",&n);
	int *arry=new int[n];
	printf("请依次输入元素：\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arry[i]);
	}
	Bubble_Sort2(arry,n);
	system("pause");
}
