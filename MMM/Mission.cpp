#include "Mission.h"
Mission::Mission(TYPE t, int id)
{
	type = t;
	ID = id;
}
void Mission::setType(TYPE t)
{
	type = t;
}
void Mission::setID(int id)
{
	ID = id;
}
void Mission::setStatus(MISSION_STATUS s)
{
	status = s;
}
void Mission::setDistance(int d)
{
	Distance = d;
}
void Mission::setSignificance(int s)
{
	Significance = s;
}

void Mission::setFormDay(int d)
{
	FormDay = d;
}

void Mission::setWaitDays(int d)
{
	WaitDays = d;
}

void Mission::setExecDays(int d)
{
	ExecDays = d;
}


void Mission::setFinishDay(int d)
{
	FinishDay = d;
}

void Mission::setDurationAtLocation(int d)
{
	durationAtLocation = d;
}

TYPE Mission::getType()
{
	return type;
}

MISSION_STATUS Mission::getStatus()
{
	return status;
}

int Mission::getID()
{
	return ID;
}

int Mission::getDistance()
{
	return Distance;
}

int Mission::getSignificance()
{
	return Significance;
}

int Mission::getFormDay()
{
	return FormDay;
}
int Mission::getWaitDays()
{
	return WaitDays;
}
int Mission::getExecDays()
{
	return ExecDays;
}
int Mission::getFinishDay()
{
	return FinishDay;
}
int Mission::getDurationAtLocation()
{
	return durationAtLocation;
}
