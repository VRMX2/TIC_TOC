#ifndef NOEUDPERIODIQUE_H_
#define NOEUDPERIODIQUE_H_

#include <omnetpp.h>
using namespace omnetpp;

class NoeudPeriodique : public cSimpleModule
{
  private:
    int nbr;         // nombre d'envois a effectuer (parametre nb)
    double d;        // delai entre deux envois (parametre d)
    int compteur;    // nombre de messages deja envoyes par n1
    cMessage *timer; // self-message utilise par n1

  public:
    virtual ~NoeudPeriodique();

  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

#endif
