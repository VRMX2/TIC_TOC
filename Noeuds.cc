#include <omnetpp.h>
#include "RouteMsg_m.h"

using namespace omnetpp;

class NoeudRoute : public cSimpleModule
{
  private:
    int nbRecus = 0;
    int nbEnvoyes = 0;
    void forwardRandom(RouteMsg *m);
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void finish() override;
};

Define_Module(NoeudRoute);

void NoeudRoute::initialize()
{
    if (getIndex() == 0) {                       // source node
        RouteMsg *m = new RouteMsg("route");
        m->setSource(0);
        m->setDestination(9);
        m->setHopCount(0);
        EV << "Node 0 creates the message for node 9" << endl;
        forwardRandom(m);
    }
}

void NoeudRoute::forwardRandom(RouteMsg *m)
{
    int n = gateSize("p$o");                     // number of output gates
    int k = intuniform(0, n - 1);                // random neighbour
    EV << "Node " << getIndex() << " forwards via gate " << k << endl;
    send(m, "p$o", k);
    nbEnvoyes++;
}

void NoeudRoute::handleMessage(cMessage *msg)
{
    RouteMsg *m = check_and_cast<RouteMsg *>(msg);   // cast cMessage -> RouteMsg
    nbRecus++;
    m->setHopCount(m->getHopCount() + 1);

    cGate *g = m->getArrivalGate();
    EV << "Node " << getIndex() << " received message from gate "
       << g->getIndex() << " (hops: " << m->getHopCount() << ")" << endl;

    if (m->getDestination() == getIndex()) {
        EV << "*** Node " << getIndex() << " is the destination. Hops: "
           << m->getHopCount() << " ***" << endl;
        bubble("Arrived!");
        delete m;
    } else {
        forwardRandom(m);
    }
}

void NoeudRoute::finish()
{
    EV << "Node " << getIndex() << ": received=" << nbRecus
       << ", sent=" << nbEnvoyes << endl;
    recordScalar("#received", nbRecus);
    recordScalar("#sent", nbEnvoyes);
}
