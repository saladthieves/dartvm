#pragma once

#include <memory>

namespace dart {
namespace utils {
template <typename T>
class Singleton {
public:
private:
    static inline std::unique_ptr<T> instance{nullptr};

    Singleton() = delete;
    Singleton(const Singleton& other) = delete;
    void operator=(const Singleton& other) = delete;
};
} // namespace utils
} // namespace dart