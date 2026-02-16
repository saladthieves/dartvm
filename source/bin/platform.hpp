#pragma once

#include "log.hpp"
#include "error_exit.hpp"

#include <format>

namespace dart {
namespace bin {
class Platform {
    using SigAction = struct sigaction;

public:
    /**
    Performs platform initialization.
    */
    static bool initialize();

    [[noreturn]] static void terminate(const ErrorCode& code);

private:
    /**
    Signal callback for the 'sigaction.sa_sigaction' handler.
    */
    static void segvHandler(int signal, siginfo_t* info, void* context);

    template <typename... T>
    static void logD(std::format_string<T...> str = "", T&&... args) {
        auto message = std::format(str, std::forward<T>(args)...);
        utils::log::d("Platform - {}", message);
    }

    template <typename... T>
    static void logE(std::format_string<T...> str = "", T&&... args) {
        auto message = std::format(str, std::forward<T>(args)...);
        utils::log::e("Platform - {}", message);
    }

    template <typename... T>
    static void logF(std::format_string<T...> str = "", T&&... args) {
        auto message = std::format(str, std::forward<T>(args)...);
        utils::log::f("Platform - {}", message);
    }
};
} // namespace bin
} // namespace dart