#ifndef __AEROCOMSYSTEM2_PKTGENERATOR_H_
#define __AEROCOMSYSTEM2_PKTGENERATOR_H_

#include <omnetpp.h>

using namespace omnetpp;

class PktGenerator : public cSimpleModule
{
  private:
    cMessage *beep;
  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

#endif
