
add_library(linalg vector_dot.c vector_add.c matrix_vector_mul.c
    matrix_matrix_mul.c vector.c matrix.c)

add_executable(test_vector_dot test_vector_dot.c)
target_link_libraries(test_vector_dot PRIVATE linalg)
add_test(TestVectorDot test_vector_dot)

add_executable(test_vector_add test_vector_add.c)
target_link_libraries(test_vector_add PRIVATE linalg)
add_test(TestVectorAdd test_vector_add)

add_executable(test_matrix_vector_mul test_matrix_vector_mul.c)
target_link_libraries(test_matrix_vector_mul PRIVATE linalg)
add_test(TestMatrixVectorMul test_matrix_vector_mul)

add_executable(test_matrix_matrix_mul test_matrix_matrix_mul.c)
target_link_libraries(test_matrix_matrix_mul PRIVATE linalg)
add_test(TestMatrixMatrixMul test_matrix_matrix_mul)

add_executable(test_data_layout test_data_layout.c)
