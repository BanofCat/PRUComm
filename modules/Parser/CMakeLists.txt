
set(temp "")
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src temp)
set(SrcDir "${SrcDir};${temp}" CACHE INTERNAL "src dir")
set(IncDir "${IncDir};${CMAKE_CURRENT_SOURCE_DIR}/include" CACHE INTERNAL "include dir")
# message(STATUS "::: ${IncDir}")