project(HTTPServer)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE httpserver)
target_link_libraries(main PRIVATE logger)