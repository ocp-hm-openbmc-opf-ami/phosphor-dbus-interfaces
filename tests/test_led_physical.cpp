#include <xyz/openbmc_project/Led/Physical/common.hpp>

#include <gtest/gtest.h>

#include <map>
#include <stdexcept>
#include <string>

namespace {

using Physical = sdbusplus::common::xyz::openbmc_project::led::Physical;
using Action = Physical::Action;
using Palette = Physical::Palette;

// ── Interface name
// ────────────────────────────────────────────────────────────

TEST(LedPhysicalInterface, InterfaceName) {
  EXPECT_STREQ(Physical::interface, "xyz.openbmc_project.Led.Physical");
}

// ── Action enum → string
// ──────────────────────────────────────────────────────

TEST(LedActionToString, Off) {
  EXPECT_EQ(Physical::convertActionToString(Action::Off),
            "xyz.openbmc_project.Led.Physical.Action.Off");
}

TEST(LedActionToString, On) {
  EXPECT_EQ(Physical::convertActionToString(Action::On),
            "xyz.openbmc_project.Led.Physical.Action.On");
}

TEST(LedActionToString, Blink) {
  EXPECT_EQ(Physical::convertActionToString(Action::Blink),
            "xyz.openbmc_project.Led.Physical.Action.Blink");
}

// ── Action string → enum
// ──────────────────────────────────────────────────────

TEST(LedActionFromString, On) {
  EXPECT_EQ(Physical::convertActionFromString(
                "xyz.openbmc_project.Led.Physical.Action.On"),
            Action::On);
}

TEST(LedActionFromString, Blink) {
  EXPECT_EQ(Physical::convertActionFromString(
                "xyz.openbmc_project.Led.Physical.Action.Blink"),
            Action::Blink);
}

TEST(LedActionFromString, Off) {
  EXPECT_EQ(Physical::convertActionFromString(
                "xyz.openbmc_project.Led.Physical.Action.Off"),
            Action::Off);
}

TEST(LedActionFromString, InvalidThrows) {
  EXPECT_THROW(Physical::convertActionFromString("xyz.invalid"),
               sdbusplus::exception::InvalidEnumString);
}

TEST(LedActionConvertStringTo, ValidReturnsValue) {
  auto r = Physical::convertStringToAction(
      "xyz.openbmc_project.Led.Physical.Action.Blink");
  ASSERT_TRUE(r.has_value());
  EXPECT_EQ(*r, Action::Blink);
}

TEST(LedActionConvertStringTo, InvalidReturnsNullopt) {
  EXPECT_FALSE(Physical::convertStringToAction("xyz.invalid").has_value());
}

// ── Palette enum → string
// ─────────────────────────────────────────────────────

TEST(LedPaletteToString, Unknown) {
  EXPECT_EQ(Physical::convertPaletteToString(Palette::Unknown),
            "xyz.openbmc_project.Led.Physical.Palette.Unknown");
}

TEST(LedPaletteToString, Red) {
  EXPECT_EQ(Physical::convertPaletteToString(Palette::Red),
            "xyz.openbmc_project.Led.Physical.Palette.Red");
}

TEST(LedPaletteToString, Green) {
  EXPECT_EQ(Physical::convertPaletteToString(Palette::Green),
            "xyz.openbmc_project.Led.Physical.Palette.Green");
}

TEST(LedPaletteToString, Blue) {
  EXPECT_EQ(Physical::convertPaletteToString(Palette::Blue),
            "xyz.openbmc_project.Led.Physical.Palette.Blue");
}

TEST(LedPaletteToString, Yellow) {
  EXPECT_EQ(Physical::convertPaletteToString(Palette::Yellow),
            "xyz.openbmc_project.Led.Physical.Palette.Yellow");
}

// ── Palette string → enum
// ─────────────────────────────────────────────────────

TEST(LedPaletteFromString, Green) {
  EXPECT_EQ(Physical::convertPaletteFromString(
                "xyz.openbmc_project.Led.Physical.Palette.Green"),
            Palette::Green);
}

TEST(LedPaletteFromString, InvalidThrows) {
  EXPECT_THROW(Physical::convertPaletteFromString("xyz.invalid"),
               sdbusplus::exception::InvalidEnumString);
}

// ── property names
// ────────────────────────────────────────────────────────────

TEST(LedPhysicalPropertyNames, State) {
  EXPECT_STREQ(Physical::property_names::state, "State");
}

TEST(LedPhysicalPropertyNames, DutyOn) {
  EXPECT_STREQ(Physical::property_names::duty_on, "DutyOn");
}

TEST(LedPhysicalPropertyNames, Color) {
  EXPECT_STREQ(Physical::property_names::color, "Color");
}

TEST(LedPhysicalPropertyNames, Period) {
  EXPECT_STREQ(Physical::property_names::period, "Period");
}

// ── unpack
// ────────────────────────────────────────────────────────────────────

TEST(LedPhysicalPropertiesUnpack, ValidMap_Unpacks) {
  std::map<std::string, Physical::PropertiesVariant> props;
  props["State"] = Action::Blink;
  props["DutyOn"] = static_cast<uint8_t>(75);
  props["Color"] = Palette::Red;
  props["Period"] = static_cast<uint16_t>(500);

  Physical::properties_t result{};
  ASSERT_NO_THROW(result = Physical::properties_t::unpack(props));
  EXPECT_EQ(result.state, Action::Blink);
  EXPECT_EQ(result.duty_on, 75u);
  EXPECT_EQ(result.color, Palette::Red);
  EXPECT_EQ(result.period, 500u);
}

TEST(LedPhysicalPropertiesUnpack, EmptyMap_UsesDefaults) {
  std::map<std::string, Physical::PropertiesVariant> props;
  Physical::properties_t result{};
  ASSERT_NO_THROW(result = Physical::properties_t::unpack(props));
  EXPECT_EQ(result.state, Action::Off);
  EXPECT_EQ(result.duty_on, 50u);
  EXPECT_EQ(result.color, Palette::Unknown);
  EXPECT_EQ(result.period, 1000u);
}

} // namespace
