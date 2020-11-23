# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/TSP-solver_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/TSP-solver_autogen.dir/ParseCache.txt"
  "TSP-solver_autogen"
  )
endif()
