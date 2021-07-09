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
//	//���Զ���
//	cycquee.InQuene(24);
//	int temp;
//	//ɾ��
//	for (int j = 0; j < 50; j++) {
//		cycquee.DeQuene(&temp);
//		cout << "ɾ��:" << temp << " ";
//	}
//	cout << endl;
//
//	cycquee.OutPut();
//	cout << "��ͷԪ�أ�" << cycquee.getHead() << endl;
//}

void AlgorithmTest() {
	//���Զ���
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

	//ͷ��ջ��β��ջ
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