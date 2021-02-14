#ifndef __AEROCOMSYSTEM2_CONTROLTOWER_H_
#define __AEROCOMSYSTEM2_CONTROLTOWER_H_

#include <omnetpp.h>

using namespace omnetpp;

class ControlTower : public cSimpleModule
{
  private:
    simsignal_t responseTimeSignal;
    simsignal_t throughputSignal;
  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

#endif
