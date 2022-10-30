set(TEST_SOURCES
        main.cpp
        array/3sum.cpp
        array/bubble_sort.cpp
        array/find_first_and_last_position_of_element_in_sorted_array.cpp
        array/find_minimum_in_rotated_sorted_array.cpp
        array/find_peak_element.cpp
        array/find_the_town_judge.cpp
        array/search_in_rotated_sorted_array.cpp
        array/insert_sort.cpp
        array/merge_sort.cpp
        array/minimum_size_subarray_sum.cpp
        array/product_expect_self.cpp
        array/rotate_function.cpp
        array/fast_four_array_sort.cpp
        array/strongest_values_in_an_array.cpp
        array/subarray_product_less_than.cpp
        dynamic/cut_rod.cpp
        graph/all_paths_from_source_to_target.cpp
        graph/number_of_provinces.cpp
        grid/number_of_islands.cpp
        grid/shortest_path_in_binary_matrix.cpp
        grid/surrounded_regions.cpp
        grid/word_search.cpp
        list/remove_duplicates_from_sorted_list_2.cpp
        matrix/search_a_2D_matrix.cpp
        matrix/spiral_order.cpp
        multithreading/visitor.cpp
        number/complement_of_base_ten.cpp
        set/combination_sum.cpp
        set/letter_combination_in_phone_number.cpp
        set/permutations_2.cpp
        set/subset.cpp
        set/subset2.cpp
        string/find_all_anagrams_in_string.cpp
        string/generate_parentheses.cpp
        tree/populating_next_right_pointers_in_each_node_two.cpp
        tree/subtree_of_another_tree.cpp
        )

add_executable(algorithms_tests ${TEST_SOURCES})
target_link_libraries(algorithms_tests algorithms_lib multithreading_visitors_lib ${CONAN_LIBS})
target_include_directories(algorithms_tests PRIVATE ${CMAKE_SOURCE_DIR}/src)
