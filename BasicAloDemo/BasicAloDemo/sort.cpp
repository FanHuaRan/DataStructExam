#include<iostream>
#include<string>
using namespace std;

/////////////ð������
void Bubble_Sort(void **data,int n,int *compare(void *,void *))
{
	for(int i=0;i<n-1;i++)//����ѭ������ n-1��
	{
		int swap=0;//�ж��Ƿ񽻻�
		for(int j=0;j<n-i-1;j++)//��ÿ��ѭ����������
		{
			//���ǰ���ֵ���ں����ֵ �򽻻�
			if(compare(data[i],data[j]))
			{
				void *temp=data[j];
				data[j]=data[j+1];
				data[j+1]=temp;
				swap=1;
			}
		}
		//�Ѿ�û�з���Ԫ�ؽ��� ��֤����ʱ�������Ѿ����մ�С����Ĵ������У������ٽ�������
	   //break����ѭ������������
		if(swap==0)
		{
			break;
		}
	}
}