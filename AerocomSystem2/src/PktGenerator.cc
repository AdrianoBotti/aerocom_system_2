#include "PktGenerator.h"
#include "aeroPacket_m.h"

Define_Module(PktGenerator);

void PktGenerator::initialize()
{
    this->beep = new cMessage("beep");
    simtime_t intervalLength = exponential(par("mean").doubleValue(), 0);

    //inizializziamo il timer per il primo invio
    scheduleAt(simTime() + intervalLength, this->beep);
}

void PktGenerator::handleMessage(cMessage *beep){ //riceve solo selfMessage
   //prepariamo un nuovo pacchetto
    AeroPacket *msg = new AeroPacket();
    msg->setGenerationTime(simTime());
    int sender = getParentModule()->getId();//id dell'AC
    msg->setSender(sender);
    int packetLength = par("packetLength").intValue();
    msg->setPacketLength(packetLength);

    //inviamo il messaggio all'interfaccia di rete
    send(msg, "out");
    //viene schedulato un nuovo pacchetto
    simtime_t intervalLength = exponential(par("mean").doubleValue());
    scheduleAt(simTime() + intervalLength, this->beep);
}
