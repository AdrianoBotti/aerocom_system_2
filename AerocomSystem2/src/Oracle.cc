#include "Oracle.h"

Define_Module(Oracle);

void Oracle::initialize(int stage)
{
    if (stage == 1) { //prima devono essere inizializzati i DL
    //creiamo un array di DL
        this->dataLinkNumber = this->getParentModule()->par("DLNumber").intValue();
        this->datalink = new DataLink*[this->dataLinkNumber];
        for (int i=0; i<this->dataLinkNumber; ++i) {
        datalink[i] = check_and_cast<DataLink*>(this->getParentModule()->getSubmodule("datalink", i));
        }
    }
}

void Oracle::handleMessage(cMessage *msg)
{
}

void Oracle::getDLAndCapacity(DataLink*& bestDL, double& bestCapacity)
{ //chiamata nel modo 2, serve ad ottenere il miglior DL e la sua capacita'
    int currentChannel = 3;
    double currentCapacity = 3;

    for (int i=0; i<this->dataLinkNumber; ++i) {
        double capacity = this->datalink[i]->getCurrentCapacity();
        EV<<i<<" : "<<capacity<<endl;
        if (capacity > currentCapacity) {
            currentChannel = i;
            currentCapacity = capacity;
        }
    }
    //si applica la percentuale di Malus
    bestCapacity = currentCapacity * (1 - par("malus").doubleValue());
    bestDL = this->datalink[currentChannel];
}

double Oracle::getCapacity(DataLink* currentDL)
{
    return currentDL->getCurrentCapacity();
}

DataLink* Oracle::getDL(int index)
{
    return datalink[index];
}
