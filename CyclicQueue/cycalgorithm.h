#pragma once
#include<iostream>
#include"queueprocess.h"
using namespace std;


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

#define M 20
#define N 20
int Ackerman(int m, int n)
{
	int akm[M][N]; 
	int i, j;
	for (j = 0; j < N; j++) 
		akm[0][j] = j + 1;
	for (i = 1; i < m; i++)
	{
		akm[i][0] = akm[i - 1][1];
		for (j = 1; j < N; j++)
			akm[i][j] = akm[i - 1][akm[i][j - 1]];
	}
	return akm[m][n];
}