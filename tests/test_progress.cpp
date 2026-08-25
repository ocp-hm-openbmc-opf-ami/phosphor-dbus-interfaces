#include <xyz/openbmc_project/Common/Progress/common.hpp>

#ifdef FAIL
#undef FAIL
#endif
#ifdef ERROR
#undef ERROR
#endif

#include <gtest/gtest.h>

#include <map>
#include <stdexcept>
#include <string>

namespace {

using Progress = sdbusplus::common::xyz::openbmc_project::common::Progress;
using OperationStatus = Progress::OperationStatus;

// ── Interface name
// ────────────────────────────────────────────────────────────

TEST(ProgressInterface, InterfaceName_IsCorrect) {
  EXPECT_STREQ(Progress::interface, "xyz.openbmc_project.Common.Progress");
}

// ── Property name constants
// ───────────────────────────────────────────────────

TEST(ProgressPropertyNames, StatusName_IsStatus) {
  EXPECT_STREQ(Progress::property_names::status, "Status");
}

TEST(ProgressPropertyNames, StartTimeName_IsStartTime) {
  EXPECT_STREQ(Progress::property_names::start_time, "StartTime");
}

TEST(ProgressPropertyNames, CompletedTimeName_IsCompletedTime) {
  EXPECT_STREQ(Progress::property_names::completed_time, "CompletedTime");
}

TEST(ProgressPropertyNames, ProgressName_IsProgress) {
  EXPECT_STREQ(Progress::property_names::progress, "Progress");
}

// ── convertOperationStatusToString ───────────────────────────────────────────

TEST(ProgressEnumToString, NotStarted_ProducesExpectedString) {
  const std::string expected = "xyz.openbmc_project.Common.Progress."
                               "OperationStatus.NotStarted";
  EXPECT_EQ(
      Progress::convertOperationStatusToString(OperationStatus::NotStarted),
      expected);
}

TEST(ProgressEnumToString, InProgress_ProducesExpectedString) {
  const std::string expected = "xyz.openbmc_project.Common.Progress."
                               "OperationStatus.InProgress";
  EXPECT_EQ(
      Progress::convertOperationStatusToString(OperationStatus::InProgress),
      expected);
}

TEST(ProgressEnumToString, Completed_ProducesExpectedString) {
  const std::string expected = "xyz.openbmc_project.Common.Progress."
                               "OperationStatus.Completed";
  EXPECT_EQ(
      Progress::convertOperationStatusToString(OperationStatus::Completed),
      expected);
}

TEST(ProgressEnumToString, Failed_ProducesExpectedString) {
  const std::string expected = "xyz.openbmc_project.Common.Progress."
                               "OperationStatus.Failed";
  EXPECT_EQ(Progress::convertOperationStatusToString(OperationStatus::Failed),
            expected);
}

TEST(ProgressEnumToString, Aborted_ProducesExpectedString) {
  const std::string expected = "xyz.openbmc_project.Common.Progress."
                               "OperationStatus.Aborted";
  EXPECT_EQ(Progress::convertOperationStatusToString(OperationStatus::Aborted),
            expected);
}

// Finding 4 (Low — CCG E.14): throws std::invalid_argument instead of
// sdbusplus::exception::InvalidEnumString for out-of-range enum values.
TEST(ProgressEnumToString, OutOfRangeEnum_ThrowsInvalidArgument) {
  EXPECT_THROW(Progress::convertOperationStatusToString(
                   static_cast<OperationStatus>(99)),
               std::invalid_argument);
}

// ── convertStringToOperationStatus ───────────────────────────────────────────

TEST(ProgressStringToEnum, ValidNotStarted_ReturnsEnum) {
  const std::string s = "xyz.openbmc_project.Common.Progress."
                        "OperationStatus.NotStarted";
  EXPECT_EQ(Progress::convertStringToOperationStatus(s),
            OperationStatus::NotStarted);
}

TEST(ProgressStringToEnum, ValidInProgress_ReturnsEnum) {
  const std::string s = "xyz.openbmc_project.Common.Progress."
                        "OperationStatus.InProgress";
  EXPECT_EQ(Progress::convertStringToOperationStatus(s),
            OperationStatus::InProgress);
}

TEST(ProgressStringToEnum, ValidCompleted_ReturnsEnum) {
  const std::string s = "xyz.openbmc_project.Common.Progress."
                        "OperationStatus.Completed";
  EXPECT_EQ(Progress::convertStringToOperationStatus(s),
            OperationStatus::Completed);
}

TEST(ProgressStringToEnum, ValidFailed_ReturnsEnum) {
  const std::string s = "xyz.openbmc_project.Common.Progress."
                        "OperationStatus.Failed";
  EXPECT_EQ(Progress::convertStringToOperationStatus(s),
            OperationStatus::Failed);
}

TEST(ProgressStringToEnum, ValidAborted_ReturnsEnum) {
  const std::string s = "xyz.openbmc_project.Common.Progress."
                        "OperationStatus.Aborted";
  EXPECT_EQ(Progress::convertStringToOperationStatus(s),
            OperationStatus::Aborted);
}

TEST(ProgressStringToEnum, InvalidString_ReturnsNullopt) {
  EXPECT_EQ(Progress::convertStringToOperationStatus("invalid"), std::nullopt);
}

TEST(ProgressStringToEnum, EmptyString_ReturnsNullopt) {
  EXPECT_EQ(Progress::convertStringToOperationStatus(""), std::nullopt);
}

TEST(ProgressStringToEnum, PartialString_ReturnsNullopt) {
  EXPECT_EQ(Progress::convertStringToOperationStatus(
                "xyz.openbmc_project.Common.Progress.OperationStatus"),
            std::nullopt);
}

// ── convertOperationStatusFromString ─────────────────────────────────────────

TEST(ProgressFromString, ValidString_ReturnsEnum) {
  const std::string s = "xyz.openbmc_project.Common.Progress."
                        "OperationStatus.Completed";
  EXPECT_EQ(Progress::convertOperationStatusFromString(s),
            OperationStatus::Completed);
}

TEST(ProgressFromString, InvalidString_ThrowsInvalidEnumString) {
  EXPECT_THROW(Progress::convertOperationStatusFromString("invalid"),
               sdbusplus::exception::InvalidEnumString);
}

TEST(ProgressFromString, EmptyString_ThrowsInvalidEnumString) {
  EXPECT_THROW(Progress::convertOperationStatusFromString(""),
               sdbusplus::exception::InvalidEnumString);
}

// ── convertForMessage
// ─────────────────────────────────────────────────────────

TEST(ProgressConvertForMessage, NotStarted_ProducesExpectedString) {
  const std::string expected = "xyz.openbmc_project.Common.Progress."
                               "OperationStatus.NotStarted";
  using sdbusplus::common::xyz::openbmc_project::common::convertForMessage;
  EXPECT_EQ(convertForMessage(OperationStatus::NotStarted), expected);
}

// ── Enum round-trip
// ───────────────────────────────────────────────────────────

TEST(ProgressEnumRoundTrip, AllValues_RoundTripCorrectly) {
  const OperationStatus values[] = {
      OperationStatus::NotStarted, OperationStatus::InProgress,
      OperationStatus::Completed,  OperationStatus::Failed,
      OperationStatus::Aborted,
  };
  for (const auto v : values) {
    const auto str = Progress::convertOperationStatusToString(v);
    const auto back = Progress::convertStringToOperationStatus(str);
    ASSERT_TRUE(back.has_value());
    EXPECT_EQ(*back, v);
  }
}

// ── properties_t construction
// ─────────────────────────────────────────────────

TEST(ProgressPropertiesT, DefaultConstruct_HasInProgressStatus) {
  const Progress::properties_t props{};
  EXPECT_EQ(props.status, OperationStatus::InProgress);
}

TEST(ProgressPropertiesT, DefaultConstruct_HasZeroStartTime) {
  const Progress::properties_t props{};
  EXPECT_EQ(props.start_time, uint64_t{0});
}

TEST(ProgressPropertiesT, DefaultConstruct_HasZeroCompletedTime) {
  const Progress::properties_t props{};
  EXPECT_EQ(props.completed_time, uint64_t{0});
}

TEST(ProgressPropertiesT, DefaultConstruct_HasZeroProgress) {
  const Progress::properties_t props{};
  EXPECT_EQ(props.progress, uint8_t{0});
}

// ── properties_t::unpack ─────────────────────────────────────────────────────

TEST(ProgressPropertiesUnpack, ValidMap_UnpacksAllProperties) {
  std::map<std::string, Progress::PropertiesVariant> props;
  props["Status"] = OperationStatus::NotStarted;
  props["StartTime"] = uint64_t{100};
  props["CompletedTime"] = uint64_t{200};
  props["Progress"] = uint8_t{50};
  Progress::properties_t result{};
  ASSERT_NO_THROW(result = Progress::properties_t::unpack(props));
  EXPECT_EQ(result.status, OperationStatus::NotStarted);
  EXPECT_EQ(result.start_time, uint64_t{100});
  EXPECT_EQ(result.completed_time, uint64_t{200});
  EXPECT_EQ(result.progress, uint8_t{50});
}

} // namespace
