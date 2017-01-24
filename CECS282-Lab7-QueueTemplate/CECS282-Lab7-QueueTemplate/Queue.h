#pragma once
//============================================================================
// Name        : Queue.h
// Author      : Sotheanith Sok
// Version     : 1.0
// Description : This is a templete for queue
//============================================================================
template <class Type, int MaxQueue>
#ifndef QUEUE_H_
#define QUEUE_H_
class Queue
{
public:
	Queue();
	~Queue();
	int empty();
	int full();
	int size();
	Type getFront();
	Type getBack();
	void push(Type);
	Type pop();
private:
	int emptyQueue;
	Type *items;
	int front;
	int back;
	
};
#endif

template<class Type, int MaxQueue>
Queue<Type, MaxQueue>::Queue()
{
	items = new Type[MaxQueue];
	emptyQueue = -1;
	front = emptyQueue;
	back = emptyQueue;
}

template<class Type, int MaxQueue>
Queue<Type, MaxQueue>::~Queue()
{
	delete[] items;
}

template<class Type, int MaxQueue>
int Queue<Type, MaxQueue>::empty()
{
	return back == emptyQueue;
}

template<class Type, int MaxQueue>
int Queue<Type, MaxQueue>::full()
{
	return back + 1 == MaxQueue;
}

template<class Type, int MaxQueue>
int Queue<Type, MaxQueue>::size()
{
	return back - front + 1;
}

template<class Type, int MaxQueue>
Type Queue<Type, MaxQueue>::getFront()
{
	return items[front];
}

template<class Type, int MaxQueue>
Type Queue<Type, MaxQueue>::getBack()
{
	return items[back];
}

template<class Type, int MaxQueue>
void Queue<Type, MaxQueue>::push(Type c)
{
	items[++back] = c;
	if (front == -1) {
		front = 0;
	}
}

template<class Type, int MaxQueue>
Type Queue<Type, MaxQueue>::pop()
{
	Type temp = items[front++];
	return temp;
}
