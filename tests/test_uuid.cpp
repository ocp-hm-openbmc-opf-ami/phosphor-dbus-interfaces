#include <xyz/openbmc_project/Common/UUID/common.hpp>

#ifdef FAIL
#undef FAIL
#endif
#ifdef ERROR
#undef ERROR
#endif

#include <gtest/gtest.h>

#include <map>
#include <string>

namespace {

using UUID = sdbusplus::common::xyz::openbmc_project::common::UUID;

// ── Interface name
// ────────────────────────────────────────────────────────────

TEST(UUIDInterface, InterfaceName_IsCorrect) {
  EXPECT_STREQ(UUID::interface, "xyz.openbmc_project.Common.UUID");
}

// ── Property name constants
// ───────────────────────────────────────────────────

TEST(UUIDPropertyNames, UuidName_IsUUID) {
  EXPECT_STREQ(UUID::property_names::uuid, "UUID");
}

TEST(UUIDPropertyNames, UuidTagName_IsUUID) {
  EXPECT_STREQ(UUID::uuid_t::name, "UUID");
}

// ── uuid_t property struct
// ────────────────────────────────────────────────────

TEST(UUIDPropertyStruct, DefaultConstruct_Works) {
  const UUID::uuid_t tag{};
  (void)tag;
  SUCCEED();
}

TEST(UUIDPropertyStruct, ExplicitConstruct_Works) {
  const UUID::uuid_t tag{std::string{"xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx"}};
  (void)tag;
  SUCCEED();
}

// ── properties_t construction
// ─────────────────────────────────────────────────

TEST(UUIDPropertiesT, DefaultConstruct_HasEmptyUuid) {
  const UUID::properties_t props{};
  EXPECT_TRUE(props.uuid.empty());
}

// ── properties_t::unpack ─────────────────────────────────────────────────────

TEST(UUIDPropertiesUnpack, ValidMap_UnpacksUuid) {
  const std::string testUuid = "xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx";
  std::map<std::string, UUID::PropertiesVariant> props;
  props["UUID"] = testUuid;
  UUID::properties_t result{};
  ASSERT_NO_THROW(result = UUID::properties_t::unpack(props));
  EXPECT_EQ(result.uuid, testUuid);
}

} // namespace
