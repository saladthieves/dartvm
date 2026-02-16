#pragma once

#include "dart_front_end.hpp"
#include "dart_utils.hpp"

namespace dart {
namespace bin {
class Options {
public:
    /**
    Attempts to parse the provided arguments and returns 'true' if parsing was
    successful, or 'false' if not.
    // TODO(complete-docs)
    */
    static bool parseArguments(int argc, const char* argv[],
                               CommandLineOptions& vmOptions,
                               CommandLineOptions& dartOptions,
                               bool parseDartVmOptions, bool vmRunAppSnapshot,
                               std::string_view scriptName,
                               bool& printFlagsSeen);

    static void setDartFrontEnd(DartFrontEnd* ptr) { dartFrontEnd = ptr; }

private:
    static inline DartFrontEnd* dartFrontEnd{nullptr};
};
} // namespace bin
} // namespace dart