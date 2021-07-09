#pragma once
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
	//�ж϶�������
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