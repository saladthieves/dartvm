#pragma once

#include <cstdint>

namespace dart {
namespace api {
/**
The kernel compilation verbosity level, used by 'DartFrontEnd'.
 */
enum class KernelCompilationVerbosityLevel : std::uint8_t {
    ERROR = 0,
    WARNING,
    INFO,
    ALL,
};
} // namespace api
} // namespace dart