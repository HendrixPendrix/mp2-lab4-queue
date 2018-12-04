#ifndef __QUEUE_H__ 
#define __QUEUE_H__ 

const int MaxQueueSize = 10000;

template <class Telem>
class TQueue
{
	Telem *Mem;
	int size;
	int end;
	int begin;
	int count;
public:
	TQueue(int _size)
	{
		size = _size;
		begin = -1;
		end = 0;
		count = 0;
		if ((size < 0) || (size > MaxQueueSize))
			throw size;
		Mem = new Telem[size];
	}
	~TQueue()
	{
		delete[] Mem;
	}
	bool IsFull()
	{
		if (count == size)
			return true;
		return false;
	}
	bool IsEmpty()
	{
		if (count == 0)
			return true;
		return false;
	}
	void Push(const Telem &val)
	{
		if (IsFull() == false)
		{
			count++;
			Mem[end] = val;
			end = (end + 1) % size;
		}
		else throw "error";
	}
	Telem Pop()
	{
		if (IsEmpty() == false)
		{
			count--;
			begin = (begin + 1) % size;
			return Mem[begin];
		}
		else
			throw "error";
	}
	Telem GetBegin()
	{
		return Mem[(begin + 1) % size];
	}
};

#endif