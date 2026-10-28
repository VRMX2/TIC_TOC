#include "NoeudJeton.h"
#include <string.h>

Define_Module(NoeudJeton);

void NoeudJeton::initialize()
{
    tours = 0;
    maxTours = par("maxTours");

    if (strcmp("n1", getName()) == 0) {
        cMessage *jeton = new cMessage("jeton");
        EV << "n1 envoie le jeton\n";
        send(jeton, "out");
    }
}

void NoeudJeton::handleMessage(cMessage *msg)
{
    if (strcmp("n1", getName()) == 0) {
        tours++;
        EV << "n1 a recu le jeton : tour " << tours << " termine\n";

        if (tours == maxTours) {
            EV << "Le jeton est stoppe au niveau de n1 apres "
               << maxTours << " tours complets\n";
            delete msg;
            return;
        }
    }
    else {
        EV << getName() << " a recu le jeton\n";
    }

    send(msg, "out");
}
