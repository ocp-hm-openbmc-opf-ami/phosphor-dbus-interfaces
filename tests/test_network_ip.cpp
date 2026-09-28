// Edge-case tests for xyz.openbmc_project.Network.IP (Protocol + AddressOrigin)
#include <xyz/openbmc_project/Network/IP/common.hpp>

#include <map>
#include <stdexcept>
#include <string>

#include <gtest/gtest.h>

namespace
{

using IP = sdbusplus::common::xyz::openbmc_project::network::IP;
using Protocol = IP::Protocol;
using AddressOrigin = IP::AddressOrigin;

// ── Interface name
// ────────────────────────────────────────────────────────────

TEST(NetworkIPInterface, InterfaceName)
{
    EXPECT_STREQ(IP::interface, "xyz.openbmc_project.Network.IP");
}

// ── Property name constants
// ───────────────────────────────────────────────────

TEST(NetworkIPPropertyNames, Address)
{
    EXPECT_STREQ(IP::property_names::address, "Address");
}

TEST(NetworkIPPropertyNames, PrefixLength)
{
    EXPECT_STREQ(IP::property_names::prefix_length, "PrefixLength");
}

TEST(NetworkIPPropertyNames, Origin)
{
    EXPECT_STREQ(IP::property_names::origin, "Origin");
}

TEST(NetworkIPPropertyNames, Type)
{
    EXPECT_STREQ(IP::property_names::type, "Type");
}

// ── Protocol enum → string (both values) ─────────────────────────────────────

TEST(NetworkIPProtocolToString, IPv4)
{
    EXPECT_EQ(IP::convertProtocolToString(Protocol::IPv4),
              "xyz.openbmc_project.Network.IP.Protocol.IPv4");
}

TEST(NetworkIPProtocolToString, IPv6)
{
    EXPECT_EQ(IP::convertProtocolToString(Protocol::IPv6),
              "xyz.openbmc_project.Network.IP.Protocol.IPv6");
}

// ── Protocol string → enum
// ────────────────────────────────────────────────────

TEST(NetworkIPProtocolFromString, IPv4)
{
    EXPECT_EQ(IP::convertProtocolFromString(
                  "xyz.openbmc_project.Network.IP.Protocol.IPv4"),
              Protocol::IPv4);
}

TEST(NetworkIPProtocolFromString, IPv6)
{
    EXPECT_EQ(IP::convertProtocolFromString(
                  "xyz.openbmc_project.Network.IP.Protocol.IPv6"),
              Protocol::IPv6);
}

TEST(NetworkIPProtocolFromString, InvalidStringThrows)
{
    EXPECT_THROW(IP::convertProtocolFromString("xyz.invalid"),
                 sdbusplus::exception::InvalidEnumString);
}

TEST(NetworkIPProtocolFromString, EmptyStringThrows)
{
    EXPECT_THROW(IP::convertProtocolFromString(""),
                 sdbusplus::exception::InvalidEnumString);
}

TEST(NetworkIPProtocolFromString, LowercaseThrows)
{
    // Enum strings are case-sensitive
    EXPECT_THROW(IP::convertProtocolFromString(
                     "xyz.openbmc_project.Network.IP.Protocol.ipv4"),
                 sdbusplus::exception::InvalidEnumString);
}

// ── convertStringToProtocol (optional variant)
// ────────────────────────────────

TEST(NetworkIPProtocolConvertStringTo, ValidReturnsValue)
{
    auto r = IP::convertStringToProtocol(
        "xyz.openbmc_project.Network.IP.Protocol.IPv6");
    ASSERT_TRUE(r.has_value());
    EXPECT_EQ(*r, Protocol::IPv6);
}

TEST(NetworkIPProtocolConvertStringTo, InvalidReturnsNullopt)
{
    EXPECT_FALSE(IP::convertStringToProtocol("xyz.invalid").has_value());
}

TEST(NetworkIPProtocolConvertStringTo, EmptyStringReturnsNullopt)
{
    EXPECT_FALSE(IP::convertStringToProtocol("").has_value());
}

// ── AddressOrigin enum → string (all 4 values) ───────────────────────────────

TEST(NetworkIPAddressOriginToString, Static)
{
    EXPECT_EQ(IP::convertAddressOriginToString(AddressOrigin::Static),
              "xyz.openbmc_project.Network.IP.AddressOrigin.Static");
}

TEST(NetworkIPAddressOriginToString, DHCP)
{
    EXPECT_EQ(IP::convertAddressOriginToString(AddressOrigin::DHCP),
              "xyz.openbmc_project.Network.IP.AddressOrigin.DHCP");
}

TEST(NetworkIPAddressOriginToString, LinkLocal)
{
    EXPECT_EQ(IP::convertAddressOriginToString(AddressOrigin::LinkLocal),
              "xyz.openbmc_project.Network.IP.AddressOrigin.LinkLocal");
}

TEST(NetworkIPAddressOriginToString, SLAAC)
{
    EXPECT_EQ(IP::convertAddressOriginToString(AddressOrigin::SLAAC),
              "xyz.openbmc_project.Network.IP.AddressOrigin.SLAAC");
}

// ── AddressOrigin string → enum
// ───────────────────────────────────────────────

TEST(NetworkIPAddressOriginFromString, Static)
{
    EXPECT_EQ(IP::convertAddressOriginFromString(
                  "xyz.openbmc_project.Network.IP.AddressOrigin.Static"),
              AddressOrigin::Static);
}

TEST(NetworkIPAddressOriginFromString, DHCP)
{
    EXPECT_EQ(IP::convertAddressOriginFromString(
                  "xyz.openbmc_project.Network.IP.AddressOrigin.DHCP"),
              AddressOrigin::DHCP);
}

TEST(NetworkIPAddressOriginFromString, SLAAC)
{
    EXPECT_EQ(IP::convertAddressOriginFromString(
                  "xyz.openbmc_project.Network.IP.AddressOrigin.SLAAC"),
              AddressOrigin::SLAAC);
}

TEST(NetworkIPAddressOriginFromString, InvalidStringThrows)
{
    EXPECT_THROW(IP::convertAddressOriginFromString("xyz.invalid"),
                 sdbusplus::exception::InvalidEnumString);
}

TEST(NetworkIPAddressOriginFromString, EmptyStringThrows)
{
    EXPECT_THROW(IP::convertAddressOriginFromString(""),
                 sdbusplus::exception::InvalidEnumString);
}

TEST(NetworkIPAddressOriginFromString, PartialPrefixThrows)
{
    EXPECT_THROW(IP::convertAddressOriginFromString(
                     "xyz.openbmc_project.Network.IP.AddressOrigin"),
                 sdbusplus::exception::InvalidEnumString);
}

// ── convertStringToAddressOrigin (optional variant)
// ───────────────────────────

TEST(NetworkIPAddressOriginConvertStringTo, ValidReturnsValue)
{
    auto r = IP::convertStringToAddressOrigin(
        "xyz.openbmc_project.Network.IP.AddressOrigin.DHCP");
    ASSERT_TRUE(r.has_value());
    EXPECT_EQ(*r, AddressOrigin::DHCP);
}

TEST(NetworkIPAddressOriginConvertStringTo, InvalidReturnsNullopt)
{
    EXPECT_FALSE(IP::convertStringToAddressOrigin("xyz.bad").has_value());
}

// ── Properties unpack
// ─────────────────────────────────────────────────────────

static IP::properties_t unpackProps(
    const std::map<std::string, IP::PropertiesVariant>& m)
{
    IP::properties_t r{};
    if (auto it = m.find("Address"); it != m.end())
        if (auto* v = std::get_if<std::string>(&it->second))
            r.address = *v;
    if (auto it = m.find("PrefixLength"); it != m.end())
        if (auto* v = std::get_if<uint8_t>(&it->second))
            r.prefix_length = *v;
    if (auto it = m.find("Origin"); it != m.end())
        if (auto* v = std::get_if<AddressOrigin>(&it->second))
            r.origin = *v;
    if (auto it = m.find("Type"); it != m.end())
        if (auto* v = std::get_if<Protocol>(&it->second))
            r.type = *v;
    return r;
}

TEST(NetworkIPPropertiesUnpack, ValidMap)
{
    std::map<std::string, IP::PropertiesVariant> props;
    props["Address"] = std::string("192.168.1.100");
    props["PrefixLength"] = static_cast<uint8_t>(24);
    props["Origin"] = AddressOrigin::Static;
    props["Type"] = Protocol::IPv4;

    IP::properties_t result{};
    ASSERT_NO_THROW(result = unpackProps(props));
    EXPECT_EQ(result.address, "192.168.1.100");
    EXPECT_EQ(result.prefix_length, 24u);
    EXPECT_EQ(result.origin, AddressOrigin::Static);
    EXPECT_EQ(result.type, Protocol::IPv4);
}

TEST(NetworkIPPropertiesUnpack, EmptyMapYieldsDefaults)
{
    std::map<std::string, IP::PropertiesVariant> props;
    IP::properties_t result{};
    ASSERT_NO_THROW(result = unpackProps(props));
    EXPECT_EQ(result.address, "");
    EXPECT_EQ(result.prefix_length, 0u);
}

TEST(NetworkIPPropertiesUnpack, WrongVariantTypeIsIgnored)
{
    // Wrong type for "Origin" — should silently skip, not crash
    std::map<std::string, IP::PropertiesVariant> props;
    props["Origin"] = std::string("not-an-enum");

    IP::properties_t result{};
    ASSERT_NO_THROW(result = unpackProps(props));
}

TEST(NetworkIPPropertiesUnpack, UnknownKeyIsIgnored)
{
    std::map<std::string, IP::PropertiesVariant> props;
    props["Type"] = Protocol::IPv6;
    props["Nonexistent"] = std::string("irrelevant");

    IP::properties_t result{};
    ASSERT_NO_THROW(result = unpackProps(props));
    EXPECT_EQ(result.type, Protocol::IPv6);
}

TEST(NetworkIPPropertiesUnpack, IPv6AddressAndPrefixLength128)
{
    std::map<std::string, IP::PropertiesVariant> props;
    props["Address"] = std::string("2001:db8::1");
    props["PrefixLength"] = static_cast<uint8_t>(128);
    props["Origin"] = AddressOrigin::SLAAC;
    props["Type"] = Protocol::IPv6;

    IP::properties_t result{};
    ASSERT_NO_THROW(result = unpackProps(props));
    EXPECT_EQ(result.address, "2001:db8::1");
    EXPECT_EQ(result.prefix_length, 128u);
    EXPECT_EQ(result.origin, AddressOrigin::SLAAC);
    EXPECT_EQ(result.type, Protocol::IPv6);
}

} // namespace
