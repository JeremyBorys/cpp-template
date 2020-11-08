
cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 17)

project(Template
  VERSION 0.1.0
  DESCRIPTION "Simple template of a main application using a library"
  HOMEPAGE_URL "https://github.com/JeremyBorys/cpp-template"
  LANGUAGES CXX
)

# Download automatically, you can also just copy the conan.cmake file
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
   message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
   file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.15/conan.cmake"
                 "${CMAKE_BINARY_DIR}/conan.cmake" 
                 TLS_VERIFY ON)
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_run(
  REQUIRES
    fmt/7.1.2
  BASIC_SETUP
  BUILD missing
)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

set(ClangOrGCC $<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>)

add_compile_options(
    $<$<CXX_COMPILER_ID:MSVC>:/W4>
    $<$<CXX_COMPILER_ID:MSVC>:/WX>
    $<${ClangOrGCC}:-Wall>
    $<${ClangOrGCC}:-Wextra>
    $<${ClangOrGCC}:-pedantic>
    $<${ClangOrGCC}:-Werror>
)

add_subdirectory(app)
add_subdirectory(lib)
add_subdirectory(doc)

