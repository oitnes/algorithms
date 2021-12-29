find_package(Threads REQUIRED)

set(SOURCE_FILES test.h test.cpp config.h institution.h institution.cpp)

add_library(multithreading_visitors_lib ${SOURCE_FILES})

target_link_libraries(multithreading_visitors_lib Threads::Threads)
