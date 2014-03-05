#include "node.h"

// Public Members

Node::Node()
{
  FIRING_THRESHOLD = 1.0;
  FIRING_STRENGTH = 0.8;
  CHARGE_DECAY_RATE = 0.02;
  currentCharge = 0;
}

void Node::fire()
{
  for (std::vector<Node*>::iterator out = outputs.begin(); 
       out != outputs.end(); 
       ++out)
  {
    (*out)->charge(FIRING_STRENGTH);
  }
}

void Node::charge(double strength)
{
  currentCharge += strength;
  while (currentCharge >= FIRING_THRESHOLD)
  {
    fire();
    currentCharge -= FIRING_THRESHOLD;
  }
}

void Node::update()
{
  currentCharge -= CHARGE_DECAY_RATE;
  if (currentCharge <= 0)
  {
    currentCharge = 0;
  }
}

double Node::get_current_charge()
{
  return currentCharge;
}

void Node::add_output(Node *out)
{
  outputs.push_back(out);
}
