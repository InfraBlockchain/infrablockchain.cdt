configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cdt-abidiff.cpp.in ${CMAKE_BINARY_DIR}/infrablockchain-abidiff.cpp)

add_tool(infrablockchain-abidiff)

set_target_properties(infrablockchain-abidiff PROPERTIES LINK_FLAGS "-Wl,-rpath,\"\\$ORIGIN/../lib\"")
