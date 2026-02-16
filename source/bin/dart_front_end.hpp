#pragma once

#include "dart_api.hpp"
#include "globals.hpp"

#include <mutex>
#include <string>

namespace dart {
namespace bin {
/**
Represents the Dart Front-End configuration.
*/
class DartFrontEnd {
private:
    static inline std::mutex mutex{};

public:
    /**
    Returns a single instance of the 'DartFrontEnd' as a singleton, creating it
    if it doesn't already exist.
    */
    static DartFrontEnd* instance();

    DartFrontEnd() = default;

private:
    bool useDartFrontEnd{false};
    bool useIncrementalCompiler{false};
    std::string frontEndFilename{};
    api::KernelCompilationVerbosityLevel verbosity{
        api::KernelCompilationVerbosityLevel::ALL};
    std::uint8_t* applicationKernelBuffer{nullptr};
    std::intptr_t applicationKernelBufferSize{0};

    DISABLE_COPY_ASSIGN(DartFrontEnd);
};
} // namespace bin
} // namespace dart