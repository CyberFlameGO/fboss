/*
 *  Copyright (c) 2004-present, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */
#include "fboss/agent/hw/switch_asics/HwAsic.h"

DEFINE_int32(acl_gid, -1, "Content aware processor group ID for ACLs");

namespace {
constexpr auto kDefaultACLGroupID = 128;
constexpr auto kDefaultDropEgressID = 100000;
enum IntAsicType ASIC_TYPE_LIST;
std::vector<IntAsicType> getAsicTypeIntList() {
  return ASIC_TYPE_LIST;
}
} // namespace

namespace facebook::fboss {

/*
 * Default Content Aware Processor group ID for ACLs
 */
int HwAsic::getDefaultACLGroupID() const {
  if (FLAGS_acl_gid > 0) {
    return FLAGS_acl_gid;
  } else {
    return kDefaultACLGroupID;
  }
}

/*
 * station entry id for vlan interface
 */
int HwAsic::getStationID(int intfID) const {
  return intfID;
}

int HwAsic::getDefaultDropEgressID() const {
  return kDefaultDropEgressID;
}

std::vector<HwAsic::AsicType> HwAsic::getAllHwAsicList() {
  std::vector<HwAsic::AsicType> result{};
  for (int asic : getAsicTypeIntList()) {
    HwAsic::AsicType asicType = static_cast<HwAsic::AsicType>(asic);
    result.push_back(asicType);
  }
  return result;
}
} // namespace facebook::fboss
