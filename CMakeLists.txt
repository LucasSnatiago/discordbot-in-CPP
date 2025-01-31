cmake_minimum_required(VERSION 3.22)

project(discord-bot VERSION 0.1 DESCRIPTION "Simple Discord Bot in CPP")

set(CMAKE_CXX_STANDARD 23)

add_executable(${PROJECT_NAME}
    src/main.cpp
    # src/**/*.c*
)

add_subdirectory(third_party)

target_link_libraries(${PROJECT_NAME} fmt::fmt dpp)

target_link_libraries(${PROJECT_NAME}
    ${DPP_LIBRARIES}
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${DPP_INCLUDE_DIR}
)

# set_target_properties(${PROJECT_NAME} PROPERTIES
#     CXX_STANDARD 21
#     CXX_STANDARD_REQUIRED ON
# )
