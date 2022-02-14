cmake_minimum_required(VERSION 2.8)
project(youtube C)

set(CMAKE_C_STANDARD 99)


find_package(PkgConfig REQUIRED)
pkg_check_modules(XML REQUIRED libxml-2.0)
pkg_check_modules(CURL REQUIRED libcurl)

include_directories(${CURL_INCLUDE_DIRS} ${XML_INCLUDE_DIRS} lib/cJSON)

add_executable(youtube main.c Config.c Config.h Channel.c Channel.h Video.c Video.h Util.c Util.h Net.c Net.h lib/cJSON/cJSON.c lib/cJSON/cJSON_Utils.c)

target_link_libraries(youtube PRIVATE ${CURL_LIBRARIES} ${XML_LIBRARIES})