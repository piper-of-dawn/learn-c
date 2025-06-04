cmake_minimum_required(VERSION 3.16)
project(MatrixHasherTests)

enable_testing()
set(CMAKE_CXX_STANDARD 17)

# Link test target with the matrix_hasher source
add_library(MatrixHasherLib ../matrix_hasher.cpp)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(matrix_hasher_tests matrix_hasher_tests.cpp)
target_link_libraries(matrix_hasher_tests MatrixHasherLib GTest::GTest GTest::Main)

add_test(NAME EmptyVectorReturnsZero COMMAND matrix_hasher_tests --gtest_filter=MatrixHasherTestSuite.EmptyVectorReturnsZero)
add_test(NAME SingleElementVectorHashesCorrectly COMMAND matrix_hasher_tests --gtest_filter=MatrixHasherTestSuite.SingleElementVectorHashesCorrectly)
add_test(NAME IdenticalVectorsProduceSameHash COMMAND matrix_hasher_tests --gtest_filter=MatrixHasherTestSuite.IdenticalVectorsProduceSameHash)
add_test(NAME SmallPerturbationChangesHash COMMAND matrix_hasher_tests --gtest_filter=MatrixHasherTestSuite.SmallPerturbationChangesHash)
add_test(NAME HighVolumeRandomDataHashConsistency COMMAND matrix_hasher_tests --gtest_filter=MatrixHasherTestSuite.HighVolumeRandomDataHashConsistency)
