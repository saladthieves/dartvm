#pragma once

#include <cstdint>
#include <iostream>
#include <print>
#include <string_view>

namespace dart {
namespace utils {
namespace log {

namespace {
enum class LogLevel : std::uint8_t {
    VERBOSE = 1,
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    FATAL,
    RAW,
};

/**
Returns a textual / string representation of the provided 'level' value.
*/
constexpr inline std::string_view formatLogLevel(const LogLevel& level) {
    switch (level) {
        case LogLevel::VERBOSE: return "V";
        case LogLevel::DEBUG:   return "D";
        case LogLevel::INFO:    return "I";
        case LogLevel::WARNING: return "W";
        case LogLevel::ERROR:   return "E";
        case LogLevel::FATAL:   return "F";
        default:                return "";
    }
}

/**
Outputs the formatted content on the provided log 'level'.
*/
template <typename... T>
constexpr inline void out(LogLevel level, std::format_string<T...> str,
                          T&&... args) {
    using enum LogLevel;
    const auto isError = level == WARNING || level == ERROR || level == FATAL;
    auto& stream = isError ? std::cerr : std::cout;
    if (level == RAW) {
        std::println(stream, str, std::forward<T>(args)...);
    } else {
        auto message = std::format(str, std::forward<T>(args)...);
        std::println(stream, "{}: {}", formatLogLevel(level), message);
    }
}

} // namespace

/**
Formats and prints the provided content with the 'VERBOSE' level.
*/
template <typename... T>
constexpr inline void v(std::format_string<T...> str = "", T&&... args) {
    out(LogLevel::VERBOSE, str, std::forward<T>(args)...);
}

/**
Formats and prints the provided content with the 'DEBUG' level.
*/
template <typename... T>
constexpr inline void d(std::format_string<T...> str = "", T&&... args) {
    out(LogLevel::DEBUG, str, std::forward<T>(args)...);
}

/**
Formats and prints the provided content with the 'INFO' level.
*/
template <typename... T>
constexpr inline void i(std::format_string<T...> str = "", T&&... args) {
    out(LogLevel::INFO, str, std::forward<T>(args)...);
}

/**
Formats and prints the provided content with the 'WARNING' level.
*/
template <typename... T>
constexpr inline void w(std::format_string<T...> str = "", T&&... args) {
    out(LogLevel::WARNING, str, std::forward<T>(args)...);
}

/**
Formats and prints the provided content with the 'ERROR' level.
*/
template <typename... T>
constexpr inline void e(std::format_string<T...> str = "", T&&... args) {
    out(LogLevel::ERROR, str, std::forward<T>(args)...);
}

/**
Formats and prints the provided content with the 'FATAL' level.
*/
template <typename... T>
constexpr inline void f(std::format_string<T...> str = "", T&&... args) {
    out(LogLevel::FATAL, str, std::forward<T>(args)...);
}
} // namespace log
} // namespace utils
} // namespace dart