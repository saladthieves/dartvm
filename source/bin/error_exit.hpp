#pragma once

#include <cstdint>

namespace dart {
namespace bin {
enum class ErrorCode : std::uint8_t {
    // Represents an internal Dart front-end error.
    DART_FRONTEND_ERROR = 252,

    // Represents an API error.
    API_ERROR,

    // Represents a compilation error.
    COMPILATION_ERROR,

    // Represents an unhandled error that's not a compilation error.
    UNHANDLED_ERROR,
};
} // namespace bin
} // namespace dart