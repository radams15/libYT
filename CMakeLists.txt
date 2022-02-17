cmake_minimum_required(VERSION 2.8)
project(yt C)

set(CMAKE_C_STANDARD 99)

include(GNUInstallDirs)

find_package(PkgConfig REQUIRED)
pkg_check_modules(CURL REQUIRED libcurl)

set(CMAKE_C_FLAGS "-std=c99")

include_directories(${CURL_INCLUDE_DIRS} lib/cJSON include/)

set(HEADERS include/Channel.h include/Config.h include/Video.h include/Net.h)

add_library(yt SHARED src/main/Config.c src/main/Channel.c src/main/Video.c src/main/Util.c src/main/Net.c lib/cJSON/cJSON.c lib/cJSON/cJSON_Utils.c)

add_executable(ytplay test/main.c)
target_link_libraries(ytplay yt)

target_link_libraries(yt PRIVATE ${CURL_LIBRARIES})


if(${APPLE})
set_target_properties(yt PROPERTIES LINK_FLAGS "-Wl,-F/System/Library/Frameworks")
endif()

install(TARGETS yt DESTINATION lib/yt)
install(TARGETS ytplay DESTINATION bin)
install(FILES ${HEADERS} DESTINATION include/yt)