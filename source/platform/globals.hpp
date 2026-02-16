#pragma once

namespace dart {
/**
Macro to disable the copy constructor and copy-assignment operators.
*/
#ifndef DISABLE_COPY_ASSIGN
#  define DISABLE_COPY_ASSIGN(TypeName)                                        \
  private:                                                                     \
      TypeName(const TypeName& other) = delete;                                \
      void operator=(const TypeName& other) = delete;
#endif

/**
Macro to disable the implicit default constructor, copy constructor and
assignment operator.
*/
#ifndef DISABLE_CONSTRUCTORS
#  define DISABLE_CONSTRUCTORS(TypeName)                                       \
  private:                                                                     \
      TypeName() = delete;                                                     \
      DISABLE_COPY_ASSIGN(TypeName)
#endif
} // namespace dart