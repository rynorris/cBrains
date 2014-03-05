#ifndef CBRAINS_NODE_H
#define CBRAINS_NODE_H

#include <vector>

class Node {
  public:
    Node();
    virtual void fire();
    virtual void charge(double strength);
    virtual void update();
    double get_current_charge();
    void add_output(Node *out);

  private:
    double FIRING_THRESHOLD;
    double FIRING_STRENGTH;
    double CHARGE_DECAY_RATE;
    double currentCharge;
    std::vector<Node*> outputs;
};

#endif // CBRAINS_NODE_H
