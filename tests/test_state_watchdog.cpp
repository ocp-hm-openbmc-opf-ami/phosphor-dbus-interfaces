// Edge-case tests for xyz.openbmc_project.State.Watchdog
// Covers Action, PreTimeoutInterruptAction, and TimerUse enums.
#include <xyz/openbmc_project/State/Watchdog/common.hpp>

#include <map>
#include <stdexcept>
#include <string>

#include <gtest/gtest.h>

namespace
{

using Watchdog = sdbusplus::common::xyz::openbmc_project::state::Watchdog;
using Action = Watchdog::Action;
using PreTimeoutInterruptAction = Watchdog::PreTimeoutInterruptAction;
using TimerUse = Watchdog::TimerUse;

// ── Interface name
// ────────────────────────────────────────────────────────────

TEST(WatchdogInterface, InterfaceName)
{
    EXPECT_STREQ(Watchdog::interface, "xyz.openbmc_project.State.Watchdog");
}

// ── Property name constants
// ───────────────────────────────────────────────────

TEST(WatchdogPropertyNames, Enabled)
{
    EXPECT_STREQ(Watchdog::property_names::enabled, "Enabled");
}

TEST(WatchdogPropertyNames, Interval)
{
    EXPECT_STREQ(Watchdog::property_names::interval, "Interval");
}

TEST(WatchdogPropertyNames, TimeRemaining)
{
    EXPECT_STREQ(Watchdog::property_names::time_remaining, "TimeRemaining");
}

TEST(WatchdogPropertyNames, ExpireAction)
{
    EXPECT_STREQ(Watchdog::property_names::expire_action, "ExpireAction");
}

// ── Action enum → string (all 4 values) ──────────────────────────────────────

TEST(WatchdogActionToString, None)
{
    EXPECT_EQ(Watchdog::convertActionToString(Action::None),
              "xyz.openbmc_project.State.Watchdog.Action.None");
}

TEST(WatchdogActionToString, HardReset)
{
    EXPECT_EQ(Watchdog::convertActionToString(Action::HardReset),
              "xyz.openbmc_project.State.Watchdog.Action.HardReset");
}

TEST(WatchdogActionToString, PowerOff)
{
    EXPECT_EQ(Watchdog::convertActionToString(Action::PowerOff),
              "xyz.openbmc_project.State.Watchdog.Action.PowerOff");
}

TEST(WatchdogActionToString, PowerCycle)
{
    EXPECT_EQ(Watchdog::convertActionToString(Action::PowerCycle),
              "xyz.openbmc_project.State.Watchdog.Action.PowerCycle");
}

// ── Action string → enum
// ──────────────────────────────────────────────────────

TEST(WatchdogActionFromString, HardReset)
{
    EXPECT_EQ(Watchdog::convertActionFromString(
                  "xyz.openbmc_project.State.Watchdog.Action.HardReset"),
              Action::HardReset);
}

TEST(WatchdogActionFromString, PowerCycle)
{
    EXPECT_EQ(Watchdog::convertActionFromString(
                  "xyz.openbmc_project.State.Watchdog.Action.PowerCycle"),
              Action::PowerCycle);
}

TEST(WatchdogActionFromString, None)
{
    EXPECT_EQ(Watchdog::convertActionFromString(
                  "xyz.openbmc_project.State.Watchdog.Action.None"),
              Action::None);
}

TEST(WatchdogActionFromString, InvalidStringThrows)
{
    EXPECT_THROW(Watchdog::convertActionFromString("xyz.invalid"),
                 sdbusplus::exception::InvalidEnumString);
}

TEST(WatchdogActionFromString, EmptyStringThrows)
{
    EXPECT_THROW(Watchdog::convertActionFromString(""),
                 sdbusplus::exception::InvalidEnumString);
}

TEST(WatchdogActionFromString, PartialPrefixThrows)
{
    EXPECT_THROW(Watchdog::convertActionFromString(
                     "xyz.openbmc_project.State.Watchdog.Action"),
                 sdbusplus::exception::InvalidEnumString);
}

// ── convertStringToAction (optional variant)
// ──────────────────────────────────

TEST(WatchdogActionConvertStringTo, ValidReturnsValue)
{
    auto r = Watchdog::convertStringToAction(
        "xyz.openbmc_project.State.Watchdog.Action.PowerOff");
    ASSERT_TRUE(r.has_value());
    EXPECT_EQ(*r, Action::PowerOff);
}

TEST(WatchdogActionConvertStringTo, InvalidReturnsNullopt)
{
    EXPECT_FALSE(Watchdog::convertStringToAction("xyz.bad").has_value());
}

TEST(WatchdogActionConvertStringTo, EmptyStringReturnsNullopt)
{
    EXPECT_FALSE(Watchdog::convertStringToAction("").has_value());
}

// ── PreTimeoutInterruptAction enum → string (all 4 values) ───────────────────

TEST(WatchdogPreTimeoutToString, None)
{
    EXPECT_EQ(Watchdog::convertPreTimeoutInterruptActionToString(
                  PreTimeoutInterruptAction::None),
              "xyz.openbmc_project.State.Watchdog.PreTimeoutInterruptAction"
              ".None");
}

TEST(WatchdogPreTimeoutToString, SMI)
{
    EXPECT_EQ(Watchdog::convertPreTimeoutInterruptActionToString(
                  PreTimeoutInterruptAction::SMI),
              "xyz.openbmc_project.State.Watchdog.PreTimeoutInterruptAction"
              ".SMI");
}

TEST(WatchdogPreTimeoutToString, NMI)
{
    EXPECT_EQ(Watchdog::convertPreTimeoutInterruptActionToString(
                  PreTimeoutInterruptAction::NMI),
              "xyz.openbmc_project.State.Watchdog.PreTimeoutInterruptAction"
              ".NMI");
}

TEST(WatchdogPreTimeoutToString, MI)
{
    EXPECT_EQ(Watchdog::convertPreTimeoutInterruptActionToString(
                  PreTimeoutInterruptAction::MI),
              "xyz.openbmc_project.State.Watchdog.PreTimeoutInterruptAction"
              ".MI");
}

// ── PreTimeoutInterruptAction string → enum
// ───────────────────────────────────

TEST(WatchdogPreTimeoutFromString, NMI)
{
    EXPECT_EQ(
        Watchdog::convertPreTimeoutInterruptActionFromString(
            "xyz.openbmc_project.State.Watchdog.PreTimeoutInterruptAction.NMI"),
        PreTimeoutInterruptAction::NMI);
}

TEST(WatchdogPreTimeoutFromString, InvalidStringThrows)
{
    EXPECT_THROW(
        Watchdog::convertPreTimeoutInterruptActionFromString("xyz.invalid"),
        sdbusplus::exception::InvalidEnumString);
}

TEST(WatchdogPreTimeoutFromString, EmptyStringThrows)
{
    EXPECT_THROW(Watchdog::convertPreTimeoutInterruptActionFromString(""),
                 sdbusplus::exception::InvalidEnumString);
}

// ── convertStringToPreTimeoutInterruptAction (optional variant)
// ───────────────

TEST(WatchdogPreTimeoutConvertStringTo, ValidReturnsValue)
{
    auto r = Watchdog::convertStringToPreTimeoutInterruptAction(
        "xyz.openbmc_project.State.Watchdog.PreTimeoutInterruptAction.SMI");
    ASSERT_TRUE(r.has_value());
    EXPECT_EQ(*r, PreTimeoutInterruptAction::SMI);
}

TEST(WatchdogPreTimeoutConvertStringTo, InvalidReturnsNullopt)
{
    EXPECT_FALSE(Watchdog::convertStringToPreTimeoutInterruptAction("xyz.bad")
                     .has_value());
}

// ── TimerUse enum → string (all 6 values) ────────────────────────────────────

TEST(WatchdogTimerUseToString, Reserved)
{
    EXPECT_EQ(Watchdog::convertTimerUseToString(TimerUse::Reserved),
              "xyz.openbmc_project.State.Watchdog.TimerUse.Reserved");
}

TEST(WatchdogTimerUseToString, BIOSFRB2)
{
    EXPECT_EQ(Watchdog::convertTimerUseToString(TimerUse::BIOSFRB2),
              "xyz.openbmc_project.State.Watchdog.TimerUse.BIOSFRB2");
}

TEST(WatchdogTimerUseToString, BIOSPOST)
{
    EXPECT_EQ(Watchdog::convertTimerUseToString(TimerUse::BIOSPOST),
              "xyz.openbmc_project.State.Watchdog.TimerUse.BIOSPOST");
}

TEST(WatchdogTimerUseToString, OSLoad)
{
    EXPECT_EQ(Watchdog::convertTimerUseToString(TimerUse::OSLoad),
              "xyz.openbmc_project.State.Watchdog.TimerUse.OSLoad");
}

TEST(WatchdogTimerUseToString, SMSOS)
{
    EXPECT_EQ(Watchdog::convertTimerUseToString(TimerUse::SMSOS),
              "xyz.openbmc_project.State.Watchdog.TimerUse.SMSOS");
}

TEST(WatchdogTimerUseToString, OEM)
{
    EXPECT_EQ(Watchdog::convertTimerUseToString(TimerUse::OEM),
              "xyz.openbmc_project.State.Watchdog.TimerUse.OEM");
}

// ── TimerUse string → enum
// ────────────────────────────────────────────────────

TEST(WatchdogTimerUseFromString, OSLoad)
{
    EXPECT_EQ(Watchdog::convertTimerUseFromString(
                  "xyz.openbmc_project.State.Watchdog.TimerUse.OSLoad"),
              TimerUse::OSLoad);
}

TEST(WatchdogTimerUseFromString, OEM)
{
    EXPECT_EQ(Watchdog::convertTimerUseFromString(
                  "xyz.openbmc_project.State.Watchdog.TimerUse.OEM"),
              TimerUse::OEM);
}

TEST(WatchdogTimerUseFromString, InvalidStringThrows)
{
    EXPECT_THROW(Watchdog::convertTimerUseFromString("xyz.invalid"),
                 sdbusplus::exception::InvalidEnumString);
}

TEST(WatchdogTimerUseFromString, EmptyStringThrows)
{
    EXPECT_THROW(Watchdog::convertTimerUseFromString(""),
                 sdbusplus::exception::InvalidEnumString);
}

// ── convertStringToTimerUse (optional variant)
// ────────────────────────────────

TEST(WatchdogTimerUseConvertStringTo, ValidReturnsValue)
{
    auto r = Watchdog::convertStringToTimerUse(
        "xyz.openbmc_project.State.Watchdog.TimerUse.BIOSPOST");
    ASSERT_TRUE(r.has_value());
    EXPECT_EQ(*r, TimerUse::BIOSPOST);
}

TEST(WatchdogTimerUseConvertStringTo, InvalidReturnsNullopt)
{
    EXPECT_FALSE(Watchdog::convertStringToTimerUse("xyz.bad").has_value());
}

// ── Properties unpack
// ─────────────────────────────────────────────────────────

static Watchdog::properties_t unpackProps(
    const std::map<std::string, Watchdog::PropertiesVariant>& m)
{
    Watchdog::properties_t r{};
    if (auto it = m.find("Enabled"); it != m.end())
        if (auto* v = std::get_if<bool>(&it->second))
            r.enabled = *v;
    if (auto it = m.find("Interval"); it != m.end())
        if (auto* v = std::get_if<uint64_t>(&it->second))
            r.interval = *v;
    if (auto it = m.find("ExpireAction"); it != m.end())
        if (auto* v = std::get_if<Action>(&it->second))
            r.expire_action = *v;
    if (auto it = m.find("CurrentTimerUse"); it != m.end())
        if (auto* v = std::get_if<TimerUse>(&it->second))
            r.current_timer_use = *v;
    return r;
}

TEST(WatchdogPropertiesUnpack, ValidMap)
{
    std::map<std::string, Watchdog::PropertiesVariant> props;
    props["Enabled"] = true;
    props["Interval"] = static_cast<uint64_t>(30000);
    props["ExpireAction"] = Action::PowerCycle;
    props["CurrentTimerUse"] = TimerUse::OSLoad;

    Watchdog::properties_t result{};
    ASSERT_NO_THROW(result = unpackProps(props));
    EXPECT_TRUE(result.enabled);
    EXPECT_EQ(result.interval, 30000u);
    EXPECT_EQ(result.expire_action, Action::PowerCycle);
    EXPECT_EQ(result.current_timer_use, TimerUse::OSLoad);
}

TEST(WatchdogPropertiesUnpack, EmptyMapYieldsDefaults)
{
    std::map<std::string, Watchdog::PropertiesVariant> props;
    Watchdog::properties_t result{};
    ASSERT_NO_THROW(result = unpackProps(props));
    EXPECT_FALSE(result.enabled);
    // Default interval from properties_t is 600000
    EXPECT_EQ(result.interval, 600000u);
}

TEST(WatchdogPropertiesUnpack, WrongVariantTypeForActionIsIgnored)
{
    std::map<std::string, Watchdog::PropertiesVariant> props;
    // uint64_t is in the variant but is not the Action type
    props["ExpireAction"] = static_cast<uint64_t>(999);

    Watchdog::properties_t result{};
    ASSERT_NO_THROW(result = unpackProps(props));
    // expire_action stays at default (HardReset per properties_t initialiser)
    EXPECT_EQ(result.expire_action, Action::HardReset);
}

TEST(WatchdogPropertiesUnpack, IntervalZeroIsValid)
{
    std::map<std::string, Watchdog::PropertiesVariant> props;
    props["Interval"] = static_cast<uint64_t>(0);

    Watchdog::properties_t result{};
    ASSERT_NO_THROW(result = unpackProps(props));
    EXPECT_EQ(result.interval, 0u);
}

TEST(WatchdogPropertiesUnpack, MaxIntervalIsAccepted)
{
    std::map<std::string, Watchdog::PropertiesVariant> props;
    props["Interval"] = std::numeric_limits<uint64_t>::max();

    Watchdog::properties_t result{};
    ASSERT_NO_THROW(result = unpackProps(props));
    EXPECT_EQ(result.interval, std::numeric_limits<uint64_t>::max());
}

} // namespace
