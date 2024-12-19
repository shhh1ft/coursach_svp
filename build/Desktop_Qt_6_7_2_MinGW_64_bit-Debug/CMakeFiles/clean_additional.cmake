# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\char_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\char_autogen.dir\\ParseCache.txt"
  "char_autogen"
  )
endif()
