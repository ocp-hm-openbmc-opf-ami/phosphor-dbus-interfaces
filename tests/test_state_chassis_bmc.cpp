#ifdef FAIL
#undef FAIL
#endif
#ifdef ERROR
#undef ERROR
#endif

#include <xyz/openbmc_project/State/BMC/common.hpp>
#include <xyz/openbmc_project/State/Chassis/common.hpp>

#include <map>
#include <stdexcept>
#include <string>

#include <gtest/gtest.h>

namespace
{

// ────────────────────────────────────────────────────────────────── Chassis ──

using Chassis = sdbusplus::common::xyz::openbmc_project::state::Chassis;
using ChassisTransition = Chassis::Transition;
using PowerState = Chassis::PowerState;
using PowerStatus = Chassis::PowerStatus;

TEST(ChassisInterface, InterfaceName)
{
    EXPECT_STREQ(Chassis::interface, "xyz.openbmc_project.State.Chassis");
}

// Transition
TEST(ChassisTransitionToString, Off)
{
    EXPECT_EQ(Chassis::convertTransitionToString(ChassisTransition::Off),
              "xyz.openbmc_project.State.Chassis.Transition.Off");
}

TEST(ChassisTransitionToString, On)
{
    EXPECT_EQ(Chassis::convertTransitionToString(ChassisTransition::On),
              "xyz.openbmc_project.State.Chassis.Transition.On");
}

TEST(ChassisTransitionToString, PowerCycle)
{
    EXPECT_EQ(Chassis::convertTransitionToString(ChassisTransition::PowerCycle),
              "xyz.openbmc_project.State.Chassis.Transition.PowerCycle");
}

TEST(ChassisTransitionFromString, On)
{
    EXPECT_EQ(Chassis::convertTransitionFromString(
                  "xyz.openbmc_project.State.Chassis.Transition.On"),
              ChassisTransition::On);
}

TEST(ChassisTransitionFromString, InvalidThrows)
{
    EXPECT_THROW(Chassis::convertTransitionFromString("xyz.invalid"),
                 sdbusplus::exception::InvalidEnumString);
}

// PowerState
TEST(ChassisPowerStateToString, Off)
{
    EXPECT_EQ(Chassis::convertPowerStateToString(PowerState::Off),
              "xyz.openbmc_project.State.Chassis.PowerState.Off");
}

TEST(ChassisPowerStateToString, TransitioningToOff)
{
    EXPECT_EQ(
        Chassis::convertPowerStateToString(PowerState::TransitioningToOff),
        "xyz.openbmc_project.State.Chassis.PowerState.TransitioningToOff");
}

TEST(ChassisPowerStateToString, On)
{
    EXPECT_EQ(Chassis::convertPowerStateToString(PowerState::On),
              "xyz.openbmc_project.State.Chassis.PowerState.On");
}

TEST(ChassisPowerStateToString, TransitioningToOn)
{
    EXPECT_EQ(Chassis::convertPowerStateToString(PowerState::TransitioningToOn),
              "xyz.openbmc_project.State.Chassis.PowerState.TransitioningToOn");
}

TEST(ChassisPowerStateFromString, On)
{
    EXPECT_EQ(Chassis::convertPowerStateFromString(
                  "xyz.openbmc_project.State.Chassis.PowerState.On"),
              PowerState::On);
}

TEST(ChassisPowerStateFromString, InvalidThrows)
{
    EXPECT_THROW(Chassis::convertPowerStateFromString("xyz.invalid"),
                 sdbusplus::exception::InvalidEnumString);
}

// PowerStatus
TEST(ChassisPowerStatusToString, Good)
{
    EXPECT_EQ(Chassis::convertPowerStatusToString(PowerStatus::Good),
              "xyz.openbmc_project.State.Chassis.PowerStatus.Good");
}

TEST(ChassisPowerStatusToString, BrownOut)
{
    EXPECT_EQ(Chassis::convertPowerStatusToString(PowerStatus::BrownOut),
              "xyz.openbmc_project.State.Chassis.PowerStatus.BrownOut");
}

TEST(ChassisPowerStatusToString, UninterruptiblePowerSupply)
{
    EXPECT_EQ(Chassis::convertPowerStatusToString(
                  PowerStatus::UninterruptiblePowerSupply),
              "xyz.openbmc_project.State.Chassis.PowerStatus."
              "UninterruptiblePowerSupply");
}

TEST(ChassisPowerStatusToString, Undefined)
{
    EXPECT_EQ(Chassis::convertPowerStatusToString(PowerStatus::Undefined),
              "xyz.openbmc_project.State.Chassis.PowerStatus.Undefined");
}

TEST(ChassisPowerStatusFromString, Good)
{
    EXPECT_EQ(Chassis::convertPowerStatusFromString(
                  "xyz.openbmc_project.State.Chassis.PowerStatus.Good"),
              PowerStatus::Good);
}

// unpack
static Chassis::properties_t unpackProps(
    const std::map<std::string, Chassis::PropertiesVariant>& m)
{
    Chassis::properties_t r{};
    if (auto it = m.find("RequestedPowerTransition"); it != m.end())
        if (auto* v = std::get_if<ChassisTransition>(&it->second))
            r.requested_power_transition = *v;
    if (auto it = m.find("CurrentPowerState"); it != m.end())
        if (auto* v = std::get_if<PowerState>(&it->second))
            r.current_power_state = *v;
    return r;
}

TEST(ChassisPropertiesUnpack, ValidMap)
{
    std::map<std::string, Chassis::PropertiesVariant> props;
    props["RequestedPowerTransition"] = ChassisTransition::On;
    props["CurrentPowerState"] = PowerState::On;

    Chassis::properties_t result{};
    ASSERT_NO_THROW(result = unpackProps(props));
    EXPECT_EQ(result.requested_power_transition, ChassisTransition::On);
    EXPECT_EQ(result.current_power_state, PowerState::On);
}

// ──────────────────────────────────────────────────────────────────── BMC ────

using BMC = sdbusplus::common::xyz::openbmc_project::state::BMC;
using BMCTransition = BMC::Transition;
using BMCState = BMC::BMCState;
using RebootCause = BMC::RebootCause;

TEST(BMCInterface, InterfaceName)
{
    EXPECT_STREQ(BMC::interface, "xyz.openbmc_project.State.BMC");
}

// BMC Transition
TEST(BMCTransitionToString, Reboot)
{
    EXPECT_EQ(BMC::convertTransitionToString(BMCTransition::Reboot),
              "xyz.openbmc_project.State.BMC.Transition.Reboot");
}

TEST(BMCTransitionToString, HardReboot)
{
    EXPECT_EQ(BMC::convertTransitionToString(BMCTransition::HardReboot),
              "xyz.openbmc_project.State.BMC.Transition.HardReboot");
}

TEST(BMCTransitionToString, None)
{
    EXPECT_EQ(BMC::convertTransitionToString(BMCTransition::None),
              "xyz.openbmc_project.State.BMC.Transition.None");
}

TEST(BMCTransitionFromString, Reboot)
{
    EXPECT_EQ(BMC::convertTransitionFromString(
                  "xyz.openbmc_project.State.BMC.Transition.Reboot"),
              BMCTransition::Reboot);
}

TEST(BMCTransitionFromString, InvalidThrows)
{
    EXPECT_THROW(BMC::convertTransitionFromString("xyz.invalid"),
                 sdbusplus::exception::InvalidEnumString);
}

// BMCState
TEST(BMCStateToString, Ready)
{
    EXPECT_EQ(BMC::convertBMCStateToString(BMCState::Ready),
              "xyz.openbmc_project.State.BMC.BMCState.Ready");
}

TEST(BMCStateToString, NotReady)
{
    EXPECT_EQ(BMC::convertBMCStateToString(BMCState::NotReady),
              "xyz.openbmc_project.State.BMC.BMCState.NotReady");
}

TEST(BMCStateToString, UpdateInProgress)
{
    EXPECT_EQ(BMC::convertBMCStateToString(BMCState::UpdateInProgress),
              "xyz.openbmc_project.State.BMC.BMCState.UpdateInProgress");
}

TEST(BMCStateToString, Quiesced)
{
    EXPECT_EQ(BMC::convertBMCStateToString(BMCState::Quiesced),
              "xyz.openbmc_project.State.BMC.BMCState.Quiesced");
}

TEST(BMCStateFromString, Ready)
{
    EXPECT_EQ(BMC::convertBMCStateFromString(
                  "xyz.openbmc_project.State.BMC.BMCState.Ready"),
              BMCState::Ready);
}

TEST(BMCStateFromString, InvalidThrows)
{
    EXPECT_THROW(BMC::convertBMCStateFromString("xyz.invalid"),
                 sdbusplus::exception::InvalidEnumString);
}

// RebootCause
TEST(BMCRebootCauseToString, POR)
{
    EXPECT_EQ(BMC::convertRebootCauseToString(RebootCause::POR),
              "xyz.openbmc_project.State.BMC.RebootCause.POR");
}

TEST(BMCRebootCauseToString, PinholeReset)
{
    EXPECT_EQ(BMC::convertRebootCauseToString(RebootCause::PinholeReset),
              "xyz.openbmc_project.State.BMC.RebootCause.PinholeReset");
}

TEST(BMCRebootCauseToString, Watchdog)
{
    EXPECT_EQ(BMC::convertRebootCauseToString(RebootCause::Watchdog),
              "xyz.openbmc_project.State.BMC.RebootCause.Watchdog");
}

TEST(BMCRebootCauseToString, Software)
{
    EXPECT_EQ(BMC::convertRebootCauseToString(RebootCause::Software),
              "xyz.openbmc_project.State.BMC.RebootCause.Software");
}

TEST(BMCRebootCauseToString, Unknown)
{
    EXPECT_EQ(BMC::convertRebootCauseToString(RebootCause::Unknown),
              "xyz.openbmc_project.State.BMC.RebootCause.Unknown");
}

TEST(BMCRebootCauseFromString, Software)
{
    EXPECT_EQ(BMC::convertRebootCauseFromString(
                  "xyz.openbmc_project.State.BMC.RebootCause.Software"),
              RebootCause::Software);
}

TEST(BMCRebootCauseFromString, InvalidThrows)
{
    EXPECT_THROW(BMC::convertRebootCauseFromString("xyz.invalid"),
                 sdbusplus::exception::InvalidEnumString);
}

// unpack
static BMC::properties_t unpackProps(
    const std::map<std::string, BMC::PropertiesVariant>& m)
{
    BMC::properties_t r{};
    if (auto it = m.find("RequestedBMCTransition"); it != m.end())
        if (auto* v = std::get_if<BMCTransition>(&it->second))
            r.requested_bmc_transition = *v;
    if (auto it = m.find("CurrentBMCState"); it != m.end())
        if (auto* v = std::get_if<BMCState>(&it->second))
            r.current_bmc_state = *v;
    return r;
}

TEST(BMCPropertiesUnpack, ValidMap)
{
    std::map<std::string, BMC::PropertiesVariant> props;
    props["RequestedBMCTransition"] = BMCTransition::Reboot;
    props["CurrentBMCState"] = BMCState::Ready;

    BMC::properties_t result{};
    ASSERT_NO_THROW(result = unpackProps(props));
    EXPECT_EQ(result.requested_bmc_transition, BMCTransition::Reboot);
    EXPECT_EQ(result.current_bmc_state, BMCState::Ready);
}

} // namespace
