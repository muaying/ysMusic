cmake_minimum_required(VERSION 3.20)
project(ysMusic)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

#添加 QT 库  需要自行更改
set(CMAKE_PREFIX_PATH "D:/Software/SDK/QT/6.2.2/mingw_64")
# 导入 QT包
find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)
# 编译文件目录
file(GLOB SRC src/*.cpp)
file(GLOB HEAD head/*.h)
file(GLOB UI ui/*.h)
#添加资源文件
qt6_add_resources(QRC Resources.qrc)
# 头文件目录
include_directories(head)
include_directories(ui)
add_executable(${PROJECT_NAME}
        ${UI} ${QRC}
        ${SRC} ${HEAD} icon.rc)
target_link_libraries(${PROJECT_NAME}
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

if (WIN32)
    set(DEBUG_SUFFIX)
    #    if (CMAKE_BUILD_TYPE MATCHES "Debug")
    #        set(DEBUG_SUFFIX "d")
    #    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
