cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    mathlib
    VERSION 0.1.0
    DESCRIPTION "MathLib, by Bensuperpc"
    HOMEPAGE_URL "https://github.com/bensuperpc"
    LANGUAGES NONE
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(mathlib_mathlib INTERFACE)
add_library(mathlib::mathlib ALIAS mathlib_mathlib)

set_property(
    TARGET mathlib_mathlib PROPERTY
    EXPORT_NAME mathlib
)

target_include_directories(
    mathlib_mathlib ${warning_guard}
    INTERFACE
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
)

# target_compile_features(mathlib_mathlib INTERFACE cxx_std_17)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Examples ----

if(PROJECT_IS_TOP_LEVEL)
  option(BUILD_EXAMPLES "Build examples tree." "${mathlib_DEVELOPER_MODE}")
  if(BUILD_EXAMPLES)
    add_subdirectory(example)
  endif()
endif()

# ---- Developer mode ----

if(NOT mathlib_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of mathlib"
  )
endif()

include(cmake/dev-mode.cmake)
