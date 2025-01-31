/*
 *  Copyright (c) 2004-present, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */

#include "fboss/agent/hw/test/HwSwitchEnsembleFactory.h"

#include "fboss/agent/hw/sai/hw_test/SaiSwitchEnsemble.h"

#include <memory>

namespace facebook::fboss {

std::unique_ptr<HwSwitchEnsemble> createHwEnsemble(
    const HwSwitchEnsemble::Features& featuresDesired,
    const HwSwitchEnsemble::HwSwitchEnsembleInitInfo& info) {
  auto ensemble = std::make_unique<SaiSwitchEnsemble>(featuresDesired);
  ensemble->init(info);
  return ensemble;
}

} // namespace facebook::fboss
