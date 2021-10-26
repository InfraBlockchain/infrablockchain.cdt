project(kvtest)

set(INFRABLOCKCHAIN_WASM_OLD_BEHAVIOR "Off")
find_package(infrablockchain.cdt)

add_contract( kvtest kvtest kvtest.cpp )
target_ricardian_directory( kvtest ${CMAKE_SOURCE_DIR}/../ricardian )