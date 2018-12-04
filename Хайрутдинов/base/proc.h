#ifndef __PROC_H__
#define __PROC_H__

#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
#include "time.h"
#include "JobStream.h"

using namespace std;

class TProc
{
private:
	double ProcRate;
	int cores;
	double intense;
	int numEx;
	int numPass;
	int progs;
	double tacts;
public:
	TProc()
	{
		ProcRate = 0.5;
		cores = 1;
		intense = 0.5;
		progs = 1;
	}
	TProc(double _rate, int _cores, double _intense, int _progs)
	{
		if (_rate >= 1 || intense >= 1)
			throw "error";
		ProcRate = _rate;
		cores = _cores;
		intense = _intense;
		progs = _progs;
	}
	void RunNewJob(int size)
	{
		TJobStream tmp(intense);
		TQueue<TJobStream> progs(size);
		TQueue <TJobStream> finishProgs(size);
		TQueue<TJobStream> lostProgs(size);
		for (int i = 0; i < size; i++)
			progs.Push(tmp);
		while (numEx != size)
		{
			if (IsProcBusy())
			{
				if (progs.GetBegin().IsFinish() == true)
				{
					numEx++;
					finishProgs.Push(progs.Pop());
				}
				else
					continue;
			}
			else
			{
				numPass++;
				lostProgs.Push(progs.Pop());
			}
			if (progs.IsEmpty() == true)
			{
				int tmp = numPass;
				while (tmp != 0)
				{
					if (lostProgs.GetBegin().IsFinish() == true)
					{
						finishProgs.Push(lostProgs.Pop());
						numEx++;
						tmp++;
					}
					else
						continue;
				}
			}

		}
		while (finishProgs.IsEmpty() == false)
		{
			tmp = finishProgs.Pop();
			tacts += tmp.GetTacts();
		}
	}
	bool IsProcBusy()
	{
		if (0.1*(rand() % 9 + 1) < ProcRate)
			return true;
		else return false;
	}
	int GetRate()
	{
		return ProcRate;
	}
	int GetCores()
	{
		return cores;
	}
	int GetEx()
	{
		return numEx;
	}
	int GetPass()
	{
		return numPass;
	}
	int GetProgs()
	{
		return progs;
	}
	double GetTacts()
	{
		return tacts;
	}
};

#endif
