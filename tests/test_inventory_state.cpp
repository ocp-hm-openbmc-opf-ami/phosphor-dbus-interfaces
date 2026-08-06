#include <xyz/openbmc_project/Inventory/Item/PCIeDevice/common.hpp>
#include <xyz/openbmc_project/Inventory/Item/PCIeSlot/common.hpp>
#include <xyz/openbmc_project/Software/ApplyTime/common.hpp>
#include <xyz/openbmc_project/State/Decorator/Health/common.hpp>
#include <xyz/openbmc_project/State/Decorator/PowerState/common.hpp>

#include <gtest/gtest.h>

#include <map>
#include <stdexcept>
#include <string>

namespace {

// ─────────────────────────────────────── State.Decorator.Health (3 enums) ────

using Health =
    sdbusplus::common::xyz::openbmc_project::state::decorator::Health;
using HealthType = Health::HealthType;

TEST(HealthInterface, InterfaceName) {
  EXPECT_STREQ(Health::interface, "xyz.openbmc_project.State.Decorator.Health");
}

TEST(HealthTypeToString, OK) {
  EXPECT_EQ(Health::convertHealthTypeToString(HealthType::OK),
            "xyz.openbmc_project.State.Decorator.Health.HealthType.OK");
}

TEST(HealthTypeToString, Warning) {
  EXPECT_EQ(Health::convertHealthTypeToString(HealthType::Warning),
            "xyz.openbmc_project.State.Decorator.Health.HealthType.Warning");
}

TEST(HealthTypeToString, Critical) {
  EXPECT_EQ(Health::convertHealthTypeToString(HealthType::Critical),
            "xyz.openbmc_project.State.Decorator.Health.HealthType.Critical");
}

TEST(HealthTypeFromString, OK) {
  EXPECT_EQ(Health::convertHealthTypeFromString(
                "xyz.openbmc_project.State.Decorator.Health.HealthType.OK"),
            HealthType::OK);
}

TEST(HealthTypeFromString, InvalidThrows) {
  EXPECT_THROW(Health::convertHealthTypeFromString("xyz.invalid"),
               sdbusplus::exception::InvalidEnumString);
}

TEST(HealthConvertStringTo, ValidReturnsValue) {
  auto r = Health::convertStringToHealthType(
      "xyz.openbmc_project.State.Decorator.Health.HealthType.Critical");
  ASSERT_TRUE(r.has_value());
  EXPECT_EQ(*r, HealthType::Critical);
}

TEST(HealthPropertiesUnpack, ValidMap) {
  std::map<std::string, Health::PropertiesVariant> props;
  props["Health"] = HealthType::OK;

  Health::properties_t result{};
  ASSERT_NO_THROW(result = Health::properties_t::unpack(props));
  EXPECT_EQ(result.health, HealthType::OK);
}

// ───────────────────────────────── State.Decorator.PowerState (5 enums) ─────

using PowerStateDecor =
    sdbusplus::common::xyz::openbmc_project::state::decorator::PowerState;
using PSState = PowerStateDecor::State;

TEST(PowerStateInterface, InterfaceName) {
  EXPECT_STREQ(PowerStateDecor::interface,
               "xyz.openbmc_project.State.Decorator.PowerState");
}

TEST(PowerStateDecorToString, On) {
  EXPECT_EQ(PowerStateDecor::convertStateToString(PSState::On),
            "xyz.openbmc_project.State.Decorator.PowerState.State.On");
}

TEST(PowerStateDecorToString, Off) {
  EXPECT_EQ(PowerStateDecor::convertStateToString(PSState::Off),
            "xyz.openbmc_project.State.Decorator.PowerState.State.Off");
}

TEST(PowerStateDecorToString, PoweringOn) {
  EXPECT_EQ(PowerStateDecor::convertStateToString(PSState::PoweringOn),
            "xyz.openbmc_project.State.Decorator.PowerState.State.PoweringOn");
}

TEST(PowerStateDecorToString, PoweringOff) {
  EXPECT_EQ(PowerStateDecor::convertStateToString(PSState::PoweringOff),
            "xyz.openbmc_project.State.Decorator.PowerState.State.PoweringOff");
}

TEST(PowerStateDecorToString, Unknown) {
  EXPECT_EQ(PowerStateDecor::convertStateToString(PSState::Unknown),
            "xyz.openbmc_project.State.Decorator.PowerState.State.Unknown");
}

TEST(PowerStateDecorFromString, On) {
  EXPECT_EQ(PowerStateDecor::convertStateFromString(
                "xyz.openbmc_project.State.Decorator.PowerState.State.On"),
            PSState::On);
}

TEST(PowerStateDecorFromString, InvalidThrows) {
  EXPECT_THROW(PowerStateDecor::convertStateFromString("xyz.invalid"),
               sdbusplus::exception::InvalidEnumString);
}

TEST(PowerStateDecorPropertiesUnpack, ValidMap) {
  std::map<std::string, PowerStateDecor::PropertiesVariant> props;
  props["PowerState"] = PSState::On;

  PowerStateDecor::properties_t result{};
  ASSERT_NO_THROW(result = PowerStateDecor::properties_t::unpack(props));
  EXPECT_EQ(result.power_state, PSState::On);
}

// ────────────────────────────── Software.ApplyTime (4 enums) ─────────────────

using ApplyTime = sdbusplus::common::xyz::openbmc_project::software::ApplyTime;
using RequestedApplyTimes = ApplyTime::RequestedApplyTimes;

TEST(ApplyTimeInterface, InterfaceName) {
  EXPECT_STREQ(ApplyTime::interface, "xyz.openbmc_project.Software.ApplyTime");
}

TEST(ApplyTimeToString, Immediate) {
  EXPECT_EQ(
      ApplyTime::convertRequestedApplyTimesToString(
          RequestedApplyTimes::Immediate),
      "xyz.openbmc_project.Software.ApplyTime.RequestedApplyTimes.Immediate");
}

TEST(ApplyTimeToString, OnReset) {
  EXPECT_EQ(
      ApplyTime::convertRequestedApplyTimesToString(
          RequestedApplyTimes::OnReset),
      "xyz.openbmc_project.Software.ApplyTime.RequestedApplyTimes.OnReset");
}

TEST(ApplyTimeToString, AtMaintenanceWindowStart) {
  EXPECT_EQ(ApplyTime::convertRequestedApplyTimesToString(
                RequestedApplyTimes::AtMaintenanceWindowStart),
            "xyz.openbmc_project.Software.ApplyTime.RequestedApplyTimes."
            "AtMaintenanceWindowStart");
}

TEST(ApplyTimeToString, InMaintenanceWindowOnReset) {
  EXPECT_EQ(ApplyTime::convertRequestedApplyTimesToString(
                RequestedApplyTimes::InMaintenanceWindowOnReset),
            "xyz.openbmc_project.Software.ApplyTime.RequestedApplyTimes."
            "InMaintenanceWindowOnReset");
}

TEST(ApplyTimeFromString, Immediate) {
  EXPECT_EQ(ApplyTime::convertRequestedApplyTimesFromString(
                "xyz.openbmc_project.Software.ApplyTime.RequestedApplyTimes."
                "Immediate"),
            RequestedApplyTimes::Immediate);
}

TEST(ApplyTimeFromString, InvalidThrows) {
  EXPECT_THROW(ApplyTime::convertRequestedApplyTimesFromString("xyz.invalid"),
               sdbusplus::exception::InvalidEnumString);
}

TEST(ApplyTimePropertiesUnpack, ValidMap) {
  std::map<std::string, ApplyTime::PropertiesVariant> props;
  props["RequestedApplyTime"] = RequestedApplyTimes::OnReset;

  ApplyTime::properties_t result{};
  ASSERT_NO_THROW(result = ApplyTime::properties_t::unpack(props));
  EXPECT_EQ(result.requested_apply_time, RequestedApplyTimes::OnReset);
}

// ──────────────────────────── Inventory.Item.PCIeDevice (2 enums, 7+5) ───────

using PCIeDevice =
    sdbusplus::common::xyz::openbmc_project::inventory::item::PCIeDevice;
using PCIeTypes = PCIeDevice::PCIeTypes;
using DeviceTypes = PCIeDevice::DeviceTypes;

TEST(PCIeDeviceInterface, InterfaceName) {
  EXPECT_STREQ(PCIeDevice::interface,
               "xyz.openbmc_project.Inventory.Item.PCIeDevice");
}

TEST(PCIeTypesToString, Gen1) {
  EXPECT_EQ(PCIeDevice::convertPCIeTypesToString(PCIeTypes::Gen1),
            "xyz.openbmc_project.Inventory.Item.PCIeDevice.PCIeTypes.Gen1");
}

TEST(PCIeTypesToString, Gen3) {
  EXPECT_EQ(PCIeDevice::convertPCIeTypesToString(PCIeTypes::Gen3),
            "xyz.openbmc_project.Inventory.Item.PCIeDevice.PCIeTypes.Gen3");
}

TEST(PCIeTypesToString, Gen5) {
  EXPECT_EQ(PCIeDevice::convertPCIeTypesToString(PCIeTypes::Gen5),
            "xyz.openbmc_project.Inventory.Item.PCIeDevice.PCIeTypes.Gen5");
}

TEST(PCIeTypesToString, Unknown) {
  EXPECT_EQ(PCIeDevice::convertPCIeTypesToString(PCIeTypes::Unknown),
            "xyz.openbmc_project.Inventory.Item.PCIeDevice.PCIeTypes.Unknown");
}

TEST(PCIeTypesFromString, Gen3) {
  EXPECT_EQ(PCIeDevice::convertPCIeTypesFromString(
                "xyz.openbmc_project.Inventory.Item.PCIeDevice.PCIeTypes.Gen3"),
            PCIeTypes::Gen3);
}

TEST(PCIeTypesFromString, InvalidThrows) {
  EXPECT_THROW(PCIeDevice::convertPCIeTypesFromString("xyz.invalid"),
               sdbusplus::exception::InvalidEnumString);
}

TEST(DeviceTypesToString, SingleFunction) {
  EXPECT_EQ(PCIeDevice::convertDeviceTypesToString(DeviceTypes::SingleFunction),
            "xyz.openbmc_project.Inventory.Item.PCIeDevice.DeviceTypes."
            "SingleFunction");
}

TEST(DeviceTypesToString, Unknown) {
  EXPECT_EQ(
      PCIeDevice::convertDeviceTypesToString(DeviceTypes::Unknown),
      "xyz.openbmc_project.Inventory.Item.PCIeDevice.DeviceTypes.Unknown");
}

TEST(DeviceTypesFromString, MultiFunction) {
  EXPECT_EQ(PCIeDevice::convertDeviceTypesFromString(
                "xyz.openbmc_project.Inventory.Item.PCIeDevice.DeviceTypes."
                "MultiFunction"),
            DeviceTypes::MultiFunction);
}

TEST(DeviceTypesFromString, InvalidThrows) {
  EXPECT_THROW(PCIeDevice::convertDeviceTypesFromString("xyz.invalid"),
               sdbusplus::exception::InvalidEnumString);
}

// ────────────────────────── Inventory.Item.PCIeSlot (7 Gen + 11 SlotTypes) ──

using PCIeSlot =
    sdbusplus::common::xyz::openbmc_project::inventory::item::PCIeSlot;
using Generations = PCIeSlot::Generations;
using SlotTypes = PCIeSlot::SlotTypes;

TEST(PCIeSlotInterface, InterfaceName) {
  EXPECT_STREQ(PCIeSlot::interface,
               "xyz.openbmc_project.Inventory.Item.PCIeSlot");
}

TEST(PCIeSlotGenerationsToString, Gen1) {
  EXPECT_EQ(PCIeSlot::convertGenerationsToString(Generations::Gen1),
            "xyz.openbmc_project.Inventory.Item.PCIeSlot.Generations.Gen1");
}

TEST(PCIeSlotGenerationsToString, Gen4) {
  EXPECT_EQ(PCIeSlot::convertGenerationsToString(Generations::Gen4),
            "xyz.openbmc_project.Inventory.Item.PCIeSlot.Generations.Gen4");
}

TEST(PCIeSlotGenerationsToString, Unknown) {
  EXPECT_EQ(PCIeSlot::convertGenerationsToString(Generations::Unknown),
            "xyz.openbmc_project.Inventory.Item.PCIeSlot.Generations.Unknown");
}

TEST(PCIeSlotGenerationsFromString, Gen4) {
  EXPECT_EQ(PCIeSlot::convertGenerationsFromString(
                "xyz.openbmc_project.Inventory.Item.PCIeSlot.Generations.Gen4"),
            Generations::Gen4);
}

TEST(PCIeSlotGenerationsFromString, InvalidThrows) {
  EXPECT_THROW(PCIeSlot::convertGenerationsFromString("xyz.invalid"),
               sdbusplus::exception::InvalidEnumString);
}

TEST(PCIeSlotTypesToString, FullLength) {
  EXPECT_EQ(PCIeSlot::convertSlotTypesToString(SlotTypes::FullLength),
            "xyz.openbmc_project.Inventory.Item.PCIeSlot.SlotTypes.FullLength");
}

TEST(PCIeSlotTypesToString, M_2) {
  EXPECT_EQ(PCIeSlot::convertSlotTypesToString(SlotTypes::M_2),
            "xyz.openbmc_project.Inventory.Item.PCIeSlot.SlotTypes.M_2");
}

TEST(PCIeSlotTypesToString, Unknown) {
  EXPECT_EQ(PCIeSlot::convertSlotTypesToString(SlotTypes::Unknown),
            "xyz.openbmc_project.Inventory.Item.PCIeSlot.SlotTypes.Unknown");
}

TEST(PCIeSlotTypesFromString, FullLength) {
  EXPECT_EQ(
      PCIeSlot::convertSlotTypesFromString(
          "xyz.openbmc_project.Inventory.Item.PCIeSlot.SlotTypes.FullLength"),
      SlotTypes::FullLength);
}

TEST(PCIeSlotTypesFromString, InvalidThrows) {
  EXPECT_THROW(PCIeSlot::convertSlotTypesFromString("xyz.invalid"),
               sdbusplus::exception::InvalidEnumString);
}

} // namespace
