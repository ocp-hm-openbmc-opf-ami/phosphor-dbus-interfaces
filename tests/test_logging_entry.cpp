// Edge-case tests for xyz.openbmc_project.Logging.Entry (Level + Notify enums)
#include <xyz/openbmc_project/Logging/Entry/common.hpp>

#include <map>
#include <stdexcept>
#include <string>

#include <gtest/gtest.h>

namespace
{

using Entry = sdbusplus::common::xyz::openbmc_project::logging::Entry;
using Level = Entry::Level;
using Notify = Entry::Notify;

// ── Interface name
// ────────────────────────────────────────────────────────────

TEST(LoggingEntryInterface, InterfaceName)
{
    EXPECT_STREQ(Entry::interface, "xyz.openbmc_project.Logging.Entry");
}

// ── Property name constants
// ───────────────────────────────────────────────────

TEST(LoggingEntryPropertyNames, Id)
{
    EXPECT_STREQ(Entry::property_names::id, "Id");
}

TEST(LoggingEntryPropertyNames, Severity)
{
    EXPECT_STREQ(Entry::property_names::severity, "Severity");
}

TEST(LoggingEntryPropertyNames, Resolved)
{
    EXPECT_STREQ(Entry::property_names::resolved, "Resolved");
}

// ── Level enum → string (all 9 values) ───────────────────────────────────────

TEST(LoggingLevelToString, Emergency)
{
    EXPECT_EQ(Entry::convertLevelToString(Level::Emergency),
              "xyz.openbmc_project.Logging.Entry.Level.Emergency");
}

TEST(LoggingLevelToString, Alert)
{
    EXPECT_EQ(Entry::convertLevelToString(Level::Alert),
              "xyz.openbmc_project.Logging.Entry.Level.Alert");
}

TEST(LoggingLevelToString, Critical)
{
    EXPECT_EQ(Entry::convertLevelToString(Level::Critical),
              "xyz.openbmc_project.Logging.Entry.Level.Critical");
}

TEST(LoggingLevelToString, Error)
{
    EXPECT_EQ(Entry::convertLevelToString(Level::Error),
              "xyz.openbmc_project.Logging.Entry.Level.Error");
}

TEST(LoggingLevelToString, Warning)
{
    EXPECT_EQ(Entry::convertLevelToString(Level::Warning),
              "xyz.openbmc_project.Logging.Entry.Level.Warning");
}

TEST(LoggingLevelToString, Notice)
{
    EXPECT_EQ(Entry::convertLevelToString(Level::Notice),
              "xyz.openbmc_project.Logging.Entry.Level.Notice");
}

TEST(LoggingLevelToString, Informational)
{
    EXPECT_EQ(Entry::convertLevelToString(Level::Informational),
              "xyz.openbmc_project.Logging.Entry.Level.Informational");
}

TEST(LoggingLevelToString, Debug)
{
    EXPECT_EQ(Entry::convertLevelToString(Level::Debug),
              "xyz.openbmc_project.Logging.Entry.Level.Debug");
}

TEST(LoggingLevelToString, NotApplicable)
{
    EXPECT_EQ(Entry::convertLevelToString(Level::NotApplicable),
              "xyz.openbmc_project.Logging.Entry.Level.NotApplicable");
}

// ── Level string → enum
// ───────────────────────────────────────────────────────

TEST(LoggingLevelFromString, Emergency)
{
    EXPECT_EQ(Entry::convertLevelFromString(
                  "xyz.openbmc_project.Logging.Entry.Level.Emergency"),
              Level::Emergency);
}

TEST(LoggingLevelFromString, Error)
{
    EXPECT_EQ(Entry::convertLevelFromString(
                  "xyz.openbmc_project.Logging.Entry.Level.Error"),
              Level::Error);
}

TEST(LoggingLevelFromString, Debug)
{
    EXPECT_EQ(Entry::convertLevelFromString(
                  "xyz.openbmc_project.Logging.Entry.Level.Debug"),
              Level::Debug);
}

TEST(LoggingLevelFromString, NotApplicable)
{
    EXPECT_EQ(Entry::convertLevelFromString(
                  "xyz.openbmc_project.Logging.Entry.Level.NotApplicable"),
              Level::NotApplicable);
}

// ── Level edge cases: invalid input ──────────────────────────────────────────

TEST(LoggingLevelFromString, InvalidStringThrows)
{
    EXPECT_THROW(Entry::convertLevelFromString("xyz.invalid"),
                 sdbusplus::exception::InvalidEnumString);
}

TEST(LoggingLevelFromString, EmptyStringThrows)
{
    EXPECT_THROW(Entry::convertLevelFromString(""),
                 sdbusplus::exception::InvalidEnumString);
}

TEST(LoggingLevelFromString, PartialPrefixThrows)
{
    // Prefix only — no value name appended
    EXPECT_THROW(Entry::convertLevelFromString(
                     "xyz.openbmc_project.Logging.Entry.Level"),
                 sdbusplus::exception::InvalidEnumString);
}

TEST(LoggingLevelFromString, WrongCaseThrows)
{
    // Enum values are case-sensitive
    EXPECT_THROW(Entry::convertLevelFromString(
                     "xyz.openbmc_project.Logging.Entry.Level.error"),
                 sdbusplus::exception::InvalidEnumString);
}

// ── convertStringToLevel (optional variant)
// ───────────────────────────────────

TEST(LoggingLevelConvertStringTo, ValidReturnsValue)
{
    auto r = Entry::convertStringToLevel(
        "xyz.openbmc_project.Logging.Entry.Level.Warning");
    ASSERT_TRUE(r.has_value());
    EXPECT_EQ(*r, Level::Warning);
}

TEST(LoggingLevelConvertStringTo, InvalidReturnsNullopt)
{
    EXPECT_FALSE(Entry::convertStringToLevel("xyz.invalid").has_value());
}

TEST(LoggingLevelConvertStringTo, EmptyStringReturnsNullopt)
{
    EXPECT_FALSE(Entry::convertStringToLevel("").has_value());
}

// ── Notify enum → string (all 3 values) ──────────────────────────────────────

TEST(LoggingNotifyToString, NotSupported)
{
    EXPECT_EQ(Entry::convertNotifyToString(Notify::NotSupported),
              "xyz.openbmc_project.Logging.Entry.Notify.NotSupported");
}

TEST(LoggingNotifyToString, Notify)
{
    EXPECT_EQ(Entry::convertNotifyToString(Notify::Notify),
              "xyz.openbmc_project.Logging.Entry.Notify.Notify");
}

TEST(LoggingNotifyToString, Inhibit)
{
    EXPECT_EQ(Entry::convertNotifyToString(Notify::Inhibit),
              "xyz.openbmc_project.Logging.Entry.Notify.Inhibit");
}

// ── Notify string → enum
// ──────────────────────────────────────────────────────

TEST(LoggingNotifyFromString, Notify)
{
    EXPECT_EQ(Entry::convertNotifyFromString(
                  "xyz.openbmc_project.Logging.Entry.Notify.Notify"),
              Notify::Notify);
}

TEST(LoggingNotifyFromString, Inhibit)
{
    EXPECT_EQ(Entry::convertNotifyFromString(
                  "xyz.openbmc_project.Logging.Entry.Notify.Inhibit"),
              Notify::Inhibit);
}

TEST(LoggingNotifyFromString, InvalidStringThrows)
{
    EXPECT_THROW(Entry::convertNotifyFromString("xyz.invalid"),
                 sdbusplus::exception::InvalidEnumString);
}

TEST(LoggingNotifyFromString, EmptyStringThrows)
{
    EXPECT_THROW(Entry::convertNotifyFromString(""),
                 sdbusplus::exception::InvalidEnumString);
}

// ── convertStringToNotify (optional variant) ─────────────────────────────────

TEST(LoggingNotifyConvertStringTo, ValidReturnsValue)
{
    auto r = Entry::convertStringToNotify(
        "xyz.openbmc_project.Logging.Entry.Notify.NotSupported");
    ASSERT_TRUE(r.has_value());
    EXPECT_EQ(*r, Notify::NotSupported);
}

TEST(LoggingNotifyConvertStringTo, InvalidReturnsNullopt)
{
    EXPECT_FALSE(Entry::convertStringToNotify("xyz.bad").has_value());
}

// ── Properties unpack ────────────────────────────────────────────────────────

static Entry::properties_t unpackProps(
    const std::map<std::string, Entry::PropertiesVariant>& m)
{
    Entry::properties_t r{};
    if (auto it = m.find("Severity"); it != m.end())
        if (auto* v = std::get_if<Level>(&it->second))
            r.severity = *v;
    if (auto it = m.find("Resolved"); it != m.end())
        if (auto* v = std::get_if<bool>(&it->second))
            r.resolved = *v;
    if (auto it = m.find("ServiceProviderNotify"); it != m.end())
        if (auto* v = std::get_if<Notify>(&it->second))
            r.service_provider_notify = *v;
    return r;
}

TEST(LoggingEntryPropertiesUnpack, ValidMap)
{
    std::map<std::string, Entry::PropertiesVariant> props;
    props["Severity"] = Level::Critical;
    props["Resolved"] = false;
    props["ServiceProviderNotify"] = Notify::Notify;

    Entry::properties_t result{};
    ASSERT_NO_THROW(result = unpackProps(props));
    EXPECT_EQ(result.severity, Level::Critical);
    EXPECT_FALSE(result.resolved);
    EXPECT_EQ(result.service_provider_notify, Notify::Notify);
}

TEST(LoggingEntryPropertiesUnpack, EmptyMapYieldsDefaults)
{
    std::map<std::string, Entry::PropertiesVariant> props;
    Entry::properties_t result{};
    ASSERT_NO_THROW(result = unpackProps(props));
    // Defaults from properties_t definition
    EXPECT_FALSE(result.resolved);
}

TEST(LoggingEntryPropertiesUnpack, WrongVariantTypeIsIgnored)
{
    // Put a string where a Level enum is expected — the get_if branch won't
    // fire
    std::map<std::string, Entry::PropertiesVariant> props;
    props["Severity"] =
        std::string("xyz.openbmc_project.Logging.Entry.Level.Error");

    Entry::properties_t result{};
    ASSERT_NO_THROW(result = unpackProps(props));
    // severity should remain at default-initialised value
}

TEST(LoggingEntryPropertiesUnpack, UnknownKeyIsIgnored)
{
    std::map<std::string, Entry::PropertiesVariant> props;
    props["Severity"] = Level::Debug;
    props["UnknownProperty"] = std::string("irrelevant");

    Entry::properties_t result{};
    ASSERT_NO_THROW(result = unpackProps(props));
    EXPECT_EQ(result.severity, Level::Debug);
}

} // namespace
