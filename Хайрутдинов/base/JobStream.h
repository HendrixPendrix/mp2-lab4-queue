#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "time.h"

class TJobStream
{
private:
	double JobIntense;
	double tacts;
public:
	TJobStream()
	{
		JobIntense = 0;
	}
	TJobStream(double _intense)
	{
		JobIntense = _intense;
	}
	bool IsFinish()
	{
		if (0.1*(rand() % 9 + 1) < JobIntense)
			return true;
		return false;
	}
	double GetTacts()
	{
		tacts = 1 / JobIntense;
		return tacts;
	}
};