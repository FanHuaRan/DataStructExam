#include<stdio.h>
#include<stdlib.h>
//ð������
void Bubble_Sort2(int *a,int n)
{
	int i,j;
	int temp;
	int swap;//�ж��Ƿ񽻻�
	printf("������ð������\n");
	for(i=0;i<n-1;i++)//����ѭ������ n-1��
	{
		swap=0;
		for(j=0;j<n-i-1;j++)//��ÿ��ѭ����������
		{
			//���ǰ���ֵ���ں����ֵ �򽻻�
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				swap=1;
			}
		}
		if(swap==0) break;//�Ѿ�û�з���Ԫ�ؽ��� ��֤����ʱ�������Ѿ����մ�С����Ĵ������У������ٽ�������
									  //break����ѭ������������
		//��Ļ���ÿ��������
			printf("�����ǵ�%d����������",i+1);
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

	printf("���������������Ԫ�ظ�����");
	scanf("%d",&n);
	int *arry=new int[n];
	printf("����������Ԫ�أ�\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arry[i]);
	}
	Bubble_Sort2(arry,n);
	system("pause");
}
