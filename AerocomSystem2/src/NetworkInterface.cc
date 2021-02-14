#include "NetworkInterface.h"
#include <iostream>

Define_Module(NetworkInterface);

void NetworkInterface::initialize(int stage)
{
    if (stage == 2){
        // a questo punto siamo sicuri che l'Oracolo sia correttamente inizializzato
        cModule *temp = getModuleByPath("<root>.oracle");
        oracle = check_and_cast<Oracle*>(temp);

        int mode = getModuleByPath("<root>")->par("mode");
        if(mode == 1){
            //scegliamo un DL a caso tra quelli disponibili
            int DLnumber = getModuleByPath("<root>")->par("DLNumber").intValue();
            currentDL = oracle->getDL(intuniform(0, DLnumber-1));
        }
    }
}

void NetworkInterface::handleMessage(cMessage *msg)
{
    if (msg->isSelfMessage()) {
        // il service time per il pacchetto attuale e' finito
        serviceEnd();
    }
    else {
        //e' arrivato un nuovo pacchetto
        AeroPacket*pkt = check_and_cast<AeroPacket*>(msg);
        newPacket(pkt);
    }
}

void NetworkInterface::newPacket(AeroPacket *msg)
{

    if (this->servedPacket == 0){
        // il server e' vuoto
        serviceStart(msg);

    } else {
        //il pacchetto viene inserito in coda
        this->packetQueue.push(msg);
    }
    EV<<"new packet from the packet generator!"<<this->packetQueue.size() + 1<<endl;
}

void NetworkInterface::serviceStart(AeroPacket *pkt)
{
    //registriamo il queue leaving time
    pkt->setQueueLeavingTime(simTime());
    //il pacchetto viene servito
    this->servedPacket = pkt;

    double capacity = 0;
    if(getModuleByPath("<root>")->par("mode").intValue() == 2) {
        //selezioniamo il miglior canale, e la sua capacita'
        oracle->getDLAndCapacity(currentDL, capacity);
    }
    else
        //rimaniamo sullo stesso DL, e otteniamo la sua capacita'
        capacity = oracle->getCapacity(currentDL);

    //calcoliamo il service time e settiamo il timer
    simtime_t serviceTime = pkt->getPacketLength() / capacity;
    scheduleAt(serviceTime + simTime(), this->beep);
    EV<<"Packet out of the server scheduled at: "<<serviceTime + simTime()<<endl;
}

void NetworkInterface::serviceEnd()
{
    //registriamo l'instante in cui il pacchetto lascia l'interfaccia
    this->servedPacket->setIfaceLeavingTime(simTime());

    sendDirect(this->servedPacket, currentDL, "dataLinkIn");
    EV<<"packet leaves!"<<this->packetQueue.size() + 1<<endl;

    //se ci sono ancora pacchetti in coda, serviamo il prossimo
    if (this->packetQueue.size() != 0) {
        serviceStart(this->packetQueue.front());
        this->packetQueue.pop();
    } else {
        // la coda e' vuota
        this->servedPacket = 0;
    }
}
