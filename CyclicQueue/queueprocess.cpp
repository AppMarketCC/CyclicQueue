#include<iostream>
using namespace std;

#define MAXQSIZE 100
#define QElemType int
typedef struct SeqQueue {
	QElemType* base;
	int front;
	int rear;
};
//只有尾指针的循环队列
typedef struct queuenode{
	QElemType data;
	struct queuenode* next;
}QueueNode; //以上是结点类型的定义

typedef struct{
	queuenode* rear;
}CRORLinkQueue; //只设一个指向队尾元素的指针


// 置空队
void InitCRORQueue(CRORLinkQueue* Q)
{ //置空队：就是使头结点成为队尾元素
	QueueNode* s;
	Q->rear = Q->rear->next;//将队尾指针指向头结点
	while (Q->rear != Q->rear->next)//当队列非空，将队中元素逐个出队
	{
		s = Q->rear->next;
		Q->rear->next = s->next;
		delete s;
	}//回收结点空间
}

// 判队空
int EmptyCRORQueue(CRORLinkQueue* Q)
{ //判队空,当头结点的 next 指针指向自己时为空队
	return Q->rear->next->next == Q->rear->next;
}
// 入队
void EnCRORQueue(CRORLinkQueue* Q, QElemType x)
{ //入队,也就是在尾结点处插入元素
	QueueNode* p = new QueueNode;//申请新结点
	p->data = x; p->next = Q->rear->next;//初始化新结点并链入 Q-rear->next=p;
	Q->rear = p;//将尾指针移至新结点
}
//出队
QElemType DeCRORQueue(CRORLinkQueue* Q)
{//出队,把头结点之后的元素摘下
	QElemType t, x;
	QueueNode* p;
	if (EmptyCRORQueue(Q))
		cout << "Queue underflow" << endl;
	p = Q->rear->next->next; //p 指向将要摘下的结点
	x = p->data; //保存结点中数据
	if (p == Q->rear)
	{//当队列中只有一个结点时，p 结点出队后，要将队尾指针指向头结点
		Q->rear = Q->rear->next;
		Q->rear->next = p->next;
	}
	else
		Q->rear->next->next = p->next;//摘下结点 p
	delete p;//释放被删结点
	return x;
}



