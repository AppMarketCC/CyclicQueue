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
//Q 是如上定义的循环队列，本算法实现从队尾删除，若删除成功，返回被删除元素，否则给出出错信息。
{
	if (Q.front == Q.rear) { cout << "队列空" << endl; exit(0); }
	Q.rear = (Q.rear - 1 + MAXQSIZE) % MAXQSIZE; //修改队尾指针。
	return(Q.base[(Q.rear + 1 + MAXQSIZE) % MAXQSIZE]); //返回出队元素。
}

void FrontEnQueue(CycQueue Q, QElemType x)
// Q 是顺序存储的循环队列，本算法实现“从队头插入”元素 x。 
{
	if (Q.rear == (Q.front - 1 + MAXQSIZE) % MAXQSIZE) {
		cout << "队满" << endl;
		exit(0);
	}
	Q.base[Q.front] = x; //x 入队列
	Q.front = (Q.front - 1 + MAXQSIZE) % MAXQSIZE; //修改队头指针。
}// 结束从队头插入算法。


//只有尾指针的循环队列
typedef struct queuenode {
	QElemType data;
	struct queuenode* next;
}QueueNode; //以上是结点类型的定义

typedef struct {
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

#define TQSIZE 100
//带表标志位的循环链表
typedef struct SeQueue {
	QElemType* data;
	int front;
	int rear;
	int tag;
};

//初始化 
SeQueue QueueInit(SeQueue Q) {//初始化队列
	Q.front = Q.rear = 0; 
	Q.tag = 0;
	return Q;
}
//入队 
SeQueue QueueIn(SeQueue Q, int e)
{//入队列
	if ((Q.tag == 1) && (Q.rear == Q.front))
		cout << "队列已满" << endl;
	else
	{
		Q.rear = (Q.rear + 1) % TQSIZE;
		Q.data[Q.rear] = e;
		if (Q.tag == 0)
			Q.tag = 1; //队列已不空
	}
	return Q;
}
//出队
QElemType QueueOut(SeQueue Q) {//出队列
	QElemType e;
	if (Q.tag == 0) {
		cout << "队列为空" << endl;
		exit(0);
	}
	else
	{
		Q.front = (Q.front + 1) % TQSIZE;;
		e = Q.data[Q.front];
		if (Q.front == Q.rear) 
			Q.tag = 0; //空队列 
	}
	return e;
}


//递归算法实现Ack
int Ack(int m, int n)
{
	if (m == 0) 
		return n + 1;
	else if (m != 0 && n == 0) 
		return Ack(m - 1, 1);
	else 
		return Ack(m - 1, Ack(m, m - 1));
}//算法结束


