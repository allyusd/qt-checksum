cmake_minimum_required (VERSION 2.8.12)
project (Qt-Websocket)

find_package(Qt5 COMPONENTS Core Network WebSockets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SOURCE_DIR src)

include_directories(${SOURCE_DIR})

FILE(GLOB_RECURSE ALL_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
  src/*.h src/*.cpp src/*.ui src/*.qrc)

add_library(${PROJECT_NAME}Lib ${ALL_FILES})

# for the VS folders to mirror the folder structure of your project
foreach(FILE ${ALL_FILES}) 
  get_filename_component(PARENT_DIR "${FILE}" PATH)

  # skip src or include
  #string(REGEX REPLACE "(\\./)?(src|include)/?" "" GROUP "${PARENT_DIR}")

  # skip ../
  string(REPLACE "../" "" GROUP "${PARENT_DIR}")

  # changes /'s to \\'s
  string(REPLACE "/" "\\" GROUP "${GROUP}")

  source_group("${GROUP}" FILES "${FILE}")
endforeach()

# add automoc file and autorcc file to group
source_group("zzzautofile" REGULAR_EXPRESSION "(.*_automoc\\.cpp|qrc_.*)")

target_link_libraries(${PROJECT_NAME}Lib Qt5::Network Qt5::WebSockets)

add_executable(${PROJECT_NAME} ${SOURCE_DIR}/main.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}Lib)
