file(STRINGS "${CMAKE_CURRENT_LIST_DIR}/../include/dout/version.hpp" dout_VERSION_MAJOR_HPP REGEX "#define DOUT_VERSION_MAJOR ")
file(STRINGS "${CMAKE_CURRENT_LIST_DIR}/../include/dout/version.hpp"  dout_VERSION_MINOR_HPP REGEX "#define DOUT_VERSION_MINOR ")
file(STRINGS "${CMAKE_CURRENT_LIST_DIR}/../include/dout/version.hpp"  dout_VERSION_PATCH_HPP REGEX "#define DOUT_VERSION_PATCH ")

string(REGEX MATCH "([0-9]+)" dout_VERSION_MAJOR  ${dout_VERSION_MAJOR_HPP})
string(REGEX MATCH "([0-9]+)" dout_VERSION_MINOR  ${dout_VERSION_MINOR_HPP})
string(REGEX MATCH "([0-9]+)" dout_VERSION_PATCH  ${dout_VERSION_PATCH_HPP})

set(PACKAGE_VERSION "${dout_VERSION_MAJOR}.${dout_VERSION_MINOR}.${dout_VERSION_PATCH}")

# Check whether the requested PACKAGE_FIND_VERSION is exactly the one requested
if("${PACKAGE_VERSION}" EQUAL "${PACKAGE_FIND_VERSION}")
    set(PACKAGE_VERSION_EXACT TRUE)
else()
    set(PACKAGE_VERSION_EXACT FALSE)
endif()

# Check whether the requested PACKAGE_FIND_VERSION is compatible
if("${PACKAGE_VERSION}" VERSION_LESS "${PACKAGE_FIND_VERSION}")
    set(PACKAGE_VERSION_COMPATIBLE FALSE)
else()
    set(PACKAGE_VERSION_COMPATIBLE TRUE)
    if ("${PACKAGE_VERSION}" VERSION_EQUAL "${PACKAGE_FIND_VERSION}")
        set(PACKAGE_VERSION_EXACT TRUE)
    endif()
endif()
