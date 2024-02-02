project(HTTPServer)

add_library(httpserver Server.cpp)
add_library(logger Logs.cpp)

target_include_directories(httpserver
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

target_include_directories(logger
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)