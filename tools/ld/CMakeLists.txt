configure_file(${CMAKE_CURRENT_SOURCE_DIR}/eosio-ld.cpp.in ${CMAKE_BINARY_DIR}/infrablockchain-ld.cpp)

add_tool(infrablockchain-ld)

set_target_properties(infrablockchain-ld PROPERTIES LINK_FLAGS "-Wl,-rpath,\"\\$ORIGIN/../lib\"")
