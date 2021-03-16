#include "Station.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void Station::fileLoader()
{
    string filename;
    cout << "Specify Input File Name (testinput1.txt,testinput2.txt,testinput3.txt) ";
    cin >> filename;

    ifstream input(filename.c_str());
    /*
   if (input.fail())
    {
        cout << filename << " was not found!";
       exit(0);
    }
   */


    int numM,numP,numE,SM,SP,SE,N,CM,CP,CE,AutoP,NumEvents;

    input >> numM >> numP >> numE >> SM >> SP >> SE >> N >> CM >> CP >> CE >> AutoP >> NumEvents;

    //Now a sanity check! Call it a unit test if you wanna be fancy :)
  //cout << numM << " " << numP << " " << numE << " " << SM << " " << SP << " " << SE << " " << N << " " << CM << " " << CP << " " << CE << " " << AutoP << " " << NumEvents << "\n";

    //Coming up is parsing the multiple lines of events information.
    //I'll do those before constructing the rovers and handling the constructor calls for all the other stuff I read in.
    //Really only because I want to close the file a little sooner.

    //We'll add more temporary variables, just so the naming looks neat and consistent.
    char EventType, CharRoverType;
    TYPE TYP;
    double TLOC;
    int ED, ID, MDUR, SIG;


    //Now a loop over Events
    for (int i = 0; i < NumEvents; i++)
    {
        input >> EventType;
        if (EventType == 'F')
        {
            input >> CharRoverType >> ED >> ID >> TLOC >> MDUR >> SIG;
            switch (CharRoverType)
            {
                case 'M':
                    TYP = M;
                    break;
                case 'P':
                    TYP = P;
                    break;
                case 'E':
                    TYP = E;
                    break;
            }
            //Another sanity check:
//            cout << TYP << " " << ED  << " " << ID << " " << TLOC  << " " << MDUR << " " << SIG << "\n";
            //Now the core logic:
            FormEvents->enqueue(Formulation(TYP, ED, ID, MDUR, SIG, TLOC)); //Anonymous object getting passed.
            countFormulationEvent++;
        }
        if (EventType == 'X')
        {
            input >> ED >> ID;
            //Sanity check:
            //cout << ED << " " << ID << "\n";
            //Now the core logic:
            CancelEvents->enqueue(Cancellation(ED, ID));
            countCancellationEvent++;
        }
        if (EventType == 'P')
        {
            input >> ED >> ID;
            //Sanity check:
            //cout << ED << " " << ID << "\n";
            //Now the core logic:
            PromEvents->enqueue(Promotion(ED, ID));
            countPromotionEvent++;
        }
    }
    input.close();

    //Let's set up how the rover info struct should look for each type of rover
    struct roverInfo mountainousStruct = {SM, N, CM};
    struct roverInfo polarStruct = {SP, N, CP};
    struct roverInfo emergencyStruct = {SE, N, CE};

    //Now a loop to create the mountainous rovers.
    for (int i = 0; i < numM; i++)
    {
        MRovers->InsertEnd(Rover(M, mountainousStruct));
        countMountRovers++;
        TotalRovers++;
    }
    //Now a loop to create the polar rovers.
    for (int i = 0; i < numP; i++)
    {
        PRovers->InsertEnd(Rover(P, polarStruct));
        countPolarRovers++;
        TotalRovers++;
    }
    //Now a loop to create the polar rovers.
    for (int i = 0; i < numE; i++)
    {
        ERovers->InsertEnd(Rover(E, emergencyStruct));
        countEmergencytRovers++;
        TotalRovers++;
    }
}

void Station::simpleSimulator()
{
    countWaitingMountMissions=0;
    countWaitingPolarMissions=0;
    countWaitingEmrgMissions=0;
    countInServMountMissions=0;
    countInServPolarMissions=0;
    countInServEmrgMissions=0;
    countDoneMountMissions=0;
    countDonePolarMissions=0;
    countDoneEmrgMissions=0;
    countMountRovers = 0;
    countPolarRovers = 0;
    countEmergencytRovers = 0;
    TotalRovers = 0;
    countFormulationEvent = 0;
    countCancellationEvent = 0;
    countPromotionEvent = 0;

    fileLoader();
    cout << "# Of Rovers of Each Type (M P E) : " << countMountRovers << " " << countPolarRovers << " " << countEmergencytRovers << endl;
    cout << "# Formulation Events " << countFormulationEvent << " # Cancellation Events " << countCancellationEvent << " # Promotion Events " << countPromotionEvent << endl;

    int day = 0;
    int userInput;
    cout << "Enter 1 to increment days." << "\n";
    cin >> userInput;

    while( userInput == 1 )
    {
        if (WaitingEmrgMissions->isEmpty() && WaitingPolarMissions->isEmpty() && WaitingMountMissions->isEmpty() && InServEmrgMissions->isEmpty() && InServPolarMissions->isEmpty() && InServMountMissions->isEmpty() && FormEvents->isEmpty() && CancelEvents->isEmpty())
        {
            cout << "All Done! No Active Missions or Events (Except For Promotion events Which we ignored this phase)" << endl;
            break;
        }
        day++;
        cout << "Today is Day " << day << endl;
        Formulation F;
        Cancellation C;
        Node<Mission>* p = nullptr;
        for( int i = 0; i < countFormulationEvent; i++)
        {
            
            FormEvents->peek(F);
            if( F.getED() == day && FormEvents->peek(F))
            {
                //cout << F.getED() << " " << day << endl;
                FormEvents->dequeue(F);
                switch (F.getType())
                {
                case M: WaitingMountMissions->InsertEnd(Mission(M, F.getID(), F.getTLOC(), F.getSIG(), day, F.getMDUR()));
                    countWaitingMountMissions++;
                   
                    break;
                case P: WaitingPolarMissions->InsertEnd(Mission(P, F.getID(), F.getTLOC(), F.getSIG(), day, F.getMDUR()));
                    countWaitingPolarMissions++;
                    break;
                case E: WaitingEmrgMissions->InsertEnd(Mission(E, F.getID(), F.getTLOC(), F.getSIG(), day, F.getMDUR()));
                    countWaitingEmrgMissions++;
                    break;
               
                }
                
            }
            else
            {
                break;
            }
        }
       

        for( int i = 0; i < countCancellationEvent; i++)
        {
            CancelEvents->peek(C);
            p = WaitingMountMissions->getHead();
            if (C.getED() == day && CancelEvents->peek(C))
            {
                CancelEvents->dequeue(C);
                while (p)
                {
                    if (C.getID() == p->getItem().getID())
                    {
                        WaitingMountMissions->DeleteNode(p->getItem());
                        countWaitingMountMissions--;
                        break;
                    }
                    p = p->getNext();
                }
            }
            else
            {
                break;
            }
        }

        if (!WaitingMountMissions->isEmpty())
        {
            Mission mMp = WaitingMountMissions->getHead()->getItem();
            InServMountMissions->InsertEnd(mMp);
            WaitingMountMissions->DeleteFirst();
            countWaitingMountMissions--;
            countInServMountMissions++;



        }
        if (!WaitingPolarMissions->isEmpty())
        {
            Mission pMp = WaitingPolarMissions->getHead()->getItem();
            InServPolarMissions->InsertEnd(pMp);
            WaitingPolarMissions->DeleteFirst();
            countWaitingPolarMissions--;
            countInServPolarMissions++;



        }
        if (!WaitingEmrgMissions->isEmpty())
        {
            Mission eMp = WaitingEmrgMissions->getHead()->getItem();
            InServEmrgMissions->InsertEnd(eMp);
            WaitingEmrgMissions->DeleteFirst();
            countWaitingEmrgMissions--;
            countInServEmrgMissions++;

        }

        if (day % 5 == 0 && !InServMountMissions->isEmpty())
        {
            Mission mMp =InServMountMissions->getHead()->getItem();
            DoneMountMissions->InsertEnd(mMp);
            InServMountMissions->DeleteFirst();
            countInServMountMissions--;
            countDoneMountMissions++;


        }
        if (day % 5 == 0 && !InServPolarMissions->isEmpty())
        {
            Mission pMp = InServPolarMissions->getHead()->getItem();
            DonePolarMissions->InsertEnd(pMp);
            InServPolarMissions->DeleteFirst();
            countInServPolarMissions--;
            countDonePolarMissions++;

        }
        if (day%5 == 0 && !InServEmrgMissions->isEmpty())
        {
            Mission eMp = InServEmrgMissions->getHead()->getItem();
            DoneEmrgMissions->InsertEnd(eMp);
            InServEmrgMissions->DeleteFirst();
            countInServEmrgMissions--;
            countDoneEmrgMissions++;


        }
        cout << " Waiting Mountain Missions IDs: ";
        Node<Mission>* a = WaitingMountMissions->getHead();
        while (a != nullptr)
        {
            cout << a->getItem().getID() << " ";
            a = a->getNext();

        }
        cout << endl;
        cout << " Waiting Polar Missions IDs: ";
        Node<Mission>* b = WaitingPolarMissions->getHead();
        while (b != nullptr)
        {
            cout << b->getItem().getID() << " ";
            b = b->getNext();

        }
        cout << endl;

        cout << " Waiting  Emrgecy Missions IDs: ";

        Node<Mission>* c = WaitingEmrgMissions->getHead();
        while (c != nullptr)
        {
            cout << c->getItem().getID() << " ";
            c = c->getNext();

        }
        cout << endl;


        cout << " In Service Mountain Missions IDs: ";
         a = InServMountMissions->getHead();
        while (a != nullptr)
        {
            cout << a->getItem().getID() << " ";
            a = a->getNext();

        }
        cout << endl;
        cout << " In Service Polar Missions IDs: ";
        b = InServPolarMissions->getHead();
        while (b != nullptr)
        {
            cout << b->getItem().getID() << " ";
            b = b->getNext();

        }
        cout << endl;

        cout << " In Service  Emrgecy Missions IDs: ";

        c = InServEmrgMissions->getHead();
        while (c != nullptr)
        {
            cout << c->getItem().getID() << " ";
            c = c->getNext();

        }
        cout << endl;

        cout << " Done Mountain Missions IDs: ";
        a = DoneMountMissions->getHead();
        while (a != nullptr)
        {
            cout << a->getItem().getID() << " ";
            a = a->getNext();

        }
        cout << endl;
        cout << " Done Polar Missions IDs: ";
        b = DonePolarMissions->getHead();
        while (b != nullptr)
        {
            cout << b->getItem().getID() << " ";
            b = b->getNext();

        }
        cout << endl;

        cout << " Done  Emrgecy Missions IDs: ";

        c = DoneEmrgMissions->getHead();
        while (c != nullptr)
        {
            cout << c->getItem().getID() << " ";
            c = c->getNext();

        }
        cout << endl;



 

        cout << "# of  Waiting Missions (M P E) : " << countWaitingMountMissions<<" "<<countWaitingPolarMissions<<" "<<countWaitingEmrgMissions<<endl;
        cout << "# of  In Service Missions (M P E) : " << countInServMountMissions << " " << countInServPolarMissions << " " << countInServEmrgMissions << endl;
        cout << "# of  Done Missions (M P E) : " << countDoneMountMissions << " " << countDonePolarMissions << " " << countDoneEmrgMissions << endl;

   


        cout << "Enter 1 to increment days." << "\n";
        cin >> userInput;
    }
    cout << "Note: Since There's no rover assignment in this phase (Note 2 in document) then  # available rovers of each type remains unchanged and equal to initial number (first printed line) " << endl;
}