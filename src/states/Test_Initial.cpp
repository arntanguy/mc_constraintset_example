#include "Test_Initial.h"

#include "../Test.h"

void Test_Initial::configure(const mc_rtc::Configuration & config)
{
}

void Test_Initial::start(mc_control::fsm::Controller & ctl_)
{
  auto & ctl = static_cast<Test &>(ctl_);
}

bool Test_Initial::run(mc_control::fsm::Controller & ctl_)
{
  auto & ctl = static_cast<Test &>(ctl_);
  output("OK");
  return true;
}

void Test_Initial::teardown(mc_control::fsm::Controller & ctl_)
{
  auto & ctl = static_cast<Test &>(ctl_);
}

EXPORT_SINGLE_STATE("Test_Initial", Test_Initial)
