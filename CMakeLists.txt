cmake_minimum_required(VERSION 3.16)

project(2D-Sandbox VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_DIR ${CMAKE_CURRENT_LIST_DIR}/cmake)
set(INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/include)
set(SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/source)

set(QT_INCLUDE_LIBRARIES Core Quick Concurrent OpenGL Gui)

#CMakeConfig.hpp Constants
add_definitions(-DROOT_PATH_CMAKE=${CMAKE_CURRENT_SOURCE_DIR})

include(${CMAKE_DIR}/AddFiles.cmake)

find_package(Qt6 6.4 REQUIRED COMPONENTS ${QT_INCLUDE_LIBRARIES})

qt_standard_project_setup()

qt_add_executable(app2D-Sandbox)

#Get cpp files to add to Executables
file(GLOB_RECURSE SOURCE_FILES ${SOURCE_DIR}/*.cpp)

#Get include files to add to Executables (Required for MOC)
file(GLOB_RECURSE INCLUDE_FILES ${INCLUDE_DIR}/*.hpp)

#Get project files
add_subdirectory(include)
add_subdirectory(source)
add_subdirectory(source_gui)

target_include_directories(app2D-Sandbox PRIVATE
    ${INCLUDE_DIR}
)

message(STATUS ${QML_FILES})

#Add resources and GUI files
qt_add_qml_module(app2D-Sandbox
    URI TwoD-Sandbox
    VERSION 1.0
    RESOURCE_PREFIX "/"

    QML_FILES ${QML_FILES}
    RESOURCES ${RESOURCES}
)

list(TRANSFORM QT_INCLUDE_LIBRARIES PREPEND "Qt6::")

target_link_libraries(app2D-Sandbox
    PRIVATE ${QT_INCLUDE_LIBRARIES}
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(app2D-Sandbox PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.app2D-Sandbox
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS app2D-Sandbox
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
