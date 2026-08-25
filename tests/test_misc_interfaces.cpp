#include <xyz/openbmc_project/Control/Power/RestorePolicy/common.hpp>
#include <xyz/openbmc_project/Software/Version/common.hpp>
#include <xyz/openbmc_project/State/Decorator/OperationalStatus/common.hpp>

#include <gtest/gtest.h>

#include <map>
#include <stdexcept>
#include <string>

namespace {

// ───────────────────────────────────────────── Software.Version (7 enums) ────

using Version = sdbusplus::common::xyz::openbmc_project::software::Version;
using VersionPurpose = Version::VersionPurpose;

TEST(SoftwareVersionInterface, InterfaceName) {
  EXPECT_STREQ(Version::interface, "xyz.openbmc_project.Software.Version");
}

TEST(VersionPurposeToString, Unknown) {
  EXPECT_EQ(Version::convertVersionPurposeToString(VersionPurpose::Unknown),
            "xyz.openbmc_project.Software.Version.VersionPurpose.Unknown");
}

TEST(VersionPurposeToString, Other) {
  EXPECT_EQ(Version::convertVersionPurposeToString(VersionPurpose::Other),
            "xyz.openbmc_project.Software.Version.VersionPurpose.Other");
}

TEST(VersionPurposeToString, System) {
  EXPECT_EQ(Version::convertVersionPurposeToString(VersionPurpose::System),
            "xyz.openbmc_project.Software.Version.VersionPurpose.System");
}

TEST(VersionPurposeToString, BMC) {
  EXPECT_EQ(Version::convertVersionPurposeToString(VersionPurpose::BMC),
            "xyz.openbmc_project.Software.Version.VersionPurpose.BMC");
}

TEST(VersionPurposeToString, Host) {
  EXPECT_EQ(Version::convertVersionPurposeToString(VersionPurpose::Host),
            "xyz.openbmc_project.Software.Version.VersionPurpose.Host");
}

TEST(VersionPurposeToString, PSU) {
  EXPECT_EQ(Version::convertVersionPurposeToString(VersionPurpose::PSU),
            "xyz.openbmc_project.Software.Version.VersionPurpose.PSU");
}

TEST(VersionPurposeToString, PLDM) {
  EXPECT_EQ(Version::convertVersionPurposeToString(VersionPurpose::PLDM),
            "xyz.openbmc_project.Software.Version.VersionPurpose.PLDM");
}

TEST(VersionPurposeFromString, BMC) {
  EXPECT_EQ(Version::convertVersionPurposeFromString(
                "xyz.openbmc_project.Software.Version.VersionPurpose.BMC"),
            VersionPurpose::BMC);
}

TEST(VersionPurposeFromString, InvalidThrows) {
  EXPECT_THROW(Version::convertVersionPurposeFromString("xyz.invalid"),
               sdbusplus::exception::InvalidEnumString);
}

TEST(VersionPurposeConvertStringTo, ValidReturnsValue) {
  auto r = Version::convertStringToVersionPurpose(
      "xyz.openbmc_project.Software.Version.VersionPurpose.Host");
  ASSERT_TRUE(r.has_value());
  EXPECT_EQ(*r, VersionPurpose::Host);
}

TEST(VersionPurposeConvertStringTo, InvalidReturnsNullopt) {
  EXPECT_FALSE(
      Version::convertStringToVersionPurpose("xyz.invalid").has_value());
}

TEST(SoftwareVersionPropertiesUnpack, ValidMap) {
  std::map<std::string, Version::PropertiesVariant> props;
  props["Version"] = std::string("v1.0.0");
  props["Purpose"] = VersionPurpose::BMC;

  Version::properties_t result{};
  ASSERT_NO_THROW(result = Version::properties_t::unpack(props));
  EXPECT_EQ(result.version, "v1.0.0");
  EXPECT_EQ(result.purpose, VersionPurpose::BMC);
}

// ─────────────────────────────────────── Control.Power.RestorePolicy (4) ────

using RestorePolicy =
    sdbusplus::common::xyz::openbmc_project::control::power::RestorePolicy;
using Policy = RestorePolicy::Policy;

TEST(RestorePolicyInterface, InterfaceName) {
  EXPECT_STREQ(RestorePolicy::interface,
               "xyz.openbmc_project.Control.Power.RestorePolicy");
}

TEST(RestorePolicyToString, None) {
  EXPECT_EQ(RestorePolicy::convertPolicyToString(Policy::None),
            "xyz.openbmc_project.Control.Power.RestorePolicy.Policy.None");
}

TEST(RestorePolicyToString, AlwaysOn) {
  EXPECT_EQ(RestorePolicy::convertPolicyToString(Policy::AlwaysOn),
            "xyz.openbmc_project.Control.Power.RestorePolicy.Policy.AlwaysOn");
}

TEST(RestorePolicyToString, AlwaysOff) {
  EXPECT_EQ(RestorePolicy::convertPolicyToString(Policy::AlwaysOff),
            "xyz.openbmc_project.Control.Power.RestorePolicy.Policy.AlwaysOff");
}

TEST(RestorePolicyToString, Restore) {
  EXPECT_EQ(RestorePolicy::convertPolicyToString(Policy::Restore),
            "xyz.openbmc_project.Control.Power.RestorePolicy.Policy.Restore");
}

TEST(RestorePolicyFromString, AlwaysOn) {
  EXPECT_EQ(
      RestorePolicy::convertPolicyFromString(
          "xyz.openbmc_project.Control.Power.RestorePolicy.Policy.AlwaysOn"),
      Policy::AlwaysOn);
}

TEST(RestorePolicyFromString, InvalidThrows) {
  EXPECT_THROW(RestorePolicy::convertPolicyFromString("xyz.invalid"),
               sdbusplus::exception::InvalidEnumString);
}

TEST(RestorePolicyPropertiesUnpack, ValidMap) {
  std::map<std::string, RestorePolicy::PropertiesVariant> props;
  props["PowerRestorePolicy"] = Policy::AlwaysOn;
  props["PowerRestoreDelay"] = static_cast<uint64_t>(10);

  RestorePolicy::properties_t result{};
  ASSERT_NO_THROW(result = RestorePolicy::properties_t::unpack(props));
  EXPECT_EQ(result.power_restore_policy, Policy::AlwaysOn);
  EXPECT_EQ(result.power_restore_delay, 10u);
}

// ──────────────────────────── State.Decorator.OperationalStatus (10 enums) ──

using OpStatus = sdbusplus::common::xyz::openbmc_project::state::decorator::
    OperationalStatus;
using StateType = OpStatus::StateType;

TEST(OperationalStatusInterface, InterfaceName) {
  EXPECT_STREQ(OpStatus::interface,
               "xyz.openbmc_project.State.Decorator.OperationalStatus");
}

TEST(StateTypeToString, None) {
  EXPECT_EQ(
      OpStatus::convertStateTypeToString(StateType::None),
      "xyz.openbmc_project.State.Decorator.OperationalStatus.StateType.None");
}

TEST(StateTypeToString, Absent) {
  EXPECT_EQ(
      OpStatus::convertStateTypeToString(StateType::Absent),
      "xyz.openbmc_project.State.Decorator.OperationalStatus.StateType.Absent");
}

TEST(StateTypeToString, Deferring) {
  EXPECT_EQ(OpStatus::convertStateTypeToString(StateType::Deferring),
            "xyz.openbmc_project.State.Decorator.OperationalStatus.StateType."
            "Deferring");
}

TEST(StateTypeToString, Disabled) {
  EXPECT_EQ(OpStatus::convertStateTypeToString(StateType::Disabled),
            "xyz.openbmc_project.State.Decorator.OperationalStatus.StateType."
            "Disabled");
}

TEST(StateTypeToString, Enabled) {
  EXPECT_EQ(OpStatus::convertStateTypeToString(StateType::Enabled),
            "xyz.openbmc_project.State.Decorator.OperationalStatus.StateType."
            "Enabled");
}

TEST(StateTypeToString, StandbyOffline) {
  EXPECT_EQ(OpStatus::convertStateTypeToString(StateType::StandbyOffline),
            "xyz.openbmc_project.State.Decorator.OperationalStatus.StateType."
            "StandbyOffline");
}

TEST(StateTypeToString, Starting) {
  EXPECT_EQ(OpStatus::convertStateTypeToString(StateType::Starting),
            "xyz.openbmc_project.State.Decorator.OperationalStatus.StateType."
            "Starting");
}

TEST(StateTypeToString, UnavailableOffline) {
  EXPECT_EQ(OpStatus::convertStateTypeToString(StateType::UnavailableOffline),
            "xyz.openbmc_project.State.Decorator.OperationalStatus.StateType."
            "UnavailableOffline");
}

TEST(StateTypeToString, Updating) {
  EXPECT_EQ(OpStatus::convertStateTypeToString(StateType::Updating),
            "xyz.openbmc_project.State.Decorator.OperationalStatus.StateType."
            "Updating");
}

TEST(StateTypeToString, Fault) {
  EXPECT_EQ(
      OpStatus::convertStateTypeToString(StateType::Fault),
      "xyz.openbmc_project.State.Decorator.OperationalStatus.StateType.Fault");
}

TEST(StateTypeFromString, Enabled) {
  EXPECT_EQ(OpStatus::convertStateTypeFromString(
                "xyz.openbmc_project.State.Decorator.OperationalStatus."
                "StateType.Enabled"),
            StateType::Enabled);
}

TEST(StateTypeFromString, InvalidThrows) {
  EXPECT_THROW(OpStatus::convertStateTypeFromString("xyz.invalid"),
               sdbusplus::exception::InvalidEnumString);
}

TEST(OpStatusPropertiesUnpack, ValidMap) {
  std::map<std::string, OpStatus::PropertiesVariant> props;
  props["Functional"] = true;
  props["State"] = StateType::Enabled;

  OpStatus::properties_t result{};
  ASSERT_NO_THROW(result = OpStatus::properties_t::unpack(props));
  EXPECT_TRUE(result.functional);
  EXPECT_EQ(result.state, StateType::Enabled);
}

} // namespace
