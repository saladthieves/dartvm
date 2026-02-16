#include "dart_front_end.hpp"
#include "singleton.hpp"

namespace dart::bin {
DartFrontEnd* DartFrontEnd::instance() {
    std::lock_guard<std::mutex> guard{mutex};
    return Singleton<DartFrontEnd>::instance();
}
} // namespace dart::bin