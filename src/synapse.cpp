#include "synapse.h"

// Public Members

Synapse::Synapse(Node *start, Node *end);
{
  PERMITTIVITY = 0.1;
  start->add_output(&this);
  add_output(end);
}

void Synapse::charge(double strength)
{
  if (currentCharge < strength)
  {
    currentCharge = strength;
  }
}

void Synapse::update()
{
  for (std::vector<Node*>::iterator out = outputs.start(); 
       out != outputs.end(); 
       ++out)
  {
    out->charge(self.currentCharge * PERMITTIVITY);
  }
  Node::update();
}
