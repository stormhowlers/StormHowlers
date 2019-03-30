#ifndef __Timer_H__
#define __Timer_H__

#include "Defs.h"

class Timer
{
public:

	// Constructor
	Timer();

	void Start();
	void Stop();

	uint32 Read() const;
	float ReadSec() const;

	bool runningRead() const;

private:

	bool	running;
	uint32	started_at;
	uint32	stopped_at;
};

#endif //__Timer_H__