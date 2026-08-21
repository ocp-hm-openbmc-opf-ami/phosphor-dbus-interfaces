#include <xyz/openbmc_project/Control/Boot/Mode/common.hpp>
#include <xyz/openbmc_project/Control/Boot/Source/common.hpp>
#include <xyz/openbmc_project/Control/Boot/Type/common.hpp>

#include <gtest/gtest.h>

#include <map>
#include <stdexcept>
#include <string>

namespace {

// ──────────────────────────────────────────────────────────────── Boot.Mode ──

using Mode = sdbusplus::common::xyz::openbmc_project::control::boot::Mode;
using Modes = Mode::Modes;

TEST(BootModeInterface, InterfaceName) {
  EXPECT_STREQ(Mode::interface, "xyz.openbmc_project.Control.Boot.Mode");
}

TEST(BootModeToString, Regular) {
  EXPECT_EQ(Mode::convertModesToString(Modes::Regular),
            "xyz.openbmc_project.Control.Boot.Mode.Modes.Regular");
}

TEST(BootModeToString, Safe) {
  EXPECT_EQ(Mode::convertModesToString(Modes::Safe),
            "xyz.openbmc_project.Control.Boot.Mode.Modes.Safe");
}

TEST(BootModeToString, Diag) {
  EXPECT_EQ(Mode::convertModesToString(Modes::Diag),
            "xyz.openbmc_project.Control.Boot.Mode.Modes.Diag");
}

TEST(BootModeToString, Setup) {
  EXPECT_EQ(Mode::convertModesToString(Modes::Setup),
            "xyz.openbmc_project.Control.Boot.Mode.Modes.Setup");
}

TEST(BootModeFromString, Regular) {
  EXPECT_EQ(Mode::convertModesFromString(
                "xyz.openbmc_project.Control.Boot.Mode.Modes.Regular"),
            Modes::Regular);
}

TEST(BootModeFromString, InvalidThrows) {
  EXPECT_THROW(Mode::convertModesFromString("xyz.invalid"),
               sdbusplus::exception::InvalidEnumString);
}

TEST(BootModeConvertStringTo, ValidReturnsValue) {
  auto r = Mode::convertStringToModes(
      "xyz.openbmc_project.Control.Boot.Mode.Modes.Safe");
  ASSERT_TRUE(r.has_value());
  EXPECT_EQ(*r, Modes::Safe);
}

TEST(BootModeConvertStringTo, InvalidReturnsNullopt) {
  EXPECT_FALSE(Mode::convertStringToModes("xyz.invalid").has_value());
}

TEST(BootModePropertyNames, BootMode) {
  EXPECT_STREQ(Mode::property_names::boot_mode, "BootMode");
}

TEST(BootModePropertiesUnpack, ValidMap) {
  std::map<std::string, Mode::PropertiesVariant> props;
  props["BootMode"] = Modes::Safe;

  Mode::properties_t result{};
  ASSERT_NO_THROW(result = Mode::properties_t::unpack(props));
  EXPECT_EQ(result.boot_mode, Modes::Safe);
}

// ────────────────────────────────────────────────────────────── Boot.Source ──

using Source = sdbusplus::common::xyz::openbmc_project::control::boot::Source;
using Sources = Source::Sources;

TEST(BootSourceInterface, InterfaceName) {
  EXPECT_STREQ(Source::interface, "xyz.openbmc_project.Control.Boot.Source");
}

TEST(BootSourceToString, Disk) {
  EXPECT_EQ(Source::convertSourcesToString(Sources::Disk),
            "xyz.openbmc_project.Control.Boot.Source.Sources.Disk");
}

TEST(BootSourceToString, ExternalMedia) {
  EXPECT_EQ(Source::convertSourcesToString(Sources::ExternalMedia),
            "xyz.openbmc_project.Control.Boot.Source.Sources.ExternalMedia");
}

TEST(BootSourceToString, Network) {
  EXPECT_EQ(Source::convertSourcesToString(Sources::Network),
            "xyz.openbmc_project.Control.Boot.Source.Sources.Network");
}

TEST(BootSourceToString, Default) {
  EXPECT_EQ(Source::convertSourcesToString(Sources::Default),
            "xyz.openbmc_project.Control.Boot.Source.Sources.Default");
}

TEST(BootSourceToString, RemovableMedia) {
  EXPECT_EQ(Source::convertSourcesToString(Sources::RemovableMedia),
            "xyz.openbmc_project.Control.Boot.Source.Sources.RemovableMedia");
}

TEST(BootSourceToString, HTTP) {
  EXPECT_EQ(Source::convertSourcesToString(Sources::HTTP),
            "xyz.openbmc_project.Control.Boot.Source.Sources.HTTP");
}

TEST(BootSourceFromString, Network) {
  EXPECT_EQ(Source::convertSourcesFromString(
                "xyz.openbmc_project.Control.Boot.Source.Sources.Network"),
            Sources::Network);
}

TEST(BootSourceFromString, InvalidThrows) {
  EXPECT_THROW(Source::convertSourcesFromString("xyz.invalid"),
               sdbusplus::exception::InvalidEnumString);
}

TEST(BootSourcePropertyNames, BootSource) {
  EXPECT_STREQ(Source::property_names::boot_source, "BootSource");
}

TEST(BootSourcePropertiesUnpack, ValidMap) {
  std::map<std::string, Source::PropertiesVariant> props;
  props["BootSource"] = Sources::Network;

  Source::properties_t result{};
  ASSERT_NO_THROW(result = Source::properties_t::unpack(props));
  EXPECT_EQ(result.boot_source, Sources::Network);
}

// ──────────────────────────────────────────────────────────────── Boot.Type ──

using Type = sdbusplus::common::xyz::openbmc_project::control::boot::Type;
using Types = Type::Types;

TEST(BootTypeInterface, InterfaceName) {
  EXPECT_STREQ(Type::interface, "xyz.openbmc_project.Control.Boot.Type");
}

TEST(BootTypeToString, Legacy) {
  EXPECT_EQ(Type::convertTypesToString(Types::Legacy),
            "xyz.openbmc_project.Control.Boot.Type.Types.Legacy");
}

TEST(BootTypeToString, EFI) {
  EXPECT_EQ(Type::convertTypesToString(Types::EFI),
            "xyz.openbmc_project.Control.Boot.Type.Types.EFI");
}

TEST(BootTypeFromString, EFI) {
  EXPECT_EQ(Type::convertTypesFromString(
                "xyz.openbmc_project.Control.Boot.Type.Types.EFI"),
            Types::EFI);
}

TEST(BootTypeFromString, InvalidThrows) {
  EXPECT_THROW(Type::convertTypesFromString("xyz.invalid"),
               sdbusplus::exception::InvalidEnumString);
}

TEST(BootTypePropertyNames, BootType) {
  EXPECT_STREQ(Type::property_names::boot_type, "BootType");
}

TEST(BootTypePropertiesUnpack, ValidMap) {
  std::map<std::string, Type::PropertiesVariant> props;
  props["BootType"] = Types::Legacy;

  Type::properties_t result{};
  ASSERT_NO_THROW(result = Type::properties_t::unpack(props));
  EXPECT_EQ(result.boot_type, Types::Legacy);
}

} // namespace
