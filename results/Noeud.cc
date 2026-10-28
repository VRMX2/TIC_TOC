#include "Noeud.h"
#include "string.h"

Define_Module(Noeud);

void Noeud::initialize()
{
    if (strcmp("tic", getName()) == 0) {
        cMessage *msg = new cMessage("Hello!");
        send(msg, "out");
     }
}
void Noeud::handleMessage(cMessage *msg)
{
 send(msg, "out");
}


