#pragma once
#include<iostream>
#include"cyclicqueueobj.h"
using namespace std;

//杨辉三角
void YHTrangleQue(int line) {

	CyclicQueue yhtqueue;
	yhtqueue.Init();//初始化
	//入队，1，1，0
	yhtqueue.InQuene(1);
	yhtqueue.InQuene(1);
	yhtqueue.InQuene(0);

	int temp = 0;//用于判断出队元素是否为0
	int value;//存放出队数据的值
	for (int i = 0; i < line;)
	{
		yhtqueue.DeQuene(&value);//出队
		if (temp && !value){ //如果上一个出队元素不为0，后一个出队元素为不为0
			yhtqueue.InQuene(temp + value);//入队temp+value的值
			yhtqueue.InQuene(0);//入队0
			cout << endl;
			i++;//开始下一行
		}
		else
		{
			cout << value << " ";//打印输出
			yhtqueue.InQuene(temp + value);//0 value value 0，两种情况都入队value
		}
		temp = value;
	}
}
