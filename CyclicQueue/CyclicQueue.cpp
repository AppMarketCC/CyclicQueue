#include<iostream>
using namespace std;
/*
循环队列队
队空状态 front=rear
满 （rear+1）%N=front
入队 rear=(rear+1)%N
出队 front = (front+1)%n
队长 (rear-front+N)%N
*/
#define STRATLEN 100
#define STEPLEN 10

class CyclicQueue {

private:
	int* data;//数组
	int front;//尾
	int rear;//头

public:
	void Init() {
		data = new int[STRATLEN];
		front = rear = STRATLEN - 2;
	}
	int GetLen() {
		return (rear - front + STRATLEN) % STRATLEN;
	}


	//输出
	void OutPut() {
		int length = GetLen();
		cout << "当前队列长度:" << length << endl;
		if (length == 0) {
			cout << "队列为空:" << endl;
		}
		else {
			cout << "队列内容:" << endl;
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
			cout << "队列已满" << endl;
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
			cout << "队列为空" << endl;
		}
		else {
			front = (front + 1) % STRATLEN;
			*value = data[front];
		}
	}

	//取对头元素不出队
	int getHead() {
		return data[(front + 1) % STRATLEN];
	}

	//动态增长



	//动态减少
};

int main() {
	CyclicQueue cycquee;
	cycquee.Init();

	for (int i = 1; i <= 99; i++) {
		cycquee.InQuene(i);
	}

	//测试队满
	cycquee.InQuene(24);

	int temp;
	//删除
	for (int j = 0; j < 50; j++) {
		cycquee.DeQuene(&temp);
		cout << "删除:" << temp << " ";
	}
	cout << endl;

	cycquee.OutPut();
	cout << "队头元素：" << cycquee.getHead() << endl;
	//杨辉三角

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