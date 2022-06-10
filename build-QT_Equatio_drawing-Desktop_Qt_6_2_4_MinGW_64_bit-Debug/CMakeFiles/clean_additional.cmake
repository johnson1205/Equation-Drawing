# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QT_Equatio_drawing_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QT_Equatio_drawing_autogen.dir\\ParseCache.txt"
  "QT_Equatio_drawing_autogen"
  )
endif()
