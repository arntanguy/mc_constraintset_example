#include "Test.h"
#include <mc_rbdyn/RobotModule.h>
#include <mc_solver/CompoundJointConstraint.h>

Test::Test(mc_rbdyn::RobotModulePtr rm, double dt,
           const mc_rtc::Configuration &config)
    : mc_control::fsm::Controller(rm, dt, config,
                                  mc_control::ControllerParameters{}
                                      .load_robot_config_into({})
                                      .overwrite_config(true)) {

  mc_rtc::log::success("Test init done ");
}

bool Test::run() { return mc_control::fsm::Controller::run(); }

void Test::reset(const mc_control::ControllerResetData &reset_data) {
  mc_control::fsm::Controller::reset(reset_data);
}
