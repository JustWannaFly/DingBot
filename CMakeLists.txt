cmake_minimum_required(VERSION 3.15)

project(DingBot VERSION 1.0)

add_subdirectory(libs/DPP)

add_executable(${PROJECT_NAME}
    src/main.cpp
 "src/Commands.cpp"  "src/commands/Help.cpp"  "headers/commands/ACommand.h" "headers/commands/Help.h" "src/commands/ACommand.cpp" "headers/commands/Ding.h" "src/commands/Ding.cpp" "headers/commands/Poll.h" "src/commands/Poll.cpp")

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