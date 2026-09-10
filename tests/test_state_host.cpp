#ifdef FAIL
#undef FAIL
#endif
#ifdef ERROR
#undef ERROR
#endif

#include <xyz/openbmc_project/State/Host/common.hpp>

#include <gtest/gtest.h>

#include <map>
#include <set>
#include <stdexcept>
#include <string>

namespace {

using Host = sdbusplus::common::xyz::openbmc_project::state::Host;
using Transition = Host::Transition;
using HostState = Host::HostState;
using RestartCause = Host::RestartCause;

// ── Interface name
// ────────────────────────────────────────────────────────────

TEST(StateHostInterface, InterfaceName) {
  EXPECT_STREQ(Host::interface, "xyz.openbmc_project.State.Host");
}

// ── Transition enum → string
// ──────────────────────────────────────────────────

TEST(HostTransitionToString, Off) {
  EXPECT_EQ(Host::convertTransitionToString(Transition::Off),
            "xyz.openbmc_project.State.Host.Transition.Off");
}

TEST(HostTransitionToString, On) {
  EXPECT_EQ(Host::convertTransitionToString(Transition::On),
            "xyz.openbmc_project.State.Host.Transition.On");
}

TEST(HostTransitionToString, Reboot) {
  EXPECT_EQ(Host::convertTransitionToString(Transition::Reboot),
            "xyz.openbmc_project.State.Host.Transition.Reboot");
}

TEST(HostTransitionToString, GracefulWarmReboot) {
  EXPECT_EQ(Host::convertTransitionToString(Transition::GracefulWarmReboot),
            "xyz.openbmc_project.State.Host.Transition.GracefulWarmReboot");
}

TEST(HostTransitionToString, ForceWarmReboot) {
  EXPECT_EQ(Host::convertTransitionToString(Transition::ForceWarmReboot),
            "xyz.openbmc_project.State.Host.Transition.ForceWarmReboot");
}

// ── Transition string → enum
// ──────────────────────────────────────────────────

TEST(HostTransitionFromString, Off) {
  EXPECT_EQ(Host::convertTransitionFromString(
                "xyz.openbmc_project.State.Host.Transition.Off"),
            Transition::Off);
}

TEST(HostTransitionFromString, On) {
  EXPECT_EQ(Host::convertTransitionFromString(
                "xyz.openbmc_project.State.Host.Transition.On"),
            Transition::On);
}

TEST(HostTransitionFromString, Reboot) {
  EXPECT_EQ(Host::convertTransitionFromString(
                "xyz.openbmc_project.State.Host.Transition.Reboot"),
            Transition::Reboot);
}

TEST(HostTransitionFromString, InvalidThrows) {
  EXPECT_THROW(Host::convertTransitionFromString("xyz.invalid"),
               sdbusplus::exception::InvalidEnumString);
}

// ── HostState enum → string
// ───────────────────────────────────────────────────

TEST(HostStateToString, Off) {
  EXPECT_EQ(Host::convertHostStateToString(HostState::Off),
            "xyz.openbmc_project.State.Host.HostState.Off");
}

TEST(HostStateToString, TransitioningToOff) {
  EXPECT_EQ(Host::convertHostStateToString(HostState::TransitioningToOff),
            "xyz.openbmc_project.State.Host.HostState.TransitioningToOff");
}

TEST(HostStateToString, Standby) {
  EXPECT_EQ(Host::convertHostStateToString(HostState::Standby),
            "xyz.openbmc_project.State.Host.HostState.Standby");
}

TEST(HostStateToString, Running) {
  EXPECT_EQ(Host::convertHostStateToString(HostState::Running),
            "xyz.openbmc_project.State.Host.HostState.Running");
}

TEST(HostStateToString, TransitioningToRunning) {
  EXPECT_EQ(Host::convertHostStateToString(HostState::TransitioningToRunning),
            "xyz.openbmc_project.State.Host.HostState.TransitioningToRunning");
}

TEST(HostStateToString, Quiesced) {
  EXPECT_EQ(Host::convertHostStateToString(HostState::Quiesced),
            "xyz.openbmc_project.State.Host.HostState.Quiesced");
}

TEST(HostStateToString, DiagnosticMode) {
  EXPECT_EQ(Host::convertHostStateToString(HostState::DiagnosticMode),
            "xyz.openbmc_project.State.Host.HostState.DiagnosticMode");
}

// ── HostState string → enum
// ───────────────────────────────────────────────────

TEST(HostStateFromString, Running) {
  EXPECT_EQ(Host::convertHostStateFromString(
                "xyz.openbmc_project.State.Host.HostState.Running"),
            HostState::Running);
}

TEST(HostStateFromString, InvalidThrows) {
  EXPECT_THROW(Host::convertHostStateFromString("xyz.invalid"),
               sdbusplus::exception::InvalidEnumString);
}

TEST(HostStateConvertStringTo, ValidReturnsValue) {
  auto r = Host::convertStringToHostState(
      "xyz.openbmc_project.State.Host.HostState.Off");
  ASSERT_TRUE(r.has_value());
  EXPECT_EQ(*r, HostState::Off);
}

TEST(HostStateConvertStringTo, InvalidReturnsNullopt) {
  EXPECT_FALSE(Host::convertStringToHostState("xyz.invalid").has_value());
}

// ── RestartCause enum → string
// ────────────────────────────────────────────────

TEST(RestartCauseToString, Unknown) {
  EXPECT_EQ(Host::convertRestartCauseToString(RestartCause::Unknown),
            "xyz.openbmc_project.State.Host.RestartCause.Unknown");
}

TEST(RestartCauseToString, RemoteCommand) {
  EXPECT_EQ(Host::convertRestartCauseToString(RestartCause::RemoteCommand),
            "xyz.openbmc_project.State.Host.RestartCause.RemoteCommand");
}

TEST(RestartCauseToString, ResetButton) {
  EXPECT_EQ(Host::convertRestartCauseToString(RestartCause::ResetButton),
            "xyz.openbmc_project.State.Host.RestartCause.ResetButton");
}

TEST(RestartCauseToString, PowerButton) {
  EXPECT_EQ(Host::convertRestartCauseToString(RestartCause::PowerButton),
            "xyz.openbmc_project.State.Host.RestartCause.PowerButton");
}

TEST(RestartCauseToString, WatchdogTimer) {
  EXPECT_EQ(Host::convertRestartCauseToString(RestartCause::WatchdogTimer),
            "xyz.openbmc_project.State.Host.RestartCause.WatchdogTimer");
}

TEST(RestartCauseToString, PowerPolicyAlwaysOn) {
  EXPECT_EQ(
      Host::convertRestartCauseToString(RestartCause::PowerPolicyAlwaysOn),
      "xyz.openbmc_project.State.Host.RestartCause.PowerPolicyAlwaysOn");
}

TEST(RestartCauseToString, PowerPolicyPreviousState) {
  EXPECT_EQ(
      Host::convertRestartCauseToString(RestartCause::PowerPolicyPreviousState),
      "xyz.openbmc_project.State.Host.RestartCause.PowerPolicyPreviousState");
}

TEST(RestartCauseToString, SoftReset) {
  EXPECT_EQ(Host::convertRestartCauseToString(RestartCause::SoftReset),
            "xyz.openbmc_project.State.Host.RestartCause.SoftReset");
}

TEST(RestartCauseToString, ScheduledPowerOn) {
  EXPECT_EQ(Host::convertRestartCauseToString(RestartCause::ScheduledPowerOn),
            "xyz.openbmc_project.State.Host.RestartCause.ScheduledPowerOn");
}

TEST(RestartCauseToString, HostCrash) {
  EXPECT_EQ(Host::convertRestartCauseToString(RestartCause::HostCrash),
            "xyz.openbmc_project.State.Host.RestartCause.HostCrash");
}

// ── RestartCause string → enum
// ────────────────────────────────────────────────

TEST(RestartCauseFromString, SoftReset) {
  EXPECT_EQ(Host::convertRestartCauseFromString(
                "xyz.openbmc_project.State.Host.RestartCause.SoftReset"),
            RestartCause::SoftReset);
}

TEST(RestartCauseFromString, InvalidThrows) {
  EXPECT_THROW(Host::convertRestartCauseFromString("xyz.invalid"),
               sdbusplus::exception::InvalidEnumString);
}

// ── property names
// ────────────────────────────────────────────────────────────

TEST(StateHostPropertyNames, RequestedHostTransition) {
  EXPECT_STREQ(Host::property_names::requested_host_transition,
               "RequestedHostTransition");
}

TEST(StateHostPropertyNames, CurrentHostState) {
  EXPECT_STREQ(Host::property_names::current_host_state, "CurrentHostState");
}

// ── unpack
// ────────────────────────────────────────────────────────────────────

TEST(StateHostPropertiesUnpack, ValidMap_Unpacks) {
  std::map<std::string, Host::PropertiesVariant> props;
  props["RequestedHostTransition"] = Transition::On;
  props["CurrentHostState"] = HostState::Running;
  props["RestartCause"] = RestartCause::RemoteCommand;

  Host::properties_t result{};
  ASSERT_NO_THROW(result = Host::properties_t::unpack(props));
  EXPECT_EQ(result.requested_host_transition, Transition::On);
  EXPECT_EQ(result.current_host_state, HostState::Running);
  EXPECT_EQ(result.restart_cause, RestartCause::RemoteCommand);
}

TEST(StateHostPropertiesUnpack, EmptyMap_UsesDefaults) {
  std::map<std::string, Host::PropertiesVariant> props;
  Host::properties_t result{};
  ASSERT_NO_THROW(result = Host::properties_t::unpack(props));
}

} // namespace
