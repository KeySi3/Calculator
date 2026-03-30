# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\CalculatorApp_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\CalculatorApp_autogen.dir\\ParseCache.txt"
  "CalculatorApp_autogen"
  )
endif()
