/**
 * Copyright 2019 Huawei Technologies Co., Ltd
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef MINDSPORE_CCSRC_SESSION_SESSION_CONTEXT_H
#define MINDSPORE_CCSRC_SESSION_SESSION_CONTEXT_H
#include <vector>
#include <map>
#include <functional>
#include <memory>
#include <utility>
#include <string>

#include "ir/meta_tensor.h"
#include "pipeline/resource.h"
#include "utils/context/ms_context.h"
namespace mindspore {
namespace session {
const char kInputCtrlTensors[] = "input_ctrl_tensors";

class Context : public pipeline::ResourceBase {
 public:
  explicit Context(std::string target = kAscendDevice, uint32_t device_id = 0)
      : target_(std::move(target)), device_id_(device_id) {}
  ~Context() override = default;

  uint32_t device_id() const { return device_id_; }
  static std::shared_ptr<Context> GetInstance();

 private:
  std::string target_;
  uint32_t device_id_;
};
}  // namespace session
}  // namespace mindspore

#endif  // MINDSPORE_CCSRC_SESSION_SESSION_CONTEXT_H
