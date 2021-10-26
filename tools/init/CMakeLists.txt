configure_file(${CMAKE_CURRENT_SOURCE_DIR}/eosio-init.cpp ${CMAKE_BINARY_DIR}/infrablockchain-init.cpp @ONLY)

add_tool(infrablockchain-init)

set_target_properties(infrablockchain-init PROPERTIES LINK_FLAGS "-Wl,-rpath,\"\\$ORIGIN/../lib\"")
