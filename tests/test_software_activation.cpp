#include <xyz/openbmc_project/Software/Activation/common.hpp>

#include <gtest/gtest.h>

#include <map>
#include <stdexcept>
#include <string>

namespace {

using Activation =
    sdbusplus::common::xyz::openbmc_project::software::Activation;
using Activations = Activation::Activations;
using RequestedActivations = Activation::RequestedActivations;

// ── Interface name
// ────────────────────────────────────────────────────────────

TEST(ActivationInterface, InterfaceName) {
  EXPECT_STREQ(Activation::interface,
               "xyz.openbmc_project.Software.Activation");
}

// ── Activations enum → string
// ─────────────────────────────────────────────────

TEST(ActivationsToString, NotReady) {
  EXPECT_EQ(Activation::convertActivationsToString(Activations::NotReady),
            "xyz.openbmc_project.Software.Activation.Activations.NotReady");
}

TEST(ActivationsToString, Invalid) {
  EXPECT_EQ(Activation::convertActivationsToString(Activations::Invalid),
            "xyz.openbmc_project.Software.Activation.Activations.Invalid");
}

TEST(ActivationsToString, Ready) {
  EXPECT_EQ(Activation::convertActivationsToString(Activations::Ready),
            "xyz.openbmc_project.Software.Activation.Activations.Ready");
}

TEST(ActivationsToString, Activating) {
  EXPECT_EQ(Activation::convertActivationsToString(Activations::Activating),
            "xyz.openbmc_project.Software.Activation.Activations.Activating");
}

TEST(ActivationsToString, ActivatingAsStandbySpare) {
  EXPECT_EQ(Activation::convertActivationsToString(
                Activations::ActivatingAsStandbySpare),
            "xyz.openbmc_project.Software.Activation.Activations."
            "ActivatingAsStandbySpare");
}

TEST(ActivationsToString, Active) {
  EXPECT_EQ(Activation::convertActivationsToString(Activations::Active),
            "xyz.openbmc_project.Software.Activation.Activations.Active");
}

TEST(ActivationsToString, Failed) {
  EXPECT_EQ(Activation::convertActivationsToString(Activations::Failed),
            "xyz.openbmc_project.Software.Activation.Activations.Failed");
}

TEST(ActivationsToString, StandbySpare) {
  EXPECT_EQ(Activation::convertActivationsToString(Activations::StandbySpare),
            "xyz.openbmc_project.Software.Activation.Activations.StandbySpare");
}

TEST(ActivationsToString, Staged) {
  EXPECT_EQ(Activation::convertActivationsToString(Activations::Staged),
            "xyz.openbmc_project.Software.Activation.Activations.Staged");
}

TEST(ActivationsToString, Staging) {
  EXPECT_EQ(Activation::convertActivationsToString(Activations::Staging),
            "xyz.openbmc_project.Software.Activation.Activations.Staging");
}

// ── Activations string → enum
// ─────────────────────────────────────────────────

TEST(ActivationsFromString, Active) {
  EXPECT_EQ(Activation::convertActivationsFromString(
                "xyz.openbmc_project.Software.Activation.Activations.Active"),
            Activations::Active);
}

TEST(ActivationsFromString, Failed) {
  EXPECT_EQ(Activation::convertActivationsFromString(
                "xyz.openbmc_project.Software.Activation.Activations.Failed"),
            Activations::Failed);
}

TEST(ActivationsFromString, Ready) {
  EXPECT_EQ(Activation::convertActivationsFromString(
                "xyz.openbmc_project.Software.Activation.Activations.Ready"),
            Activations::Ready);
}

TEST(ActivationsFromString, InvalidStringThrows) {
  EXPECT_THROW(Activation::convertActivationsFromString("xyz.invalid.string"),
               sdbusplus::exception::InvalidEnumString);
}

// ── RequestedActivations enum → string ───────────────────────────────────────

TEST(RequestedActivationsToString, None) {
  EXPECT_EQ(
      Activation::convertRequestedActivationsToString(
          RequestedActivations::None),
      "xyz.openbmc_project.Software.Activation.RequestedActivations.None");
}

TEST(RequestedActivationsToString, Active) {
  EXPECT_EQ(
      Activation::convertRequestedActivationsToString(
          RequestedActivations::Active),
      "xyz.openbmc_project.Software.Activation.RequestedActivations.Active");
}

TEST(RequestedActivationsToString, StandbySpare) {
  EXPECT_EQ(Activation::convertRequestedActivationsToString(
                RequestedActivations::StandbySpare),
            "xyz.openbmc_project.Software.Activation.RequestedActivations."
            "StandbySpare");
}

// ── RequestedActivations string → enum ───────────────────────────────────────

TEST(RequestedActivationsFromString, None) {
  EXPECT_EQ(
      Activation::convertRequestedActivationsFromString(
          "xyz.openbmc_project.Software.Activation.RequestedActivations.None"),
      RequestedActivations::None);
}

TEST(RequestedActivationsFromString, InvalidStringThrows) {
  EXPECT_THROW(Activation::convertRequestedActivationsFromString("invalid"),
               sdbusplus::exception::InvalidEnumString);
}

// ── convertStringTo (noexcept variant) ───────────────────────────────────────

TEST(ActivationsConvertStringTo, ValidReturnsValue) {
  auto result = Activation::convertStringToActivations(
      "xyz.openbmc_project.Software.Activation.Activations.Active");
  ASSERT_TRUE(result.has_value());
  EXPECT_EQ(*result, Activations::Active);
}

TEST(ActivationsConvertStringTo, InvalidReturnsNullopt) {
  auto result = Activation::convertStringToActivations("xyz.invalid");
  EXPECT_FALSE(result.has_value());
}

// ── property names
// ────────────────────────────────────────────────────────────

TEST(ActivationPropertyNames, Activation) {
  EXPECT_STREQ(Activation::property_names::activation, "Activation");
}

TEST(ActivationPropertyNames, RequestedActivation) {
  EXPECT_STREQ(Activation::property_names::requested_activation,
               "RequestedActivation");
}

// ── unpack
// ────────────────────────────────────────────────────────────────────

TEST(ActivationPropertiesUnpack, ValidMap_UnpacksBothProperties) {
  std::map<std::string, Activation::PropertiesVariant> props;
  props["Activation"] = Activations::Active;
  props["RequestedActivation"] = RequestedActivations::None;

  Activation::properties_t result{};
  ASSERT_NO_THROW(result = Activation::properties_t::unpack(props));
  EXPECT_EQ(result.activation, Activations::Active);
  EXPECT_EQ(result.requested_activation, RequestedActivations::None);
}

TEST(ActivationPropertiesUnpack, EmptyMapReturnsDefaults) {
  std::map<std::string, Activation::PropertiesVariant> props;
  Activation::properties_t result{};
  ASSERT_NO_THROW(result = Activation::properties_t::unpack(props));
}

} // namespace
