#include <xyz/openbmc_project/Sensor/Value/common.hpp>

#include <gtest/gtest.h>

#include <cmath>
#include <limits>
#include <map>
#include <stdexcept>
#include <string>

namespace {

using Value = sdbusplus::common::xyz::openbmc_project::sensor::Value;
using Unit = Value::Unit;

// ── Interface name
// ────────────────────────────────────────────────────────────

TEST(SensorValueInterface, InterfaceName) {
  EXPECT_STREQ(Value::interface, "xyz.openbmc_project.Sensor.Value");
}

// ── Unit enum → string
// ────────────────────────────────────────────────────────

TEST(SensorUnitToString, Amperes) {
  EXPECT_EQ(Value::convertUnitToString(Unit::Amperes),
            "xyz.openbmc_project.Sensor.Value.Unit.Amperes");
}

TEST(SensorUnitToString, CFM) {
  EXPECT_EQ(Value::convertUnitToString(Unit::CFM),
            "xyz.openbmc_project.Sensor.Value.Unit.CFM");
}

TEST(SensorUnitToString, DegreesC) {
  EXPECT_EQ(Value::convertUnitToString(Unit::DegreesC),
            "xyz.openbmc_project.Sensor.Value.Unit.DegreesC");
}

TEST(SensorUnitToString, Hertz) {
  EXPECT_EQ(Value::convertUnitToString(Unit::Hertz),
            "xyz.openbmc_project.Sensor.Value.Unit.Hertz");
}

TEST(SensorUnitToString, Joules) {
  EXPECT_EQ(Value::convertUnitToString(Unit::Joules),
            "xyz.openbmc_project.Sensor.Value.Unit.Joules");
}

TEST(SensorUnitToString, LPM) {
  EXPECT_EQ(Value::convertUnitToString(Unit::LPM),
            "xyz.openbmc_project.Sensor.Value.Unit.LPM");
}

TEST(SensorUnitToString, Meters) {
  EXPECT_EQ(Value::convertUnitToString(Unit::Meters),
            "xyz.openbmc_project.Sensor.Value.Unit.Meters");
}

TEST(SensorUnitToString, Percent) {
  EXPECT_EQ(Value::convertUnitToString(Unit::Percent),
            "xyz.openbmc_project.Sensor.Value.Unit.Percent");
}

TEST(SensorUnitToString, PercentRH) {
  EXPECT_EQ(Value::convertUnitToString(Unit::PercentRH),
            "xyz.openbmc_project.Sensor.Value.Unit.PercentRH");
}

TEST(SensorUnitToString, Pascals) {
  EXPECT_EQ(Value::convertUnitToString(Unit::Pascals),
            "xyz.openbmc_project.Sensor.Value.Unit.Pascals");
}

TEST(SensorUnitToString, RPMS) {
  EXPECT_EQ(Value::convertUnitToString(Unit::RPMS),
            "xyz.openbmc_project.Sensor.Value.Unit.RPMS");
}

TEST(SensorUnitToString, Volts) {
  EXPECT_EQ(Value::convertUnitToString(Unit::Volts),
            "xyz.openbmc_project.Sensor.Value.Unit.Volts");
}

TEST(SensorUnitToString, Watts) {
  EXPECT_EQ(Value::convertUnitToString(Unit::Watts),
            "xyz.openbmc_project.Sensor.Value.Unit.Watts");
}

TEST(SensorUnitToString, Counts) {
  EXPECT_EQ(Value::convertUnitToString(Unit::Counts),
            "xyz.openbmc_project.Sensor.Value.Unit.Counts");
}

// ── Unit string → enum
// ────────────────────────────────────────────────────────

TEST(SensorUnitFromString, DegreesC) {
  EXPECT_EQ(Value::convertUnitFromString(
                "xyz.openbmc_project.Sensor.Value.Unit.DegreesC"),
            Unit::DegreesC);
}

TEST(SensorUnitFromString, Volts) {
  EXPECT_EQ(Value::convertUnitFromString(
                "xyz.openbmc_project.Sensor.Value.Unit.Volts"),
            Unit::Volts);
}

TEST(SensorUnitFromString, Amperes) {
  EXPECT_EQ(Value::convertUnitFromString(
                "xyz.openbmc_project.Sensor.Value.Unit.Amperes"),
            Unit::Amperes);
}

TEST(SensorUnitFromString, InvalidThrows) {
  EXPECT_THROW(Value::convertUnitFromString("xyz.invalid"),
               sdbusplus::exception::InvalidEnumString);
}

TEST(SensorUnitConvertStringTo, ValidReturnsValue) {
  auto r =
      Value::convertStringToUnit("xyz.openbmc_project.Sensor.Value.Unit.Watts");
  ASSERT_TRUE(r.has_value());
  EXPECT_EQ(*r, Unit::Watts);
}

TEST(SensorUnitConvertStringTo, InvalidReturnsNullopt) {
  EXPECT_FALSE(Value::convertStringToUnit("xyz.invalid").has_value());
}

// ── property names
// ────────────────────────────────────────────────────────────

TEST(SensorValuePropertyNames, Value_) {
  EXPECT_STREQ(Value::property_names::value, "Value");
}

TEST(SensorValuePropertyNames, MaxValue) {
  EXPECT_STREQ(Value::property_names::max_value, "MaxValue");
}

TEST(SensorValuePropertyNames, MinValue) {
  EXPECT_STREQ(Value::property_names::min_value, "MinValue");
}

TEST(SensorValuePropertyNames, Unit_) {
  EXPECT_STREQ(Value::property_names::unit, "Unit");
}

// ── unpack
// ────────────────────────────────────────────────────────────────────

TEST(SensorValuePropertiesUnpack, ValidMap_UnpacksValueAndUnit) {
  std::map<std::string, Value::PropertiesVariant> props;
  props["Value"] = 42.5;
  props["Unit"] = Unit::DegreesC;

  Value::properties_t result{};
  ASSERT_NO_THROW(result = Value::properties_t::unpack(props));
  EXPECT_DOUBLE_EQ(result.value, 42.5);
  EXPECT_EQ(result.unit, Unit::DegreesC);
}

TEST(SensorValuePropertiesUnpack, EmptyMap_UsesDefaults) {
  std::map<std::string, Value::PropertiesVariant> props;
  Value::properties_t result{};
  ASSERT_NO_THROW(result = Value::properties_t::unpack(props));
  EXPECT_TRUE(std::isinf(result.max_value));
}

} // namespace
