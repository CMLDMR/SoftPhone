cmake_minimum_required(VERSION 3.5)

project(SoftPhone VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zc:__cplusplus")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets Quick Multimedia Gui)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets Quick Multimedia Gui)

#set(PROJECT_SOURCES
#        main.cpp
#        mainwindow.cpp
#        mainwindow.h
#        mainwindow.ui
#)

qt_add_resources(QT_RESOURCES sounds.qrc images.qrc qmlResource.qrc)


set(bsoncxx_DIR C:/Mongo/mongoCPPCore/install/lib/cmake/bsoncxx-3.7.0)
set(mongocxx_DIR C:/Mongo/mongoCPPCore/install/lib/cmake/mongocxx-3.7.0)

file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE QMLFILES ${CMAKE_CURRENT_SOURCE_DIR}/*.qml)
file(GLOB_RECURSE UIFILES ${CMAKE_CURRENT_SOURCE_DIR}/*.ui)
file(GLOB_RECURSE QT_RESOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.qrc)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(SoftPhone
        MANUAL_FINALIZATION
        ${HEADERS}
        ${SOURCES}
        ${QMLFILES}
        ${UIFILES}
        ${QT_RESOURCES}
    )

qt_add_qml_module(SoftPhone
    URI SoftPhone
    VERSION 1.0
    QML_FILES main.qml
        QML/PhoneKeyboard.qml
        QML/PhoneButton.qml
)




# Define target properties for Android with Qt 6 as:
#    set_property(TARGET SoftPhone APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(SoftPhone SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(SoftPhone
            ${PROJECT_SOURCES}
        )
    endif()
endif()


target_include_directories(SoftPhone PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../SoftPhoneLib/MSVC2022x64noBoost/include")

target_link_directories(SoftPhone PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../SoftPhoneLib/MSVC2022x64noBoost/lib")

target_include_directories(SoftPhone PUBLIC "C:/Mongo/mongoCPPCore/install/include")
target_link_directories(SoftPhone PUBLIC "C:/Mongo/mongoCPPCore/install/lib")
target_link_libraries(SoftPhone PRIVATE MongoCore)



target_link_libraries(SoftPhone PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Multimedia Qt${QT_VERSION_MAJOR}::Gui SerikBLDCore)


find_package(mongocxx REQUIRED)
find_package(bsoncxx REQUIRED)
include_directories(${LIBMONGOCXX_INCLUDE_DIR})
include_directories(${LIBBSONCXX_INCLUDE_DIR})
target_link_libraries(SoftPhone PRIVATE mongo::bsoncxx_shared)
target_link_libraries(SoftPhone PRIVATE mongo::mongocxx_shared)


add_definitions(-DPJ_NATIVE_STRING_IS_UNICODE=1)
add_definitions(-DPJ_WIN32=1)
add_definitions(-DPJ_IS_LITTLE_ENDIAN=1)
add_definitions(-DPJ_IS_BIG_ENDIAN=1)
add_definitions(-DUNICODE=0)



target_include_directories(SoftPhone PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../SoftPhoneLib/pjproject-2.12/pjsip/include")
target_include_directories(SoftPhone PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../SoftPhoneLib/pjproject-2.12/pjlib/include")
target_include_directories(SoftPhone PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../SoftPhoneLib/pjproject-2.12/pjlib-util/include")
target_include_directories(SoftPhone PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../SoftPhoneLib/pjproject-2.12/pjmedia/include")
target_include_directories(SoftPhone PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../SoftPhoneLib/pjproject-2.12/pjnath/include")


target_link_directories(SoftPhone PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../SoftPhoneLib/pjproject-2.12/lib")
target_link_directories(SoftPhone PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../SoftPhoneLib/pjproject-2.12/pjlib/lib")
target_link_directories(SoftPhone PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../SoftPhoneLib/pjproject-2.12/pjlib-util/lib")
target_link_directories(SoftPhone PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../SoftPhoneLib/pjproject-2.12/pjmedia/lib")
target_link_directories(SoftPhone PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../SoftPhoneLib/pjproject-2.12/pjnath/lib")
target_link_directories(SoftPhone PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../SoftPhoneLib/pjproject-2.12/pjsip/lib")
target_link_directories(SoftPhone PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../SoftPhoneLib/pjproject-2.12/pjnath/lib")
target_link_directories(SoftPhone PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../SoftPhoneLib/pjproject-2.12/third_party/lib")

target_link_libraries(SoftPhone PUBLIC libpjproject-x86_64-x64-vc14-Release-Dynamic)
target_link_libraries(SoftPhone PUBLIC pjlib-util-x86_64-x64-vc14-Release-Dynamic)
target_link_libraries(SoftPhone PUBLIC pjsua2-lib-x86_64-x64-vc14-Release-Dynamic)
target_link_libraries(SoftPhone PUBLIC pjsua-lib-x86_64-x64-vc14-Release-Dynamic)
target_link_libraries(SoftPhone PUBLIC pjsip-ua-x86_64-x64-vc14-Release-Dynamic)

target_link_libraries(SoftPhone PUBLIC pjsip-simple-x86_64-x64-vc14-Release-Dynamic)
target_link_libraries(SoftPhone PUBLIC pjsip-core-x86_64-x64-vc14-Release-Dynamic)
target_link_libraries(SoftPhone PUBLIC pjmedia-codec-x86_64-x64-vc14-Release-Dynamic)
target_link_libraries(SoftPhone PUBLIC pjmedia-x86_64-x64-vc14-Release-Dynamic)
target_link_libraries(SoftPhone PUBLIC pjmedia-codec-x86_64-x64-vc14-Release-Dynamic)
target_link_libraries(SoftPhone PUBLIC pjmedia-audiodev-x86_64-x64-vc14-Release-Dynamic)
target_link_libraries(SoftPhone PUBLIC pjnath-x86_64-x64-vc14-Release-Dynamic)
target_link_libraries(SoftPhone PUBLIC pjlib-x86_64-x64-vc14-Release-Dynamic)
target_link_libraries(SoftPhone PUBLIC libbaseclasses-x86_64-x64-vc14-Release-Dynamic)
target_link_libraries(SoftPhone PUBLIC libg7221codec-x86_64-x64-vc14-Release-Dynamic)
                #target_link_libraries(SoftPhone PUBLIC libportaudio-i386-Win32-vc14-Release-Dynamic \
target_link_libraries(SoftPhone PUBLIC libgsmcodec-x86_64-x64-vc14-Release-Dynamic)
target_link_libraries(SoftPhone PUBLIC libilbccodec-x86_64-x64-vc14-Release-Dynamic)
target_link_libraries(SoftPhone PUBLIC libspeex-x86_64-x64-vc14-Release-Dynamic)
target_link_libraries(SoftPhone PUBLIC libresample-x86_64-x64-vc14-Release-Dynamic)
target_link_libraries(SoftPhone PUBLIC libmilenage-x86_64-x64-vc14-Release-Dynamic)
target_link_libraries(SoftPhone PUBLIC libsrtp-x86_64-x64-vc14-Release-Dynamic)
target_link_libraries(SoftPhone PUBLIC winmm)
target_link_libraries(SoftPhone PUBLIC ole32)
target_link_libraries(SoftPhone PUBLIC ws2_32)
target_link_libraries(SoftPhone PUBLIC wsock32)
target_link_libraries(SoftPhone PUBLIC gdi32)

set_target_properties(SoftPhone PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS SoftPhone
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(SoftPhone)
endif()
