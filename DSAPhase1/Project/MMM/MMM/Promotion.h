#pragma once
#include "Events.h"
class Promotion : public Events
{
	int	ED;     // is the event day.
	int	ID;     // is the ID of the mission to be promoted to emergency.This ID must be of a mountainous mission.

public:
    Promotion(){}
    Promotion(int ED1, int ID1);
};

