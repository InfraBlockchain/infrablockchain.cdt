project(kv_map)

set(INFRABLOCKCHAIN_WASM_OLD_BEHAVIOR "Off")
find_package(infrablockchain.cdt)

add_contract( kv_map kv_map kv_map.cpp )
target_include_directories( kv_map PUBLIC ${CMAKE_SOURCE_DIR}/../include )
target_ricardian_directory( kv_map ${CMAKE_SOURCE_DIR}/../ricardian )