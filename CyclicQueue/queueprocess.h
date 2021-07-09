#pragma once
#include<iostream>
using namespace std;

#define MAXQSIZE 100
#define QElemType int
typedef struct SeqQueue {
	QElemType* base;
	int front;
	int rear;
}SeqQueue, CycQueue;

//��ʼ������
bool IinitQueue(CycQueue& Q) {
	Q.base = new QElemType[MAXQSIZE];
	if (!Q.base)
		exit(0);
	Q.front = Q.rear = 0;
	return true;
}

//��ȡ���г���
int QueueLength(CycQueue& Q) {
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

//ѭ��������ջ
bool EnQueue(CycQueue& Q, QElemType e) {
	if ((Q.rear + 1) % MAXQSIZE == Q.front)
		return false;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return true;
}

bool DeQueue(CycQueue& Q, QElemType& e) {
	if (Q.rear == Q.front)
		return false;
	e = Q.base[Q.front];
	Q.front = Q.front + 1;
}


QElemType RaerDeQueue(CycQueue& Q)
//Q �����϶����ѭ�����У����㷨ʵ�ִӶ�βɾ������ɾ���ɹ������ر�ɾ��Ԫ�أ��������������Ϣ��
{
	if (Q.front == Q.rear) { cout << "���п�" << endl; exit(0); }
	Q.rear = (Q.rear - 1 + MAXQSIZE) % MAXQSIZE; //�޸Ķ�βָ�롣
	return(Q.base[(Q.rear + 1 + MAXQSIZE) % MAXQSIZE]); //���س���Ԫ�ء�
}

void FrontEnQueue(CycQueue& Q, QElemType x)
// Q ��˳��洢��ѭ�����У����㷨ʵ�֡��Ӷ�ͷ���롱Ԫ�� x�� 
{
	if (Q.rear == (Q.front - 1 + MAXQSIZE) % MAXQSIZE) {
		cout << "����" << endl;
		exit(0);
	}
	Q.base[Q.front] = x; //x �����
	Q.front = (Q.front - 1 + MAXQSIZE) % MAXQSIZE; //�޸Ķ�ͷָ�롣
}// �����Ӷ�ͷ�����㷨��


//ֻ��βָ���ѭ������
typedef struct QueueNode {
	QElemType data;
	struct QueueNode* next;
}QueueNode; //�����ǽ�����͵Ķ���

typedef struct {
	QueueNode* rear;
}CRORLinkQueue; //ֻ��һ��ָ���βԪ�ص�ָ��


// �ÿն�
void InitCRORQueue(CRORLinkQueue* Q)
{ //�ÿնӣ�����ʹͷ����Ϊ��βԪ��
	QueueNode* s=(QueueNode*)malloc(sizeof(QueueNode));
	Q->rear = s;
	s->next = s;//��ͷָ���Լ�
	Q->rear = Q->rear->next;//����βָ��ָ��ͷ���
	while (Q->rear != Q->rear->next)//�����зǿգ�������Ԫ���������
	{
		s = Q->rear->next;
		Q->rear->next = s->next;
		delete s;//���ս��ռ�
	}
}

// �жӿ�
int EmptyCRORQueue(CRORLinkQueue* Q)
{ //�жӿ�,��ͷ���� next ָ��ָ���Լ�ʱΪ�ն�
	return Q->rear->next->next == Q->rear->next;
}
// ���
void EnCRORQueue(CRORLinkQueue* Q, QElemType x)
{ //���,Ҳ������β��㴦����Ԫ��
	QueueNode* p = new QueueNode;//�����½��
	p->data = x; 
	p->next = Q->rear->next;//��ʼ���½�㲢���� 
	Q->rear->next=p;
	Q->rear = p;//��βָ�������½��
}

//����
QElemType DeCRORQueue(CRORLinkQueue* Q)
{//����,��ͷ���֮���Ԫ��ժ��
	QElemType t, x;
	QueueNode* p;
	if (EmptyCRORQueue(Q)) {
		cout << "Queue underflow" << endl;
		exit(0);
	}
	p = Q->rear->next->next; //p ָ��Ҫժ�µĽ��
	x = p->data; //������������
	if (p == Q->rear)
	{//��������ֻ��һ�����ʱ��p �����Ӻ�Ҫ����βָ��ָ��ͷ���
		Q->rear = Q->rear->next;
		Q->rear->next = p->next;
	}
	else
		Q->rear->next->next = p->next;//ժ�½�� p
	delete p;//�ͷű�ɾ���
	return x;
}

//��ʾ��������Ԫ��
void showCRORQuenue(CRORLinkQueue* Q) {
	QueueNode* p = Q->rear;
	while (p->next) {
		cout << p->data;
	}
	cout << p->data << endl;
}


#define TQSIZE 100
//�����־λ��ѭ������
typedef struct SeTagQueue {
	QElemType* data;
	int front;
	int rear;
	int tag;
}SeTagQueue;

//��ʼ�� 
void QueueInit(SeTagQueue& Q) {//��ʼ����
	Q.data = new QElemType[MAXQSIZE];
	Q.front = Q.rear = 0;
	Q.tag = 0;
}
//��� 
SeTagQueue QueueIn(SeTagQueue& Q, int e)
{//�����
	if ((Q.tag == 1) && (Q.rear == Q.front))
		cout << "��������" << endl;
	else
	{
		Q.rear = (Q.rear + 1) % TQSIZE;
		Q.data[Q.rear] = e;
		if (Q.tag == 0)
			Q.tag = 1; //�����Ѳ���
	}
	return Q;
}
//����
QElemType QueueOut(SeTagQueue& Q) {//������
	QElemType e;
	if (Q.tag == 0) {
		cout << "����Ϊ��" << endl;
		exit(0);
	}
	else
	{
		Q.front = (Q.front + 1) % TQSIZE;;
		e = Q.data[Q.front];
		if (Q.front == Q.rear)
			Q.tag = 0; //�ն��� 
	}
	return e;
}





