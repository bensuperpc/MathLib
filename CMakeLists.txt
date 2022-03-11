cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    MathLib
    VERSION 0.1.0
    DESCRIPTION "MathLib, by Bensuperpc"
    HOMEPAGE_URL "https://github.com/bensuperpc"
    LANGUAGES NONE
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(MathLib_MathLib INTERFACE)
add_library(MathLib::MathLib ALIAS MathLib_MathLib)

set_property(
    TARGET MathLib_MathLib PROPERTY
    EXPORT_NAME MathLib
)

target_include_directories(
    MathLib_MathLib ${warning_guard}
    INTERFACE
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
)

target_compile_features(MathLib_MathLib INTERFACE cxx_std_17)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Examples ----

if(PROJECT_IS_TOP_LEVEL)
  option(BUILD_EXAMPLES "Build examples tree." "${MathLib_DEVELOPER_MODE}")
  if(BUILD_EXAMPLES)
    add_subdirectory(example)
  endif()
endif()

# ---- Developer mode ----

if(NOT MathLib_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of MathLib"
  )
endif()

include(cmake/dev-mode.cmake)
