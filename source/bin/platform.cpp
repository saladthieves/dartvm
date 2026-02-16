#include "platform.hpp"
#include "console.hpp"

#include <_abort.h>
#include <signal.h>
#include <utility>

namespace dart::bin {
bool Platform::initialize() {
    /*
    Turn off the signal handler for SIGPIPE as it causes the process to
    terminate on writing to a closed pipe. Without the signal handler, error
    EPIPE is set instead.
    */
    SigAction action{};
    action.sa_handler = SIG_IGN;
    if (sigaction(SIGPIPE, &action, nullptr) != 0) {
        logE("Setting signal handler failed - SIGPIPE");
        return false;
    }

    /*
    tcsetattr raises SIGTTOU if we try to set console attributes when in
    background, which suspends the process. Ignoring the signal prevents us from
    being suspended and lets us fail gracefully instead.
    */
    sigset_t signalMask{};
    sigemptyset(&signalMask);
    sigaddset(&signalMask, SIGTTOU);
    if (sigprocmask(SIG_BLOCK, &signalMask, nullptr) < 0) {
        logE("setting signal handler failed - SIG_BLOCK");
        return false;
    }

    action.sa_flags = SA_SIGINFO;
    action.sa_sigaction = &segvHandler;
    if (sigemptyset(&action.sa_mask) != 0) {
        logE("sigemptyset() failed.");
        return false;
    }
    if (sigaddset(&action.sa_mask, SIGPROF) != 0) {
        logE("sigaddset() failed.");
        return false;
    }
    if (sigaction(SIGSEGV, &action, nullptr) != 0) {
        logE("sigaction(SIGSEGV) failed.");
        return false;
    }
    if (sigaction(SIGBUS, &action, nullptr) != 0) {
        logE("sigaction(SIGBUS) failed.");
        return false;
    }
    if (sigaction(SIGTRAP, &action, nullptr) != 0) {
        logE("sigaction(SIGTRAP) failed.");
        return false;
    }
    if (sigaction(SIGILL, &action, nullptr) != 0) {
        logE("sigaction(SIGILL) failed.");
        return false;
    }

    return true;
}

[[noreturn]] void Platform::terminate(const ErrorCode& code) {
    Console::restoreConfig();
    exit(std::to_underlying(code));
}

void Platform::segvHandler(int signal, siginfo_t* info, void* context) {
    auto message = std::format("- - - - - - - - - CRASH - - - - - - - - -\n");
    message += std::format("\tsi_signo = {}[{}]\n", strsignal(info->si_signo),
                           info->si_signo);
    message += std::format("\tsi_code={}\n", info->si_code);
    message += std::format("\tsi_addr={:X}\n", (std::size_t)info->si_addr);
    std::abort();
}
} // namespace dart::bin