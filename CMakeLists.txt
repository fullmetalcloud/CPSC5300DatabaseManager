cmake_minimum_required(VERSION 3.7)
project(Milestone2)

set(CMAKE_CXX_STANDARD 11)

include_directories("/usr/local/BerkeleyDB.6.2/include" )
include_directories("${PROJECT_SOURCE_DIR}/sql-parser/src")

set(SOURCE_FILES main.cpp)
set(HEAP_FILES heap_storage.cpp)
set(CFLAGS -Wall -DHAVE_CXX_STDHEADERS -D_GNU_SOURCE -D_REENTRANT -O3 -c)

add_library(HLIB ${HEAP_FILES})

add_executable(Milestone2 ${SOURCE_FILES})
target_link_libraries(Milestone2 HLIB "db_cxx" "SQLParser")
add_definitions(${CFLAGS})