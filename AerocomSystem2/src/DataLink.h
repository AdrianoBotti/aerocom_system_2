#ifndef __AEROCOMSYSTEM2_DATALINK_H_
#define __AEROCOMSYSTEM2_DATALINK_H_

#include <omnetpp.h>
#include "aeroPacket_m.h"

using namespace omnetpp;

class DataLink : public cSimpleModule
{
  private:
    cMessage *beep;
    double initialCapacity; //la capacita' varia linearmente dal valore iniziale a quello finale
    double finalCapacity;
    simtime_t intervalLength; //intervallo di tempo nel quale la capacita' raggiunge il suo nuovo valore finale
    simtime_t intervalStart; // inizio dell'intervallo, necessario per calcolare la current capacity

    void computeParameters();
    void deliverMessage(cMessage *msg);
    simtime_t getIntervalLength();

  protected:
    virtual void initialize(int stage);
    virtual void handleMessage(cMessage *msg);
    virtual int numInitStages()const{return 1;}
  public:
    double getCurrentCapacity();
};

#endif
