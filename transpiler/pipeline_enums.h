// Copyright 2021 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef FULLY_HOMOMORPHIC_ENCRYPTION_TRANSPILER_PIPELINE_ENUMS_H_
#define FULLY_HOMOMORPHIC_ENCRYPTION_TRANSPILER_PIPELINE_ENUMS_H_

#include <string>

#include "absl/strings/match.h"
#include "absl/strings/string_view.h"

namespace fully_homomorphic_encryption::transpiler {

enum class Optimizer {
  kXLS,
  kYosys,
};

inline bool AbslParseFlag(absl::string_view text, Optimizer* out,
                          std::string* error) {
  if (absl::EqualsIgnoreCase(text, "xls")) {
    *out = Optimizer::kXLS;
    return true;
  }
  if (absl::EqualsIgnoreCase(text, "yosys")) {
    *out = Optimizer::kYosys;
    return true;
  }
  *error = "Unrecognized optimizer.";
  return false;
}
inline std::string AbslUnparseFlag(Optimizer in) {
  switch (in) {
    case Optimizer::kXLS:
      return "xls";
    case Optimizer::kYosys:
      return "yosys";
  }
  return "unknown";
}

enum class Backend {
  kTFHE,
  kPALISADE,
  kInterpretedTFHE,
  kInterpretedPALISADE,
  kCleartext,
};

inline bool AbslParseFlag(absl::string_view text, Backend* out,
                          std::string* error) {
  if (absl::EqualsIgnoreCase(text, "tfhe")) {
    *out = Backend::kTFHE;
    return true;
  }
  if (absl::EqualsIgnoreCase(text, "palisade")) {
    *out = Backend::kPALISADE;
    return true;
  }
  if (absl::EqualsIgnoreCase(text, "interpreted_tfhe")) {
    *out = Backend::kInterpretedTFHE;
    return true;
  }
  if (absl::EqualsIgnoreCase(text, "interpreted_palisade")) {
    *out = Backend::kInterpretedPALISADE;
    return true;
  }
  if (absl::EqualsIgnoreCase(text, "cleartext")) {
    *out = Backend::kCleartext;
    return true;
  }
  *error = "Unrecognized backend.";
  return false;
}
inline std::string AbslUnparseFlag(Backend in) {
  switch (in) {
    case Backend::kTFHE:
      return "tfhe";
    case Backend::kPALISADE:
      return "palisade";
    case Backend::kInterpretedTFHE:
      return "interpreted_tfhe";
    case Backend::kInterpretedPALISADE:
      return "interpreted_palisade";
    case Backend::kCleartext:
      return "cleartext";
  }
  return "unknown";
}

}  // namespace fully_homomorphic_encryption::transpiler

#endif  // FULLY_HOMOMORPHIC_ENCRYPTION_TRANSPILER_PIPELINE_ENUMS_H
