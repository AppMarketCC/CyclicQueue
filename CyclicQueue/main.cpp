#include<iostream>
#include"cyclicqueue.h"
using namespace std;


void CycTest() {
	CyclicQueue cycquee;
	cycquee.Init();

	for (int i = 1; i <= 99; i++) {
		cycquee.InQuene(i);
	}

	//���Զ���
	cycquee.InQuene(24);
	int temp;
	//ɾ��
	for (int j = 0; j < 50; j++) {
		cycquee.DeQuene(&temp);
		cout << "ɾ��:" << temp << " ";
	}
	cout << endl;

	cycquee.OutPut();
	cout << "��ͷԪ�أ�" << cycquee.getHead() << endl;
}


int main() {

	return 0;
}