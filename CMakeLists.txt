cmake_minimum_required(VERSION 3.10)

project(n-body LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)
find_package(OpenGL REQUIRED)

# qt-section-widget
SET(QT_COLLAPSIBLE_SECTION qt-collapsible-section)
add_subdirectory(${QT_COLLAPSIBLE_SECTION})

# source files
file(GLOB_RECURSE HDRS "src/*.hh" "src/*.h")
file(GLOB_RECURSE SRCS "src/*.cpp" "src/*.c")

# other files
set(OTHER_FILES "README.md")

add_executable(${PROJECT_NAME} ${SRCS} ${HDRS} ${QML} ${OTHER_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/src)
target_compile_options(${PROJECT_NAME} PUBLIC "-O3")
target_compile_options(${PROJECT_NAME} PUBLIC "-g")
target_compile_options(${PROJECT_NAME} PUBLIC "-save-temps")

if (WIN32)
    set_property(TARGET ${PROJECT_NAME} PROPERTY WIN32_EXECUTABLE true)
endif (WIN32)

target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Widgets)
target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL)

target_include_directories(${PROJECT_NAME} PRIVATE ${QT_COLLAPSIBLE_SECTION})
target_link_libraries(${PROJECT_NAME} PRIVATE ${QT_COLLAPSIBLE_SECTION})

target_compile_options(${PROJECT_NAME} PRIVATE -fstandalone-debug)
