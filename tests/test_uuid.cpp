#include <xyz/openbmc_project/Common/UUID/common.hpp>

#ifdef FAIL
#undef FAIL
#endif
#ifdef ERROR
#undef ERROR
#endif

#include <map>
#include <string>

#include <gtest/gtest.h>

namespace
{

using UUID = sdbusplus::common::xyz::openbmc_project::common::UUID;

// ── Interface name
// ────────────────────────────────────────────────────────────

TEST(UUIDInterface, InterfaceName_IsCorrect)
{
    EXPECT_STREQ(UUID::interface, "xyz.openbmc_project.Common.UUID");
}

// ── Property name constants
// ───────────────────────────────────────────────────

TEST(UUIDPropertyNames, UuidName_IsUUID)
{
    EXPECT_STREQ(UUID::property_names::uuid, "UUID");
}

// ── properties_t construction
// ─────────────────────────────────────────────────

TEST(UUIDPropertiesT, DefaultConstruct_HasEmptyUuid)
{
    const UUID::properties_t props{};
    EXPECT_TRUE(props.uuid.empty());
}

// ── properties_t::unpack ─────────────────────────────────────────────────────

static UUID::properties_t unpackProps(
    const std::map<std::string, UUID::PropertiesVariant>& m)
{
    UUID::properties_t r{};
    if (auto it = m.find("UUID"); it != m.end())
        if (auto* v = std::get_if<std::string>(&it->second))
            r.uuid = *v;
    return r;
}

TEST(UUIDPropertiesUnpack, ValidMap_UnpacksUuid)
{
    const std::string testUuid = "xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx";
    std::map<std::string, UUID::PropertiesVariant> props;
    props["UUID"] = testUuid;
    UUID::properties_t result{};
    ASSERT_NO_THROW(result = unpackProps(props));
    EXPECT_EQ(result.uuid, testUuid);
}

} // namespace
