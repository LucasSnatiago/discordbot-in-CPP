cmake_minimum_required(VERSION 3.22)

project(discord-bot VERSION 0.1 DESCRIPTION "Simple Discord Bot in CPP" LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)

include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(${PROJECT_NAME}
    src/main.cpp
    # src/**/*.c*
)

add_subdirectory(third_party)

target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt dpp)

target_link_libraries(${PROJECT_NAME}
    ${DPP_LIBRARIES}
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${DPP_INCLUDE_DIR}
)

target_compile_options(${PROJECT_NAME} PUBLIC -fexceptions -Wall -pedantic -O3 -march=native)
target_compile_options(fmt PUBLIC -fexceptions -O3 -march=native)
target_compile_options(dpp PUBLIC -fexceptions -O3 -march=native)
