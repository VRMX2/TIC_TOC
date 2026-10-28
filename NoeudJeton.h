#ifndef NOEUDJETON_H_
#define NOEUDJETON_H_

#include <omnetpp.h>
using namespace omnetpp;

class NoeudJeton : public cSimpleModule
{
  private:
    int tours;
    int maxTours;

  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

#endif
