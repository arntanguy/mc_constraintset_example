#include "Test_Initial.h"

#include "../Test.h"

void Test_Initial::addRemoveCollisions(mc_control::fsm::Controller &ctl_,
                                       bool add = true, bool before = true) {
  const auto &stateConfig = config_;
  const auto &ctlConfig = ctl_.config();
  std::string name = fmt::format("{}CollisionSets{}", add ? "Add" : "Remove",
                                 before ? "Before" : "After");
  if (auto addCollisionSets = stateConfig.find(name)) {
    if (addCollisionSets->size()) {
      if (auto robotCollisionSets = ctlConfig.find("collision_sets")
                                        .value_or(mc_rtc::Configuration{})
                                        .find(ctl_.robot().name())) {
        for (const auto &setName : *addCollisionSets) {
          if (auto collisionSet = robotCollisionSets->find(setName)) {
            auto colSet = *collisionSet;
            auto r1 = colSet("r1", ctl_.robot().name());
            auto r2 = colSet("r2", ctl_.robot().name());
            auto collisions =
                colSet("collisions", std::vector<mc_rbdyn::Collision>{});
            if (add) {
              mc_rtc::log::info("Adding collision set {} for robot {}", setName,
                                ctl_.robot().name());
              ctl_.addCollisions(r1, r2, collisions);
            } else {
              mc_rtc::log::info("Removing collision set {} for robot {}",
                                setName, ctl_.robot().name());
              ctl_.removeCollisions(r1, r2, collisions);
            }
          }
        }
      }
    }
  }
}

void Test_Initial::start(mc_control::fsm::Controller &ctl_) {
  auto &ctl = static_cast<Test &>(ctl_);

  addRemoveCollisions(ctl, true, true);
  addRemoveCollisions(ctl, false, true);
}

bool Test_Initial::run(mc_control::fsm::Controller &ctl_) {
  auto &ctl = static_cast<Test &>(ctl_);
  output("OK");
  return true;
}

void Test_Initial::teardown(mc_control::fsm::Controller &ctl_) {
  auto &ctl = static_cast<Test &>(ctl_);
  addRemoveCollisions(ctl, true, false);
  addRemoveCollisions(ctl, false, false);
}

EXPORT_SINGLE_STATE("Test_Initial", Test_Initial)
