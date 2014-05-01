project(TEMPLATE_CPP)
cmake_minimum_required(VERSION 2.8.5)



###############################################################################
# Using Clang is awesome
# code based on http://stackoverflow.com/q/7031126
###############################################################################
option(USE_CLANG "build application with clang" ON) # OFF is the default
if(USE_CLANG)
  SET (CMAKE_CXX_COMPILER             "/usr/bin/clang++")
  SET (CMAKE_CXX_FLAGS                "-Wall -Wextra -O3 -std=c++0x")
else(USE_CLANG)
  SET (CMAKE_CXX_COMPILER             "/usr/bin/g++")
  SET (CMAKE_CXX_FLAGS                "-Wall -Wextra -O3 -std=c++0x")
endif(USE_CLANG)



###############################################################################
# Headers
###############################################################################
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)



###############################################################################
# Boost
###############################################################################
find_package(Boost 1.48.0 REQUIRED)
include_directories(SYSTEM ${Boost_INCLUDE_DIRS})
set(LIBS ${LIBS} ${Boost_LIBRARIES})




###############################################################################
# Build executables
###############################################################################
add_executable(Main src/main.cc)




###############################################################################
# Adding linker behaviour
###############################################################################
# add the libraries (Boost...) to this executable
target_link_libraries(Main ${LIBS})
