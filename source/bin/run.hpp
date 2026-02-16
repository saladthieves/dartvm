#pragma once

namespace dart {
namespace bin {
namespace {
// TODO(docs)
static bool vmRunAppSnapshot{false};
} // namespace

/**
Run the Dart VM implementation along with the provided 'argc' count and 'argv'
command line options.
*/
void run(int argc, const char* argv[]);
} // namespace bin
} // namespace dart