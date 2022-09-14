configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cdt-cc.cpp.in ${CMAKE_BINARY_DIR}/infrablockchain-cc.cpp)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cdt-cpp.cpp.in ${CMAKE_BINARY_DIR}/infrablockchain-cpp.cpp)

add_tool(infrablockchain-cc)
add_tool(infrablockchain-cpp)

set_target_properties(infrablockchain-cc PROPERTIES LINK_FLAGS "-Wl,-rpath,\"\\$ORIGIN/../lib\"")
set_target_properties(infrablockchain-cpp PROPERTIES LINK_FLAGS "-Wl,-rpath,\"\\$ORIGIN/../lib\"")
