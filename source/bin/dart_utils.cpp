#include "dart_utils.hpp"
#include "log.hpp"
#include <cstdlib>

namespace dart::bin {
CommandLineOptions::CommandLineOptions(int maxCount) : maxCount{maxCount} {
    arguments.reserve(maxCount);
}

void CommandLineOptions::addArgument(std::string_view argument) {
    if (arguments.size() < maxCount) {
        arguments.emplace_back(argument);
    } else { // We should never get into this situation.
        utils::log::f("CommandLineOptions - max arguments reached: [{}]",
                      maxCount);
        std::abort();
    }
}
} // namespace dart::bin