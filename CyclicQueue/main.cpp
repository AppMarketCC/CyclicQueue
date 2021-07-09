#include<iostream>
//#include"cyclicqueueobj.h"
#include"queueprocess.h"
#include"cycalgorithm.h"
using namespace std;


//void CycObjTest() {
//	CyclicQueue cycquee;
//	cycquee.Init();
//
//	for (int i = 1; i <= 99; i++) {
//		cycquee.InQuene(i);
//	}
//
//	//测试队满
//	cycquee.InQuene(24);
//	int temp;
//	//删除
//	for (int j = 0; j < 50; j++) {
//		cycquee.DeQuene(&temp);
//		cout << "删除:" << temp << " ";
//	}
//	cout << endl;
//
//	cycquee.OutPut();
//	cout << "队头元素：" << cycquee.getHead() << endl;
//}

void AlgorithmTest() {
	//测试队列
	CRORLinkQueue *crorqueue =new CRORLinkQueue;
	int i;
	
	InitCRORQueue(crorqueue);
	for (i = 0; i < 20;i++) {
		EnCRORQueue(crorqueue, i);
	}
	//showCRORQuenue(crorqueue);
	for (i = 0; i < 10; i++) {
		DeCRORQueue(crorqueue);
	}
	//showCRORQuenue(crorqueue);

	SeTagQueue cytag;
	QueueInit(cytag);
	for (i = 0; i < 20; i++) {
		QueueIn(cytag, i);
	}
	for (i = 0; i < 10; i++) {
		cout<<QueueOut(cytag)<<" ";
	}
	cout << endl;

	//头入栈，尾出栈
	CycQueue cycq;
	IinitQueue(cycq);
	for (i = 0; i < 20; i++) {
		FrontEnQueue(cycq, i);
	}
	for (i = 0; i < 10; i++) {
		cout<<RaerDeQueue(cycq)<<" ";
	}
	cout << endl;
}


int main() {
	AlgorithmTest();
	return 0;
}