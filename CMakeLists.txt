#####################################################################
#CMakeLists.txt configuration for deep learning source file and application
#####################################################################
PROJECT(Josephus)

CMAKE_MINIMUM_REQUIRED( VERSION 2.6.4 )
CMAKE_POLICY(SET CMP0003 NEW)

SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_C_FLAGS   "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb -DDEBUG -Wunused-variable")
#SET(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb -DDEBUG -Wunused-variable")
#SET(CMAKE_C_FLAGS   "$ENV{CXXFLAGS} -O0 -Wall -Wunused-variable")
#SET(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -O0 -Wall -Wunused-variable")

#####################################################################
## set app source file path
#####################################################################
SET(SRCS
    ./josephus.cpp
)

#####################################################################
## set app header file path
#####################################################################		 
SET(HEADER_LIST 
)
 
#####################################################################
## set CMAKE_MODULE_PATH search FindXXX.cmake
#####################################################################
MESSAGE(STATUS "project source path:" ${PROJECT_SOURCE_DIR})
SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeConfig)

#####################################################################
#          declare the target
#####################################################################
ADD_EXECUTABLE(josephus  ${SRCS})


#####################################################################
#          target include head files
#####################################################################
INCLUDE_DIRECTORIES(${HEADER_LIST})
