/**
 *  @file capi/infrablockchain/system_token.h
 *  @author bezalel@infrablockchain.com
 *  @copyright defined in infrablockchain/LICENSE
 */
#pragma once
#include "../eosio/types.h"
#ifdef __cplusplus
extern "C" {
#endif

/**
 *  @defgroup system_token_c InfraBlockchain System Token C API
 *  @ingroup c_api
 *  @brief Defines API for InfraBlockchain System Token Operations
 */


/**
 *  Get System Token Count
 *  @brief get the number of active system tokens authorized by block producers and used as transaction fee payment token
 *
 *  @return the number of system tokens
 */
__attribute__((eosio_wasm_import))
uint32_t get_system_token_count();


/**
 * Get System Token List
 * @brief Retrieve the system token list
 *
 * @param data - output buffer of the system token list, only retrieved if sufficent size to hold packed data.
 * @param datalen - size of the data buffer, 0 to report required size.
 * @return size of the packed system token list data
 * @pre `data` is a valid pointer to a range of memory at least `datalen` bytes long
 * @post `data` is filled with packed system token list (vector<infrablockchain_system_token>)
 */
__attribute__((eosio_wasm_import))
uint32_t get_system_token_list_packed( char* data, uint32_t datalen );

/**
 * Set System Token List
 * @brief set the list of system tokens (vector<infrablockchain_system_token>) used as transaction fee payment token.
 *        2/3+ block producers have to sign any modification of system token list.
 *
 * @param system_token_list_data - packed data of system_token vector in the appropriate system token order
 * @param data_size - size of the data buffer
 *
 * @return -1 if setting new system token list was unsuccessful, otherwise returns the version of the new system token list
 */
__attribute__((eosio_wasm_import))
int64_t set_system_token_list_packed( const char* data, uint32_t datalen );

#ifdef __cplusplus
}
#endif
