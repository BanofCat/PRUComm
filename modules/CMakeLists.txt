project(PruCom)
cmake_minimum_required(VERSION 2.8)

# set(SrcDir "")
set(SrcDir "" CACHE INTERNAL "src dir")
set(IncDir "" CACHE INTERNAL "include dir")

message(STATUS ">>>11 ${SrcDir}")
add_subdirectory(${PROJECT_SOURCE_DIR}/Communicator)
add_subdirectory(${PROJECT_SOURCE_DIR}/Exception)
add_subdirectory(${PROJECT_SOURCE_DIR}/Parser)
add_subdirectory(${PROJECT_SOURCE_DIR}/Utils)

include_directories(${IncDir})
message(STATUS ">>> ${SrcDir}")
message(STATUS ">>> ${IncDir}")
add_executable(PruCom ${PROJECT_SOURCE_DIR}/Main_test.cpp ${SrcDir})
