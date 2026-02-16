#pragma once

#include "globals.hpp"

#include <memory>

namespace dart {
template <typename T>
/**
Manages a single instance of 'T' stored on the heap.
*/
class Singleton {
public:
    /**
    Returns a pointer to the single instance of 'T', and creates it if it does
    not exist already.

    The instance 'T' must be default constructible.
    */
    static T* instance() {
        if (!object) {
            object = std::make_unique<T>();
        }

        return object.get();
    }

private:
    static inline std::unique_ptr<T> object{nullptr};

    DISABLE_COPY_ASSIGN(Singleton);
};
} // namespace dart