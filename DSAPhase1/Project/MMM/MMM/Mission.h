#ifndef MISSION_H
#define MISSION_H
#include "Definitions.h"

class Mission
{
private:
	TYPE type;
	MISSION_STATUS status;
	int ID;
	int Distance;
	int Significance;
	int FormDay, WaitDays, ExecDays;
	int FinishDay; // = FormDay + WaitDays + ExecDays//
	int durationAtLocation;
public:
	Mission(TYPE t, int id);
	void setType(TYPE t);
	void setID(int id);
	void setStatus(MISSION_STATUS s);
	void setDistance(int d);
	void setSignificance(int s);
	void setFormDay(int d);
	void setWaitDays(int d);
	void setExecDays(int d);
	void setFinishDay(int d);
	void setDurationAtLocation(int d);
	TYPE getType();
	MISSION_STATUS getStatus();
	int getID();
	int getDistance();
	int getSignificance();
	int getFormDay();
	int getWaitDays();
	int getExecDays();
	int getFinishDay();
	int getDurationAtLocation();

	bool operator == (Mission const& OtherMission)
    {
	    return ID == OtherMission.ID;
    }

};



#endif



