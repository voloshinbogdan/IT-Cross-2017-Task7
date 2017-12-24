cmake_minimum_required(VERSION 3.2)

set (CMAKE_INCLUDE_CURRENT_DIR ON)
set (CMAKE_AUTOMOC ON)
set (CMAKE_AUTOUIC ON)
set (CMAKE_CXX_STANDARD 11)

set( qt_distro /opt/anaconda3)

# Add the path to the Qt installation/files
set(CMAKE_PREFIX_PATH ${qt_distro})

project(Sky)

find_package(Qt5Core REQUIRED Widgets Qml Quick Gui)
find_package(Qt5Quick)
find_package(Qt5Qml)
find_package(Qt5Gui)
find_package(Qt5Widgets)

qt5_add_resources(QRC_WRAPPERS qml.qrc)

add_executable(Sky WIN32 main.cpp ${QRC_WRAPPERS})

target_link_libraries(Sky Qt5::Qml Qt5::Quick Qt5::Widgets Qt5::Gui)

#add_custom_command(TARGET Sky POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_PREFIX_PATH}/bin $<TARGET_FILE_DIR:Sky>)
#add_custom_command(TARGET POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_PREFIX_PATH}/plugins $<TARGET_FILE_DIR:Sky>)
#add_custom_command(TARGET Sky POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_PREFIX_PATH}/qml $<TARGET_FILE_DIR:Sky>)
