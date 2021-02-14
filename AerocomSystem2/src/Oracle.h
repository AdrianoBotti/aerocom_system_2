/*****************************/
/* E' stato utilizzato un modulo Oracolo al fine di simulare il protocollo  */
/* di channel sensing delle interfacce di rete                              */
/*****************************/

#ifndef __AEROCOMSYSTEM2_ORACLE_H_
#define __AEROCOMSYSTEM2_ORACLE_H_

#include <omnetpp.h>
#include "DataLink.h"
#include "aeroPacket_m.h"

using namespace omnetpp;

class Oracle : public cSimpleModule
{
private:
    int dataLinkNumber;
    DataLink** datalink; //array di puntatori a DL
    int currentChannel = 0; //indice del miglior DL nell'array
    virtual int numInitStages()const {return 2;}
  protected:
    virtual void initialize(int stage);
    virtual void handleMessage(cMessage *msg);
  public:
    void getDLAndCapacity(DataLink*& bestDL, double& bestCapacity); // modo 2
    double getCapacity(DataLink* currentDL);
    DataLink* getDL(int index);

};

#endif
