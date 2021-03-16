#ifndef STATION_H
#define STATION_H
#include"Definitions.h"
#include"Formulation.h"
#include"Cancellation.h"
#include"Promotion.h"
#include"LinkedQueue.h"
#include"LinkedList.h"
#include"Node.h"
#include"Rover.h"
#include"Mission.h"
#include"Events.h"
#include<iostream>
class Station
{
private:

    int countWaitingMountMissions;
    int countWaitingPolarMissions;
    int countWaitingEmrgMissions;
    int countInServMountMissions;
    int countInServPolarMissions;
    int countInServEmrgMissions;
    int countDoneMountMissions;
    int countDonePolarMissions;
    int countDoneEmrgMissions;
    int countMountRovers;
    int countPolarRovers;
    int countEmergencytRovers;
    int TotalRovers;
    int countFormulationEvent;
    int countCancellationEvent;
    int countPromotionEvent;
    LinkedQueue<Formulation>* FormEvents = new LinkedQueue<Formulation>;
    LinkedQueue<Cancellation>* CancelEvents  = new LinkedQueue<Cancellation>;
    LinkedQueue<Promotion>* PromEvents = new LinkedQueue<Promotion>;
    LinkedList<Mission>* WaitingMountMissions = new LinkedList<Mission>;
    LinkedList<Mission>* WaitingPolarMissions = new LinkedList<Mission>;
    LinkedList<Mission>* WaitingEmrgMissions = new LinkedList<Mission>;
    LinkedList<Mission>* InServMountMissions = new LinkedList<Mission>;
    LinkedList<Mission>* InServPolarMissions = new LinkedList<Mission>;
    LinkedList<Mission>* InServEmrgMissions = new LinkedList<Mission>;
    LinkedList<Mission>* DoneMountMissions = new LinkedList<Mission>;
    LinkedList<Mission>* DonePolarMissions = new LinkedList<Mission>;
    LinkedList<Mission>* DoneEmrgMissions = new LinkedList<Mission>;
    LinkedList<Rover>* PRovers = new LinkedList<Rover>;
    LinkedList<Rover>* MRovers = new LinkedList <Rover>;
    LinkedList<Rover>* ERovers = new LinkedList<Rover>;

public:

    void fileLoader();
    void simpleSimulator();




};

#endif