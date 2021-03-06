// CBSample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LIFO.h"
#include "FIFO.h"
#include <iostream>

using namespace std;

int main()
{
	LIFO stack = LIFO();

	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	stack.Push(4);
	stack.Push(5);

	int done;
	cout << stack.Pop() << endl;
	cout << stack.Pop() << endl;
	cout << stack.Pop() << endl;
	cin >> done;


	FIFO queue = FIFO();
	queue.Queue(1);
	queue.Queue(2);
	queue.Queue(3);
	queue.Queue(4);
	queue.Queue(5);
	queue.Queue(6);

	cout << queue.Dequeue() << endl;
	cout << queue.Dequeue() << endl;
	cout << queue.Dequeue() << endl;
	cout << queue.Dequeue() << endl;
	cin >> done;
    return 0;
}

