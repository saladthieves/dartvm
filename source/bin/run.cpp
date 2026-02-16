#include "run.hpp"
#include "console.hpp"
#include "dart_front_end.hpp"
#include "dart_utils.hpp"
#include "error_exit.hpp"
#include "log.hpp"
#include "options.hpp"
#include "platform.hpp"

#include <string_view>

namespace dart::bin {
void run(int argc, const char* argv[]) {
    std::string_view scriptName{};

    // Perform platform initialization
    if (!Platform::initialize()) {
        utils::log::e("Platform initialization failed.");
        Platform::terminate(ErrorCode::UNHANDLED_ERROR);
    }

    // Save the console state so that it can be restored at shutdown.
    Console::saveConfig();

    // Processing of some command-line flags directly manipulates the Dart FE.
    Options::setDartFrontEnd(DartFrontEnd::instance());

    constexpr int EXTRA_VM_ARGUMENTS = 10;
    CommandLineOptions vmOptions{argc + EXTRA_VM_ARGUMENTS};
    CommandLineOptions dartOptions{argc + EXTRA_VM_ARGUMENTS};
    bool printFlagsSeen{false};

    // Use larger new gen semi space size and faster new gen growth factor
    vmOptions.addArgument("--new_gen_semi_max_size=32");
    vmOptions.addArgument("--new_gen_growth_factor=4");

    utils::log::d("dart::bin::run(argc, const char**) = DONE");

    auto parseArguments = [&](int argc, const char* argv[],
                              bool parseDartVmOptions) {
        const bool successful = Options::parseArguments(
            argc, argv, vmOptions, dartOptions, parseDartVmOptions,
            vmRunAppSnapshot, scriptName, printFlagsSeen);
    };
}
} // namespace dart::bin