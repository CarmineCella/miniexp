cmake_minimum_required(VERSION 3.0)

project(miniexp)

# Source files to be used in the library
set(library_SOURCES
    src/miniexp.cpp
)

#Generate the static library from the library sources
add_library(miniexp STATIC ${library_SOURCES})

target_include_directories(miniexp
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)
