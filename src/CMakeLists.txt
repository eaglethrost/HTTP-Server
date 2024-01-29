project(HTTPServer)

add_library(httpserver Server.cpp)

target_include_directories(httpserver
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)