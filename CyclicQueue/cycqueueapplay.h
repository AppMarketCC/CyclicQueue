#pragma once
#include<iostream>
#include"cyclicqueueobj.h"
using namespace std;

//�������
void YHTrangleQue(int line) {

	CyclicQueue yhtqueue;
	yhtqueue.Init();//��ʼ��
	//��ӣ�1��1��0
	yhtqueue.InQuene(1);
	yhtqueue.InQuene(1);
	yhtqueue.InQuene(0);

	int temp = 0;//�����жϳ���Ԫ���Ƿ�Ϊ0
	int value;//��ų������ݵ�ֵ
	for (int i = 0; i < line;)
	{
		yhtqueue.DeQuene(&value);//����
		if (temp && !value){ //�����һ������Ԫ�ز�Ϊ0����һ������Ԫ��Ϊ��Ϊ0
			yhtqueue.InQuene(temp + value);//���temp+value��ֵ
			yhtqueue.InQuene(0);//���0
			cout << endl;
			i++;//��ʼ��һ��
		}
		else
		{
			cout << value << " ";//��ӡ���
			yhtqueue.InQuene(temp + value);//0 value value 0��������������value
		}
		temp = value;
	}
}
