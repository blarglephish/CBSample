#include "stdafx.h"
#include "LIFO.h"

LIFO::LIFO()
{
	m_top = -1;
}


LIFO::~LIFO()
{
}

void LIFO::Push(int value)
{
	if (m_top == MAX_SIZE - 1)
	{
		throw "Overflow error!";
	}
	else
	{
		m_top++;
		m_items[m_top] = value;
	}
}

int LIFO::Pop()
{
	if (m_top == -1)
	{
		throw "Underflow error!";
	}
	else
	{
		m_top--;
		return m_items[m_top + 1];
	}
}
