include(ExternalProject)
# if no cdt root is given use default path
if(INFRABLOCKCHAIN_CDT_ROOT STREQUAL "" OR NOT INFRABLOCKCHAIN_CDT_ROOT)
   find_package(infrablockchain.cdt)
endif()

ExternalProject_Add(
   hello_project
   SOURCE_DIR ${CMAKE_SOURCE_DIR}/src
   BINARY_DIR ${CMAKE_BINARY_DIR}/hello
   CMAKE_ARGS -DCMAKE_TOOLCHAIN_FILE=${INFRABLOCKCHAIN_CDT_ROOT}/lib/cmake/infrablockchain.cdt/InfraBlockchainWasmToolchain.cmake
   UPDATE_COMMAND ""
   PATCH_COMMAND ""
   TEST_COMMAND ""
   INSTALL_COMMAND ""
   BUILD_ALWAYS 1
)

ExternalProject_Add(
   hello_tests_project
   SOURCE_DIR ${CMAKE_SOURCE_DIR}/tests
   BINARY_DIR ${CMAKE_BINARY_DIR}/tests
   CMAKE_ARGS -DCMAKE_TOOLCHAIN_FILE=${INFRABLOCKCHAIN_CDT_ROOT}/lib/cmake/infrablockchain.cdt/InfraBlockchainWasmToolchain.cmake
   UPDATE_COMMAND ""
   PATCH_COMMAND ""
   TEST_COMMAND ""
   INSTALL_COMMAND ""
   BUILD_ALWAYS 1
)

### add a new test
include (CTest)
enable_testing()
add_test(hello_test ${CMAKE_BINARY_DIR}/tests/hello_test)
