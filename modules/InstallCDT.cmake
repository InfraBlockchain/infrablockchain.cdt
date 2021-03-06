add_custom_command( TARGET EosioClang POST_BUILD COMMAND mkdir -p ${CMAKE_BINARY_DIR}/bin )
macro( eosio_clang_install file )
   set(BINARY_DIR ${CMAKE_BINARY_DIR}/eosio_llvm/bin)
   add_custom_command( TARGET EosioClang POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${BINARY_DIR}/${file} ${CMAKE_BINARY_DIR}/bin/ )
   install(FILES ${BINARY_DIR}/${file}
      DESTINATION ${CDT_INSTALL_PREFIX}/bin
      PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)
endmacro( eosio_clang_install )

macro( eosio_clang_install_and_symlink file symlink )
   set(BINARY_DIR ${CMAKE_BINARY_DIR}/eosio_llvm/bin)
   add_custom_command( TARGET EosioClang POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${BINARY_DIR}/${file} ${CMAKE_BINARY_DIR}/bin/ )
   add_custom_command( TARGET EosioClang POST_BUILD COMMAND cd ${CMAKE_BINARY_DIR}/bin && ln -sf ${file} ${symlink} )
   install(FILES ${BINARY_DIR}/${file}
      DESTINATION ${CDT_INSTALL_PREFIX}/bin
      PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)
   install(CODE "execute_process( COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_INSTALL_PREFIX}/bin)")
   install(CODE "execute_process( COMMAND ${CMAKE_COMMAND} -E create_symlink ${CDT_INSTALL_PREFIX}/bin/${file} ${CMAKE_INSTALL_PREFIX}/bin/${symlink})")
endmacro( eosio_clang_install_and_symlink )

macro( infrablockchain_tool_install file )
   set(BINARY_DIR ${CMAKE_BINARY_DIR}/tools/bin)
   add_custom_command( TARGET InfraBlockchainTools POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${BINARY_DIR}/${file} ${CMAKE_BINARY_DIR}/bin/ )
   install(FILES ${BINARY_DIR}/${file}
      DESTINATION ${CDT_INSTALL_PREFIX}/bin
      PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)
endmacro( infrablockchain_tool_install )

macro( infrablockchain_tool_install_and_symlink file symlink )
   set(BINARY_DIR ${CMAKE_BINARY_DIR}/tools/bin)
   add_custom_command( TARGET InfraBlockchainTools POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${BINARY_DIR}/${file} ${CMAKE_BINARY_DIR}/bin/ )
   install(FILES ${BINARY_DIR}/${file}
      DESTINATION ${CDT_INSTALL_PREFIX}/bin
      PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)
   install(CODE "execute_process( COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_INSTALL_PREFIX}/bin)")
   install(CODE "execute_process( COMMAND ${CMAKE_COMMAND} -E create_symlink ${CDT_INSTALL_PREFIX}/bin/${file} ${CMAKE_INSTALL_PREFIX}/bin/${symlink})")
endmacro( infrablockchain_tool_install_and_symlink )

macro( infrablockchain_cmake_install_and_symlink file symlink )
   set(BINARY_DIR ${CMAKE_BINARY_DIR}/modules)
   install(CODE "execute_process( COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_INSTALL_PREFIX}/lib/cmake/infrablockchain.cdt)")
   install(CODE "execute_process( COMMAND ${CMAKE_COMMAND} -E create_symlink ${CDT_INSTALL_PREFIX}/lib/cmake/infrablockchain.cdt/${file} ${CMAKE_INSTALL_PREFIX}/lib/cmake/infrablockchain.cdt/${symlink})")
endmacro( infrablockchain_cmake_install_and_symlink )

macro( infrablockchain_libraries_install)
   execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/lib)
   execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/include)
   install(DIRECTORY ${CMAKE_BINARY_DIR}/lib/ DESTINATION ${CDT_INSTALL_PREFIX}/lib)
   install(DIRECTORY ${CMAKE_BINARY_DIR}/include/ DESTINATION ${CDT_INSTALL_PREFIX}/include)
endmacro( infrablockchain_libraries_install )

eosio_clang_install_and_symlink(llvm-ranlib infrablockchain-ranlib)
eosio_clang_install_and_symlink(llvm-ar infrablockchain-ar)
eosio_clang_install_and_symlink(llvm-nm infrablockchain-nm)
eosio_clang_install_and_symlink(llvm-objcopy infrablockchain-objcopy)
eosio_clang_install_and_symlink(llvm-objdump infrablockchain-objdump)
eosio_clang_install_and_symlink(llvm-readobj infrablockchain-readobj)
eosio_clang_install_and_symlink(llvm-readelf infrablockchain-readelf)
eosio_clang_install_and_symlink(llvm-strip infrablockchain-strip)

eosio_clang_install(opt)
eosio_clang_install(llc)
eosio_clang_install(lld)
eosio_clang_install(ld.lld)
eosio_clang_install(ld64.lld)
eosio_clang_install(clang-9)
eosio_clang_install(wasm-ld)

infrablockchain_tool_install_and_symlink(infrablockchain-pp infrablockchain-pp)
infrablockchain_tool_install_and_symlink(infrablockchain-wast2wasm infrablockchain-wast2wasm)
infrablockchain_tool_install_and_symlink(infrablockchain-wasm2wast infrablockchain-wasm2wast)
infrablockchain_tool_install_and_symlink(infrablockchain-cc infrablockchain-cc)
infrablockchain_tool_install_and_symlink(infrablockchain-cpp infrablockchain-cpp)
infrablockchain_tool_install_and_symlink(infrablockchain-ld infrablockchain-ld)
infrablockchain_tool_install_and_symlink(infrablockchain-abidiff infrablockchain-abidiff)
infrablockchain_tool_install_and_symlink(infrablockchain-init infrablockchain-init)

eosio_clang_install(../lib/LLVMEosioApply${CMAKE_SHARED_LIBRARY_SUFFIX})
eosio_clang_install(../lib/LLVMEosioSoftfloat${CMAKE_SHARED_LIBRARY_SUFFIX})

infrablockchain_cmake_install_and_symlink(infrablockchain.cdt-config.cmake infrablockchain.cdt-config.cmake)
infrablockchain_cmake_install_and_symlink(InfraBlockchainWasmToolchain.cmake InfraBlockchainWasmToolchain.cmake)
infrablockchain_cmake_install_and_symlink(InfraBlockchainCDTMacros.cmake InfraBlockchainCDTMacros.cmake)

infrablockchain_libraries_install()
