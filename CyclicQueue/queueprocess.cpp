#include<iostream>
using namespace std;

#define MAXQSIZE 100
#define QElemType int
typedef struct SeqQueue {
	QElemType* base;
	int front;
	int rear;
};
//ֻ��βָ���ѭ������
typedef struct queuenode{
	QElemType data;
	struct queuenode* next;
}QueueNode; //�����ǽ�����͵Ķ���

typedef struct{
	queuenode* rear;
}CRORLinkQueue; //ֻ��һ��ָ���βԪ�ص�ָ��


// �ÿն�
void InitCRORQueue(CRORLinkQueue* Q)
{ //�ÿնӣ�����ʹͷ����Ϊ��βԪ��
	QueueNode* s;
	Q->rear = Q->rear->next;//����βָ��ָ��ͷ���
	while (Q->rear != Q->rear->next)//�����зǿգ�������Ԫ���������
	{
		s = Q->rear->next;
		Q->rear->next = s->next;
		delete s;
	}//���ս��ռ�
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
	p->data = x; p->next = Q->rear->next;//��ʼ���½�㲢���� Q-rear->next=p;
	Q->rear = p;//��βָ�������½��
}
//����
QElemType DeCRORQueue(CRORLinkQueue* Q)
{//����,��ͷ���֮���Ԫ��ժ��
	QElemType t, x;
	QueueNode* p;
	if (EmptyCRORQueue(Q))
		cout << "Queue underflow" << endl;
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



