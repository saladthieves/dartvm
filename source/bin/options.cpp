#include "options.hpp"

namespace dart::bin {
bool Options::parseArguments(int argc, const char* argv[],
                             CommandLineOptions& vmOptions,
                             CommandLineOptions& dartOptions,
                             bool parseDartVmOptions, bool vmRunAppSnapshot,
                             std::string_view scriptName,
                             bool& printFlagsSeen) {

    return false;
}
} // namespace dart::bin