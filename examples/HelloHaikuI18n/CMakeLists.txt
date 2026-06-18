cmake_minimum_required(VERSION 3.16)

project(HelloHaikuI18n CXX)

# Point at the UseHaiku.cmake module two directories up (the root of this
# repo). A real project would instead vendor UseHaiku.cmake into its own
# CMakeModules/ directory and point CMAKE_MODULE_PATH at that instead.
get_filename_component(HAIKU_CMAKE_MODULE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../.." ABSOLUTE)
list(APPEND CMAKE_MODULE_PATH "${HAIKU_CMAKE_MODULE_DIR}")

# must be set before include(UseHaiku) -- it gates the catkeys/catalogs/
# bindcatalogs/catalogsinstall top-level targets created by the module
set(HAIKU_ENABLE_I18N ON CACHE BOOL "")

include(UseHaiku)

haiku_add_executable(HelloHaikuI18n
	Source/HelloHaikuI18n.cpp
	Source/HelloHaikuI18n.rdef
)

target_link_libraries(HelloHaikuI18n be localestub)

set(HelloHaikuI18n-APP_MIME_SIG "application/x-vnd.Haiku-CMake-HelloHaikuI18n")
set(HelloHaikuI18n-LOCALES en fr)

haiku_add_i18n(HelloHaikuI18n)

install(TARGETS HelloHaikuI18n RUNTIME DESTINATION apps)
