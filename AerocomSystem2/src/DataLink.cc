#include "DataLink.h"

Define_Module(DataLink);

// ogni DL utilizza due RNG, uno per la capacita'(#0), uno per la lunghezza dell'intervallo (#1)
void DataLink::initialize(int stage)
{
    // i DL devono essere inizializzati per primi
    if (stage == 0){
        this->beep = new cMessage("beep");
        this->initialCapacity = uniform(par("minCapacity").doubleValue(), par("maxCapacity").doubleValue(), 0);
        this->finalCapacity = uniform(par("minCapacity").doubleValue(), par("maxCapacity").doubleValue(), 0);
        this->intervalLength = getIntervalLength();
        this->intervalStart = 0;
        scheduleAt(this->intervalLength, this->beep);
    }
}

void DataLink::handleMessage(cMessage *msg)
{
    if (msg->isSelfMessage()) {
        //calcola una nuova capacita' e un nuovo intervallo
        computeParameters();
    } else {
        // invia il messaggio alla CT
        deliverMessage(msg);
    }
}

void DataLink::computeParameters()
{
    //nuovo intervallo
    this->intervalLength = getIntervalLength();
    this->intervalStart = simTime();
    //nuova capacita'
    this->initialCapacity = this->finalCapacity;
    this->finalCapacity = uniform(par("minCapacity").doubleValue(), par("maxCapacity").doubleValue(), 0);
    //timer per il ricalcolo
    scheduleAt(this->intervalLength + simTime(), this->beep);

    //debug
    EV<<"intervalLength:\t"<<intervalLength<<endl;
    EV<<"initialCapacity:\t"<<initialCapacity<<endl;
    EV<<"finalCapacity:\t"<<finalCapacity<<endl;
}

void DataLink::deliverMessage(cMessage *msg)
{
    //invia il messaggio alla CT
    send(msg, "dataLinkOut");
}


simtime_t DataLink::getIntervalLength ()
{
    // controlla a quale distribuzione appartengono gli intervalli e prende
    // un valore dallo stream corretto

    simtime_t intervalLength;
    std::string distribution (par("distribution").stringValue());
    if (distribution.compare("exp") == 0) {
        intervalLength = exponential(par("distrMean").doubleValue(), 1);
    } else if (distribution.compare("lognorm") == 0) {
        intervalLength = lognormal(par("distrMean").doubleValue(), par("distrVar").doubleValue(), 1);
    }
    return intervalLength;
}

double DataLink::getCurrentCapacity() {
    double deltaY = this->finalCapacity - this->initialCapacity;
    double deltaX = this->intervalLength.dbl();
    double currentX = simTime().dbl() - this->intervalStart.dbl();
    return (deltaY / deltaX) * currentX + this->initialCapacity;
}
