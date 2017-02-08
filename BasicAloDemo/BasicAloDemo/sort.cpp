#include<iostream>
#include<string>
using namespace std;

/////////////冒泡排序
void Bubble_Sort(void **data,int n,int *compare(void *,void *))
{
	for(int i=0;i<n-1;i++)//控制循环次数 n-1次
	{
		int swap=0;//判断是否交换
		for(int j=0;j<n-i-1;j++)//对每次循环进行排序
		{
			//如果前面的值大于后面的值 则交换
			if(compare(data[i],data[j]))
			{
				void *temp=data[j];
				data[j]=data[j+1];
				data[j+1]=temp;
				swap=1;
			}
		}
		//已经没有发生元素交换 则证明此时的数组已经按照从小到大的次序排列，无需再进行排序
	   //break跳出循环，结束排序
		if(swap==0)
		{
			break;
		}
	}
}