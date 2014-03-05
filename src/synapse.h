#ifndef CBRAINS_SYNAPSE_H
#define CBRAINS_SYNAPSE_H

#include "node.h"

class Synapse : public Node 
{
  public:
    Synapse();

  private:
    double PERMITTIVITY;
};

#endif // CBRAINS_SYNAPSE_H
