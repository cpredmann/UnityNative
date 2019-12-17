cmake_minimum_required(VERSION 3.8)

project(UnityNativeBasic)

add_library(
    ${PROJECT_NAME}
    ${PROJECT_NAME}.cpp
)

add_library(
    UnityNativeWrapper
    SHARED
    UnityNativeWrapper.cpp
)

target_link_libraries(
    UnityNativeWrapper
    ${PROJECT_NAME}
)

add_executable(
    ${PROJECT_NAME}_Test
    ${PROJECT_NAME}_Test.cpp
)

target_link_libraries(
    ${PROJECT_NAME}_Test
    ${PROJECT_NAME}
)

install(
    TARGETS
    UnityNativeWrapper
    ${PROJECT_NAME}
    DESTINATION
    ${CMAKE_SOURCE_DIR}/UnityNativeBasic/Assets/Plugins/x86_64
)

install(
    FILES
    UnityNativeWrapper.cs
    DESTINATION
    ${CMAKE_SOURCE_DIR}/UnityNativeBasic/Assets/Plugins/x86_64
)
