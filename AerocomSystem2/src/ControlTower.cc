#include "ControlTower.h"
#include "aeroPacket_m.h"

Define_Module(ControlTower);

void ControlTower::initialize()
{
    //si registrano i segnali del response time e waiting time
    this->responseTimeSignal = registerSignal("responseTimeSignal");
    this->throughputSignal = registerSignal("throughputSignal");   // usato nel consistency test
}

void ControlTower::handleMessage(cMessage *msg)
{
    AeroPacket *pkt = check_and_cast<AeroPacket*>(msg);
    pkt->setControlTowerArrivalTime(simTime());
    EV<<"message received!"<<endl;
    EV<<"generation time: "<<pkt->getGenerationTime()<<endl;
    EV<<"queue leaving time: "<<pkt->getQueueLeavingTime()<<endl;
    EV<<"service end time: "<<pkt->getIfaceLeavingTime()<<endl;
    // si registrano le statistiche
    emit(this->responseTimeSignal, pkt->getIfaceLeavingTime() - pkt->getGenerationTime());
    emit(this->throughputSignal, 1);
    delete msg;
}
