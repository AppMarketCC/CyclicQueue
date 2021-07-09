#include<iostream>
#include"cyclicqueue.h"
using namespace std;


void CycTest() {
	CyclicQueue cycquee;
	cycquee.Init();

	for (int i = 1; i <= 99; i++) {
		cycquee.InQuene(i);
	}

	//²âÊÔ¶ÓÂú
	cycquee.InQuene(24);
	int temp;
	//É¾³ý
	for (int j = 0; j < 50; j++) {
		cycquee.DeQuene(&temp);
		cout << "É¾³ý:" << temp << " ";
	}
	cout << endl;

	cycquee.OutPut();
	cout << "¶ÓÍ·ÔªËØ£º" << cycquee.getHead() << endl;
}


int main() {

	return 0;
}