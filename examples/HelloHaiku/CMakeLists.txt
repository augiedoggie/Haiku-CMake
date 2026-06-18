cmake_minimum_required(VERSION 3.16)

project(HelloHaiku CXX)

# Point at the UseHaiku.cmake module two directories up (the root of this
# repo). A real project would instead vendor UseHaiku.cmake into its own
# CMakeModules/ directory and point CMAKE_MODULE_PATH at that instead.
get_filename_component(HAIKU_CMAKE_MODULE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../.." ABSOLUTE)
list(APPEND CMAKE_MODULE_PATH "${HAIKU_CMAKE_MODULE_DIR}")

include(UseHaiku)

haiku_add_executable(HelloHaiku
	Source/HelloHaiku.cpp
	Source/HelloHaiku.rdef
)

target_link_libraries(HelloHaiku be)

# demonstrates haiku_add_target_attr(): sets an arbitrary BFS string
# attribute on the built binary as a post-build step
haiku_add_target_attr(HelloHaiku "Example:Greeting" "Hello from UseHaiku.cmake")

install(TARGETS HelloHaiku RUNTIME DESTINATION apps)
