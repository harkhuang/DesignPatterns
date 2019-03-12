project(factory)
cmake_minimum_required(VERSION 2.6)


#if(MSVC)
#  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zi")
#else()
#  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
#endif()

# this is debug version
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")

# this is relase version
#SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

include_directories(${CMAKE_SOURCE_DIR} )
aux_source_directory(src ${CMAKE_SOURCE_DIR} )

add_executable(factory main.cpp mydoc.cpp myapp.cpp manager.cpp app.h doc.h ${src})
