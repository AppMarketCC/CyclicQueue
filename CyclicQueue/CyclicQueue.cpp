#include<iostream>
using namespace std;
/*
ѭ�����ж�
�ӿ�״̬ front=rear
�� ��rear+1��%N=front
��� rear=(rear+1)%N
���� front = (front+1)%n
�ӳ� (rear-front+N)%N
*/
#define STRATLEN 100
#define STEPLEN 10

class CyclicQueue {

private:
	int* data;//����
	int front;//β
	int rear;//ͷ

public:
	void Init() {
		data = new int[STRATLEN];
		front = rear = STRATLEN - 2;
	}
	int GetLen() {
		return (rear - front + STRATLEN) % STRATLEN;
	}


	//���
	void OutPut() {
		int length = GetLen();
		cout << "��ǰ���г���:" << length << endl;
		if (length == 0) {
			cout << "����Ϊ��:" << endl;
		}
		else {
			cout << "��������:" << endl;
			int index = (front + 1) % STRATLEN;
			for (int i = 0; i < length; i++) {
				cout << data[index];
				index = (index + 1) % STRATLEN;
				if (i <= length - 1)
					cout << ",";
			}
			cout << endl;
		}
	}
	bool isFulled() {
		if ((rear + 1) % STRATLEN == front) {
			return true;
		}
		else {
			return false;
		}
	}

	void InQuene(int value) {
		if (isFull()) {
			cout << "��������" << endl;
		}
		else {
			rear = (rear + 1) % STRATLEN;
			data[rear] = value;
		}
	}

	bool isEmpty() {
		return (front == rear) ? true : false;
	}

	bool isFull() {
		return ((rear + 1) % STRATLEN == front) ? true : false;
	}

	void DeQuene(int* value) {
		if (GetLen() == 0) {
			cout << "����Ϊ��" << endl;
		}
		else {
			front = (front + 1) % STRATLEN;
			*value = data[front];
		}
	}

	//ȡ��ͷԪ�ز�����
	int getHead() {
		return data[(front + 1) % STRATLEN];
	}

	//��̬����



	//��̬����
};

int main() {
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
	//�������

	CyclicQueue trangleQue;
	trangleQue.Init();

	int line = 6;
	//cout<<""<<endl;
	//cin>>line;

	trangleQue.InQuene(0);
	trangleQue.InQuene(1);
	trangleQue.InQuene(1);

	int head;
	int value;
	for (int i = 1; i < line + 1;) {
		//head=trangleQue.getHead();
		trangleQue.DeQuene(&value);
		if (0 == value) {
			cout << endl;
			i++;
			if (temp + value == 0) {
				trangleQue.InQuene(0);
				trangleQue.InQuene(0);
			}
			else {
				trangleQue.InQuene(temp + value);
			}
		}
		else {
			cout << value << " ";
			trangleQue.InQuene(temp + value);
		}
		temp = value;
	}



	return 0;
}