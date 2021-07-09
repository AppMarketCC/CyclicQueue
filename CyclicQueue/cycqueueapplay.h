#pragma once
#include<iostream>
#include"cyclicqueue.h"
using namespace std;
//�������
void YHTrangleQue(int line) {

	CyclicQueue yhtqueue;
	yhtqueue.Init();
	//������ǵ����
	yhtqueue.InQuene(1);
	yhtqueue.InQuene(1);
	yhtqueue.InQuene(0);

	int temp = 0;
	int value;
	for (int i = 0; i < line;)
	{
		yhtqueue.DeQuene(&value);
		if (temp && !value)
		{
			yhtqueue.InQuene(temp + value);
			yhtqueue.InQuene(0);
			cout << endl;
			i++;
		}
		else
		{
			cout << value << " ";
			yhtqueue.InQuene(temp + value);
		}
		temp = value;
	}
}
