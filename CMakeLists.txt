project(moteur_onea)
cmake_minimum_required(VERSION 2.8)

add_definitions(-Wall -g)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 1)

aux_source_directory(. SRC_LIST)
aux_source_directory(src SRC_LIST)
aux_source_directory(src/Physique SRC_LIST)
aux_source_directory(src/Animation SRC_LIST)
aux_source_directory(src/Evenement SRC_LIST)

add_executable(${PROJECT_NAME} ${SRC_LIST})

include_directories(include)
link_directories(lib)
target_link_libraries(${PROJECT_NAME}
    sfml-graphics sfml-window sfml-system tinyxml GL)
