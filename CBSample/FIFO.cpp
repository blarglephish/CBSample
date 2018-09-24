#include "stdafx.h"
#include "FIFO.h"


FIFO::FIFO()
{
	m_head = -1;
	m_tail = -1;
}

FIFO::~FIFO()
{
}

void FIFO::Queue(int value)
{
	// Case1: Overflow
	// Occurs if tail is immediately before head, OR if head is at 0
	// and the tail is at the max size and ready to wrap around
	if ((m_head == 0 && m_tail == (MAX_SIZE - 1)) || (m_head == m_tail + 1))
	{
		throw "Overflow error!";
	}
	else
	{
		// Case2: Update tail pointer, add to queue

		// 2.1: Insert into empty queue
		// Here we need to initialize both head and tail pointers to 0 so that
		// isEmpty no longer = true
		if (isEmpty())
		{
			m_head = 0;
			m_tail = 0;
		}
		// 2.2 Insert into non-empty queue
		// Here, we update tail pointer to be the next thing, or reset to 0
		// if it needs to wrap around
		else
		{
			m_tail = (m_tail == (MAX_SIZE - 1)) ? 0 : m_tail + 1;
		}

		m_items[m_tail] = value;
	}
}

int FIFO::Dequeue()
{
	// Case1: Underflow
	if (isEmpty())
	{
		throw "Underflow error!";
	}
	else
	{
		// Case2: remove item from the head, update head pointer
		int retVal = m_items[m_head];

		// 2.1 Last item
		// If head = tail, then we only have one item in the queue. After we get
		// the single item, we reset to -1 to satisfy isEmpty()
		if (m_head == m_tail)
		{
			m_head = -1;
			m_tail = -1;
		}
		// 2.2 general case
		// just update the head pointer, being mindful of the wraparound
		else
		{
			m_head = (m_head == (MAX_SIZE - 1)) ? 0 : m_head + 1;
		}

		return retVal;
	}
}

bool FIFO::isEmpty()
{
	return (m_head == -1 && m_tail == -1);
}
