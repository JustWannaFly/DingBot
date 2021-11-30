cmake_minimum_required(VERSION 3.15)

project(DingBot VERSION 1.0)

add_subdirectory(libs/DPP)

add_executable(${PROJECT_NAME}
    "headers/commands/ACommand.h"
    "headers/commands/Ding.h"
    "headers/commands/Help.h"
    "headers/commands/Poll.h"

    "src/main.cpp"
    "src/Commands.cpp"
    "src/commands/ACommand.cpp"
    "src/commands/Help.cpp" 
    "src/commands/Ding.cpp"
    "src/commands/Poll.cpp"
 "src/commands/Advent.cpp" "headers/commands/Advent.h")

target_link_libraries(${PROJECT_NAME}
    dpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    headers
    libs/DPP/include
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)