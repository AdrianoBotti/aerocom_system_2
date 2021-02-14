#ifndef __AEROCOMSYSTEM2_DATALINKINTERFACE_H_
#define __AEROCOMSYSTEM2_DATALINKINTERFACE_H_

#include <omnetpp.h>
#include <queue>
#include "DataLink.h"
#include "aeroPacket_m.h"
#include "Oracle.h"

using namespace omnetpp;


class NetworkInterface : public cSimpleModule
{
  private:
    Oracle *oracle;
    DataLink* currentDL = NULL;
    std::queue<AeroPacket*> packetQueue; //coda dei pacchetti in attesa
    AeroPacket *servedPacket = 0; //puntatore al pacchetto attualmente servito
    cMessage *beep = new cMessage("beep");
  protected:
    virtual void initialize(int stage);
    virtual void handleMessage(cMessage *msg);
    virtual int numInitStages () const {return 3;} //all'inizio, i DL devono essere inizializzati
    virtual void serviceStart(AeroPacket *msg); //inizio a servire un pacchetto
    virtual void serviceEnd(); //fine del servizio di un pacchetto
    virtual void newPacket(AeroPacket *msg); //e'arrivato un nuovo pacchetto
};

#endif
