#@note   Hikvision Digital Technology Co., Ltd. All Rights Reserved.
#@brief  CMake子目录配置文件
#@author Yaopei
#@date   2015/7/31
#@note   the CMakeLists.txt for src. directory


PROJECT(HMSProxy)
cmake_minimum_required(VERSION 2.8)

IF (WIN32)
    ADD_DEFINITIONS(-DWIN32)
ELSEIF (UNIX)
    #do something related to UNIX
ELSEIF(APPLE)
    #do something related to APPLE
ENDIF (WIN32)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -g -Wall -fPIC -O0")

LINK_DIRECTORIES(
  ${PROJECT_SOURCE_DIR}/../CosApp/lib
)

SET(SRC_SRCS
  ClusterManager.cpp
  main.cpp
)

# shared library
#ADD_LIBRARY(Cluster SHARED ${SRC_SRCS} )

#static library
ADD_LIBRARY(Cluster STATIC ${SRC_SRCS})

ADD_EXECUTABLE(clusterManager main.cpp)
# link library
TARGET_LINK_LIBRARIES(clusterManager  Cluster TraceWorker pthread
                      boost_atomic boost_atomic boost_atomic boost_regex boost_regex boost_thread boost_system)

# clean
SET_TARGET_PROPERTIES(FileOpr PROPERTIES CLEAN_DIRECT_OUTPUT 1)