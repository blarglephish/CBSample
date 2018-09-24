#pragma once
class FIFO
{
private:
	// Hardcoding this in to avoid the use of a 
	// vector object (no STL)
	const static int MAX_SIZE = 256;

	int m_items[MAX_SIZE];
	int m_head;
	int m_tail;

public:
	FIFO();
	~FIFO();

	void Queue(int value);
	int Dequeue();
	bool isEmpty();
};

