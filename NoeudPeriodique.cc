#include "NoeudPeriodique.h"
#include <string.h>
#include <string>

Define_Module(NoeudPeriodique);

NoeudPeriodique::~NoeudPeriodique()
{
    cancelAndDelete(timer);
}

void NoeudPeriodique::initialize()
{
    nbr = par("nb");
    d = par("d");
    compteur = 0;
    timer = nullptr;

    WATCH(compteur);
    WATCH(nbr);

    // Seul n1 envoie periodiquement : il programme son timer
    if (strcmp("n1", getName()) == 0) {
        timer = new cMessage("Timer");
        scheduleAt(simTime() + d, timer);
    }
}

void NoeudPeriodique::handleMessage(cMessage *msg)
{
    if (msg->isSelfMessage()) {
        // Le timer de n1 a expire : on envoie un nouveau message
        compteur++;
        std::string nom = "message" + std::to_string(compteur);
        cMessage *m = new cMessage(nom.c_str());

        EV << "n1 envoie " << nom << " (" << compteur << "/" << nbr << ")\n";
        send(m, "out");

        // On reprogramme le timer tant qu'on n'a pas envoye nb messages
        if (compteur < nbr)
            scheduleAt(simTime() + d, timer);
    }
    else if (strcmp("n10", getName()) == 0) {
        // Dernier noeud : il supprime le message
        EV << "n10 a recu " << msg->getName() << " : je le supprime\n";
        delete msg;
    }
    else {
        // Noeuds intermediaires : ils transferent le message
        EV << "Le message " << msg->getName()
           << " est bien recu! Je le transfere a mon tour (" << getName() << ")\n";
        send(msg, "out");
    }
}
