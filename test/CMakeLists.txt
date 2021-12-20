set(TEST_SOURCES
        main.cpp
        array/3sum.cpp
        array/bubble_sort.cpp
        array/find_first_and_last_position_of_element_in_sorted_array.cpp
        array/find_minimum_in_rotated_sorted_array.cpp
        array/find_peak_element.cpp
        array/search_in_rotated_sorted_array.cpp
        array/insert_sort.cpp
        array/merge_sort.cpp
        array/fast_four_array_sort.cpp
        graph/all_paths_in_acyclic_graph.cpp
        grid/shortest_path_in_binary_matrix.cpp
        grid/surrounded_regions.cpp
        list/remove_duplicates_from_sorted_list_2.cpp
        matrix/search_a_2D_matrix.cpp
        )

add_executable(algorithms_tests ${TEST_SOURCES})
target_link_libraries(algorithms_tests algorithms_lib ${CONAN_LIBS})
target_include_directories(algorithms_tests PRIVATE ${CMAKE_SOURCE_DIR}/src)

add_test(NAME algorithms_tests WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin COMMAND algorithms_tests)
