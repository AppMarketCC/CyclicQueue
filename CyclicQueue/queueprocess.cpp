#include<iostream>
using namespace std;

#define MAXQSIZE 100
#define QElemType int
typedef struct SeqQueue {
	QElemType* base;
	int front;
	int rear;
}CycQueue;

QElemType RaerDeQueue(CycQueue Q)
//Q �����϶����ѭ�����У����㷨ʵ�ִӶ�βɾ������ɾ���ɹ������ر�ɾ��Ԫ�أ��������������Ϣ��
{
	if (Q.front == Q.rear) { cout << "���п�" << endl; exit(0); }
	Q.rear = (Q.rear - 1 + MAXQSIZE) % MAXQSIZE; //�޸Ķ�βָ�롣
	return(Q.base[(Q.rear + 1 + MAXQSIZE) % MAXQSIZE]); //���س���Ԫ�ء�
}

void FrontEnQueue(CycQueue Q, QElemType x)
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
typedef struct queuenode {
	QElemType data;
	struct queuenode* next;
}QueueNode; //�����ǽ�����͵Ķ���

typedef struct {
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

#define TQSIZE 100
//�����־λ��ѭ������
typedef struct SeQueue {
	QElemType* data;
	int front;
	int rear;
	int tag;
};

//��ʼ�� 
SeQueue QueueInit(SeQueue Q) {//��ʼ������
	Q.front = Q.rear = 0; 
	Q.tag = 0;
	return Q;
}
//��� 
SeQueue QueueIn(SeQueue Q, int e)
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
QElemType QueueOut(SeQueue Q) {//������
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


//�ݹ��㷨ʵ��Ack
int Ack(int m, int n)
{
	if (m == 0) 
		return n + 1;
	else if (m != 0 && n == 0) 
		return Ack(m - 1, 1);
	else 
		return Ack(m - 1, Ack(m, m - 1));
}//�㷨����


