// Edge-case tests for xyz.openbmc_project.HardwareIsolation.Entry (Type enum)
#include <xyz/openbmc_project/HardwareIsolation/Entry/common.hpp>

#include <map>
#include <stdexcept>
#include <string>

#include <gtest/gtest.h>

namespace
{

using HWEntry =
    sdbusplus::common::xyz::openbmc_project::hardware_isolation::Entry;
using Type = HWEntry::Type;

// ── Interface name
// ────────────────────────────────────────────────────────────

TEST(HardwareIsolationEntryInterface, InterfaceName)
{
    EXPECT_STREQ(HWEntry::interface,
                 "xyz.openbmc_project.HardwareIsolation.Entry");
}

// ── Property name constants
// ───────────────────────────────────────────────────

TEST(HardwareIsolationEntryPropertyNames, Severity)
{
    EXPECT_STREQ(HWEntry::property_names::severity, "Severity");
}

TEST(HardwareIsolationEntryPropertyNames, Resolved)
{
    EXPECT_STREQ(HWEntry::property_names::resolved, "Resolved");
}

// ── Type enum → string (all 3 values) ────────────────────────────────────────

TEST(HardwareIsolationTypeToString, Critical)
{
    EXPECT_EQ(HWEntry::convertTypeToString(Type::Critical),
              "xyz.openbmc_project.HardwareIsolation.Entry.Type.Critical");
}

TEST(HardwareIsolationTypeToString, Warning)
{
    EXPECT_EQ(HWEntry::convertTypeToString(Type::Warning),
              "xyz.openbmc_project.HardwareIsolation.Entry.Type.Warning");
}

TEST(HardwareIsolationTypeToString, Manual)
{
    EXPECT_EQ(HWEntry::convertTypeToString(Type::Manual),
              "xyz.openbmc_project.HardwareIsolation.Entry.Type.Manual");
}

// ── Type string → enum
// ────────────────────────────────────────────────────────

TEST(HardwareIsolationTypeFromString, Critical)
{
    EXPECT_EQ(HWEntry::convertTypeFromString(
                  "xyz.openbmc_project.HardwareIsolation.Entry.Type.Critical"),
              Type::Critical);
}

TEST(HardwareIsolationTypeFromString, Warning)
{
    EXPECT_EQ(HWEntry::convertTypeFromString(
                  "xyz.openbmc_project.HardwareIsolation.Entry.Type.Warning"),
              Type::Warning);
}

TEST(HardwareIsolationTypeFromString, Manual)
{
    EXPECT_EQ(HWEntry::convertTypeFromString(
                  "xyz.openbmc_project.HardwareIsolation.Entry.Type.Manual"),
              Type::Manual);
}

// ── Type edge cases: invalid input ───────────────────────────────────────────

TEST(HardwareIsolationTypeFromString, InvalidStringThrows)
{
    EXPECT_THROW(HWEntry::convertTypeFromString("xyz.invalid"),
                 sdbusplus::exception::InvalidEnumString);
}

TEST(HardwareIsolationTypeFromString, EmptyStringThrows)
{
    EXPECT_THROW(HWEntry::convertTypeFromString(""),
                 sdbusplus::exception::InvalidEnumString);
}

TEST(HardwareIsolationTypeFromString, PartialPrefixThrows)
{
    EXPECT_THROW(HWEntry::convertTypeFromString(
                     "xyz.openbmc_project.HardwareIsolation.Entry.Type"),
                 sdbusplus::exception::InvalidEnumString);
}

TEST(HardwareIsolationTypeFromString, WrongCaseThrows)
{
    // Enum strings are case-sensitive
    EXPECT_THROW(
        HWEntry::convertTypeFromString(
            "xyz.openbmc_project.HardwareIsolation.Entry.Type.critical"),
        sdbusplus::exception::InvalidEnumString);
}

TEST(HardwareIsolationTypeFromString, WhitespaceStringThrows)
{
    EXPECT_THROW(HWEntry::convertTypeFromString("   "),
                 sdbusplus::exception::InvalidEnumString);
}

// ── convertStringToType (optional variant)
// ────────────────────────────────────

TEST(HardwareIsolationTypeConvertStringTo, ValidCriticalReturnsValue)
{
    auto r = HWEntry::convertStringToType(
        "xyz.openbmc_project.HardwareIsolation.Entry.Type.Critical");
    ASSERT_TRUE(r.has_value());
    EXPECT_EQ(*r, Type::Critical);
}

TEST(HardwareIsolationTypeConvertStringTo, ValidWarningReturnsValue)
{
    auto r = HWEntry::convertStringToType(
        "xyz.openbmc_project.HardwareIsolation.Entry.Type.Warning");
    ASSERT_TRUE(r.has_value());
    EXPECT_EQ(*r, Type::Warning);
}

TEST(HardwareIsolationTypeConvertStringTo, ValidManualReturnsValue)
{
    auto r = HWEntry::convertStringToType(
        "xyz.openbmc_project.HardwareIsolation.Entry.Type.Manual");
    ASSERT_TRUE(r.has_value());
    EXPECT_EQ(*r, Type::Manual);
}

TEST(HardwareIsolationTypeConvertStringTo, InvalidReturnsNullopt)
{
    EXPECT_FALSE(HWEntry::convertStringToType("xyz.bad").has_value());
}

TEST(HardwareIsolationTypeConvertStringTo, EmptyStringReturnsNullopt)
{
    EXPECT_FALSE(HWEntry::convertStringToType("").has_value());
}

// ── Round-trip: ToStr → FromStr == original
// ───────────────────────────────────

TEST(HardwareIsolationTypeRoundTrip, CriticalRoundTrip)
{
    const auto s = HWEntry::convertTypeToString(Type::Critical);
    EXPECT_EQ(HWEntry::convertTypeFromString(s), Type::Critical);
}

TEST(HardwareIsolationTypeRoundTrip, WarningRoundTrip)
{
    const auto s = HWEntry::convertTypeToString(Type::Warning);
    EXPECT_EQ(HWEntry::convertTypeFromString(s), Type::Warning);
}

TEST(HardwareIsolationTypeRoundTrip, ManualRoundTrip)
{
    const auto s = HWEntry::convertTypeToString(Type::Manual);
    EXPECT_EQ(HWEntry::convertTypeFromString(s), Type::Manual);
}

// ── Properties unpack
// ─────────────────────────────────────────────────────────

static HWEntry::properties_t unpackProps(
    const std::map<std::string, HWEntry::PropertiesVariant>& m)
{
    HWEntry::properties_t r{};
    if (auto it = m.find("Severity"); it != m.end())
        if (auto* v = std::get_if<Type>(&it->second))
            r.severity = *v;
    if (auto it = m.find("Resolved"); it != m.end())
        if (auto* v = std::get_if<bool>(&it->second))
            r.resolved = *v;
    return r;
}

TEST(HardwareIsolationPropertiesUnpack, ValidMapCriticalUnresolved)
{
    std::map<std::string, HWEntry::PropertiesVariant> props;
    props["Severity"] = Type::Critical;
    props["Resolved"] = false;

    HWEntry::properties_t result{};
    ASSERT_NO_THROW(result = unpackProps(props));
    EXPECT_EQ(result.severity, Type::Critical);
    EXPECT_FALSE(result.resolved);
}

TEST(HardwareIsolationPropertiesUnpack, ValidMapWarningResolved)
{
    std::map<std::string, HWEntry::PropertiesVariant> props;
    props["Severity"] = Type::Warning;
    props["Resolved"] = true;

    HWEntry::properties_t result{};
    ASSERT_NO_THROW(result = unpackProps(props));
    EXPECT_EQ(result.severity, Type::Warning);
    EXPECT_TRUE(result.resolved);
}

TEST(HardwareIsolationPropertiesUnpack, EmptyMapYieldsDefaults)
{
    std::map<std::string, HWEntry::PropertiesVariant> props;
    HWEntry::properties_t result{};
    ASSERT_NO_THROW(result = unpackProps(props));
    EXPECT_FALSE(result.resolved);
}

TEST(HardwareIsolationPropertiesUnpack, WrongVariantTypeIsIgnored)
{
    // String value where Type enum is expected — get_if branch should not fire
    std::map<std::string, HWEntry::PropertiesVariant> props;
    // bool is in the variant but is not the Type enum
    props["Severity"] = true;
    props["Resolved"] = false;

    HWEntry::properties_t result{};
    ASSERT_NO_THROW(result = unpackProps(props));
    EXPECT_FALSE(result.resolved);
}

TEST(HardwareIsolationPropertiesUnpack, UnknownKeyIsIgnored)
{
    std::map<std::string, HWEntry::PropertiesVariant> props;
    props["Severity"] = Type::Manual;
    props["Bogus"] = true; // extra key not in schema

    HWEntry::properties_t result{};
    ASSERT_NO_THROW(result = unpackProps(props));
    EXPECT_EQ(result.severity, Type::Manual);
}

} // namespace
