#pragma once

#include "globals.hpp"
#include <string>
#include <vector>

namespace dart {
namespace bin {
/**
Handler and processor for command-line options.
*/
class CommandLineOptions {
public:
    explicit CommandLineOptions(int maxCount);

    void addArgument(std::string_view argument);

private:
    std::vector<std::string> arguments{};
    int maxCount{0};

    DISABLE_COPY_ASSIGN(CommandLineOptions);
};
} // namespace bin
} // namespace dart