cmake_minimum_required(VERSION 3.16)

project(DemoChatApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)
find_package(Qt6 REQUIRED COMPONENTS Core)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appDemoChatApp
    main.cpp
)

qt_add_qml_module(appDemoChatApp
    URI DemoChatApp
    VERSION 1.0
    QML_FILES
        Main.qml
        QML_FILES  qml/DeList.qml
        SOURCES source/data.cpp source/data.h
        SOURCES
        SOURCES
        SOURCES ../DemoChatServer/source/messageutils.cpp ../DemoChatServer/source/messageutils.h
        SOURCES
        SOURCES source/listmodel.cpp source/listmodel.h
        SOURCES ../DemoChatServer/source/pipeclient.cpp ../DemoChatServer/source/pipeclient.h
        QML_FILES
        QML_FILES qml/DeBox.qml
        QML_FILES
        QML_FILES qml/DeButton.qml
        QML_FILES qml/DeTextBox.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appDemoChatApp PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appDemoChatApp
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appDemoChatApp
    PRIVATE Qt6::Quick
)
target_link_libraries(appDemoChatApp PRIVATE Qt6::Core)

include(GNUInstallDirs)
install(TARGETS appDemoChatApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
