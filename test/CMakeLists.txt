include_directories(../include)
add_executable(slist_test slist_test.c slist_test.h test.c)
target_link_libraries(slist_test PUBLIC "${CMAKE_SOURCE_DIR}/lib/libcds.a")