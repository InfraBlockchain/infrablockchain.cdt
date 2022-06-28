/**
 *  @file capi/infrablockchain/standard_token.h
 *  @author bezalel@infrablockchain.com
 *  @copyright defined in infrablockchain/LICENSE
 */
#pragma once
#include "../eosio/types.h"
#ifdef __cplusplus
extern "C" {
#endif

/**
 *  @defgroup token_c InfraBlockchain Standard Token C API
 *  @ingroup c_api
 *  @brief Defines API for InfraBlockchain Standard Token Operations
 */

/**
 *  Get Token Symbol
 *  @brief get token symbol of a token
 *
 *  @param token_id - token account name
 *  @return token symbol code (eosio::symbol_code)
 */
__attribute__((eosio_wasm_import))
uint64_t get_token_symbol( capi_name token_id );

/**
 *  Get Token Total Supply
 *  @brief get current total supply of a token
 *
 *  @param token_id - token account name
 *  @return current total supply amount of the token
 */
__attribute__((eosio_wasm_import))
int64_t get_token_total_supply( capi_name token_id );

/**
 *  Get Token Balance
 *  @brief get token balance of an account for an token
 *
 *  @param token_id - token account name
 *  @param account - account name to retrieve token balance
 *  @return token balance of the account
 */
__attribute__((eosio_wasm_import))
int64_t get_token_balance( capi_name token_id, capi_name account );

/**
 *  Issue Token
 *  @brief issue new token to a specific account,
 *  token_id is implicitly the action receiver (token owner) account,
 *  the contract code of token owner account can issue its own token only.
 *
 *  @param to - account name to which new token is issued
 *  @param amount - amount of token to issue
 */
__attribute__((eosio_wasm_import))
void issue_token( capi_name to, int64_t amount );

/**
 *  Transfer Token
 *  @brief transfer token from 'from' account to 'to' account,
 *  token_id is implicitly the action receiver (token owner) account,
 *  the contract code of token owner account can transfer its own token only.
 *
 *  @param from - account from which token amount is transferred (subtracted)
 *  @param to - account to which token amount is transferred (added)
 *  @param amount - amount of token to transfer
 */
__attribute__((eosio_wasm_import))
void transfer_token( capi_name from, capi_name to, int64_t amount );

/**
 *  Retire(Burn) Token
 *  @brief retire(burn) token from token owner account,
 *  token_id is implicitly the action receiver (token owner) account,
 *  the contract code of token owner account can burn its own token only.
 *
 *  @param amount - amount of token to retire(burn)
 */
__attribute__((eosio_wasm_import))
void retire_token( int64_t amount );


#ifdef __cplusplus
}
#endif
