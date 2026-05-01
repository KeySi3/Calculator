cmake_minimum_required(VERSION 3.16)
project(CalculatorApp VERSION 1.0.0 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets Core Gui)

# Добавить исполняемый файл
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/Calculator.cpp
    src/Calculator.h
    src/Calculator.ui
    src/Calculator.qrc
)

set_source_files_properties(Calculator.ui PROPERTIES AUTOUIC ON)

set_source_files_properties(Calculator.qrc PROPERTIES AUTORCC ON)

# Связь с библиотеками Qt5
target_link_libraries(${PROJECT_NAME}
    Qt5::Widgets
    Qt5::Core
    Qt5::Gui
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
    $<TARGET_PROPERTY:Qt5::Core,DEFINITIONS>
)

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /MP /W3)
endif()

# Устанавливаем свойства для отладки и релиза
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin"
)

# Добавить Qt5 DLL в папку с исполняемым файлом
if(WIN32 AND NOT CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:Qt5::Core>
            $<TARGET_FILE_DIR:${PROJECT_NAME}>
        COMMENT "Copying Qt5 Core DLL"
    )
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:Qt5::Widgets>
            $<TARGET_FILE_DIR:${PROJECT_NAME}>
        COMMENT "Copying Qt5 Widgets DLL"
    )
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:Qt5::Widgets>
            $<TARGET_FILE_DIR:${PROJECT_NAME}>
        COMMENT "Copying Qt5 Gui DLL"
    )
endif()


if(WIN32) 
    set_target_properties(${PROJECT_NAME} PROPERTIES
        WIN32_EXECUTABLE TRUE
    )
endif()