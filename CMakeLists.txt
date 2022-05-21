cmake_minimum_required(VERSION 3.0)
project(yt C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 98)

include(GNUInstallDirs)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(CURL REQUIRED libcurl)

option(BUILD_YTPLAY "Build Example Application" ON)

set(CMAKE_C_FLAGS "-std=c99")

include_directories(${CURL_INCLUDE_DIRS} lib/cJSON include/ lib/librequest/include)

set(YT_HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include PARENT_SCOPE)

set(YT_HEADERS include/Channel.h include/Config.h include/Video.h include/Net.h include/List.h)

add_subdirectory(lib/librequest)

add_library(yt STATIC src/main/Config.c src/main/Channel.c src/main/Video.c src/main/Util.c src/main/Net.c lib/cJSON/cJSON.c lib/cJSON/cJSON_Utils.c include/YT.h include/List.h src/main/Sort.c src/main/Sort.h)

if(BUILD_YTPLAY)
add_executable(ytplay test/main.cpp)
target_link_libraries(ytplay yt)
endif()

target_link_libraries(yt PRIVATE ${CURL_LIBRARIES} request)


if(${APPLE})
    # https://github.com/sheldonth/ios-cmake
    set_target_properties(yt PROPERTIES
            FRAMEWORK TRUE
            FRAMEWORK_VERSION A
            MACOSX_FRAMEWORK_IDENTIFIER uk.co.therhys.yt
            MACOSX_FRAMEWORK_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/res/framework.plist
            # "current version" in semantic format in Mach-O binary fname
            VERSION 1.0.0
            # "compatibility version" in semantic format in Mach-O binary fname
            SOVERSION 1.0.0
            PUBLIC_HEADER "${YT_HEADERS}"
            )

    set_target_properties(yt PROPERTIES LINK_FLAGS "-Wl,-F/System/Library/Frameworks")
endif()

install(TARGETS yt DESTINATION lib/)
if(BUILD_YTPLAY)
install(TARGETS ytplay DESTINATION bin)
endif()
install(FILES ${YT_HEADERS} DESTINATION include/yt/)
