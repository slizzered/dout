project("dout_dev")
cmake_minimum_required(VERSION 3.0.2)

find_package(dout 1.0 REQUIRED PATHS ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

add_executable(example EXCLUDE_FROM_ALL examples/example1.cpp)

install(
  DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/dout"
  DESTINATION "lib"
  )

install(
  DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/cmake"
  DESTINATION "lib/dout"
  )
