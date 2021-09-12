cmake_minimum_required(VERSION 3.15)

project(DingBot VERSION 1.0)

add_subdirectory(libs/DPP)

add_executable(${PROJECT_NAME}
    src/main.cpp
 "src/commands.cpp"  "src/commands/help.cpp"  "headers/commands/ACommand.h" "headers/commands/help.h" "src/commands/ACommand.cpp")

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