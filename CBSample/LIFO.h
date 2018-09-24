#pragma once
class LIFO
{
private:
	// Hardcoding this in to avoid the use of a 
	// vector object (no STL)
	const static int MAX_SIZE = 256;

	int m_items[MAX_SIZE];
	int m_top;

public:
	LIFO();
	~LIFO();

	void Push(int v);
	int Pop();
};

