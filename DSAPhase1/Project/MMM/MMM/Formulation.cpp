#include "Formulation.h"

Formulation::Formulation(TYPE TYP1, int ED1, int ID1, double TLOC1, int MDUR1, int SIG1):Events (ED1, ID1)
{
	TLOC = TLOC1;
	MDUR = MDUR1;
	SIG = SIG1;
}
double Formulation::getTLOC()
{
	return TLOC;
}

int Formulation::getMDUR()
{
	return MDUR;
}

int Formulation::getSIG()
{
	return SIG;
}

