include(ExternalProject)
# if no cdt root is given use default path
if(INFRABLOCKCHAIN_CDT_ROOT STREQUAL "" OR NOT INFRABLOCKCHAIN_CDT_ROOT)
   find_package(infrablockchain.cdt)
endif()

ExternalProject_Add(
   singleton_example_project
   SOURCE_DIR ${CMAKE_SOURCE_DIR}/src
   BINARY_DIR ${CMAKE_BINARY_DIR}/singleton_example
   CMAKE_ARGS -DCMAKE_TOOLCHAIN_FILE=${INFRABLOCKCHAIN_CDT_ROOT}/lib/cmake/infrablockchain.cdt/InfraBlockchainWasmToolchain.cmake
   UPDATE_COMMAND ""
   PATCH_COMMAND ""
   TEST_COMMAND ""
   INSTALL_COMMAND ""
   BUILD_ALWAYS 1
)