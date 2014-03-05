#include "gtest/gtest.h"

#include "node.h"

#define DELTA 0.0001

class NodeTest : public ::testing::Test {
  protected:
  Node node, output;
  
  virtual void SetUp()
  {
    node.add_output(&output);
  }
};

TEST_F(NodeTest, DefaultValueTest)
{
  EXPECT_LE(node.get_current_charge(), DELTA) << "Initialised with 0 charge.";
}

TEST_F(NodeTest, ChargeTest)
{
  node.charge(0.5);
  EXPECT_LE(node.get_current_charge() - 0.5, DELTA) << "Charge is added.";
}

TEST_F(NodeTest, UpdateTest)
{
  node.update();
  EXPECT_LE(node.get_current_charge(), DELTA) << "Doesn't decay below 0.";
  node.charge(0.5);
  EXPECT_LE(node.get_current_charge() - 0.5, DELTA) << "Charge up.";
  node.update();
  EXPECT_LE(node.get_current_charge() - 0.48, DELTA) << "Decays on update.";
}

TEST_F(NodeTest, FireTest)
{
  node.charge(1.5);
  EXPECT_LE(node.get_current_charge() - 0.5, DELTA) << "Charge wraps.";
  EXPECT_LE(output.get_current_charge() - 0.8, DELTA) << "Output is charged.";
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
