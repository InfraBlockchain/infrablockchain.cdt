/**
 *  @file capi/infrablockchain/transaction_fee_management.h
 *  @author bezalel@infrablockchain.com
 *  @copyright defined in infrablockchain/LICENSE
 */
#pragma once
#include "../eosio/types.h"
#ifdef __cplusplus
extern "C" {
#endif

/**
 *  @defgroup trx_fee_c InfraBlockchain Transaction Fee Management C API
 *  @ingroup c_api
 *  @brief Defines API for InfraBlockchain Transaction Fee Management Operations
 */


/**
 *  Set Transaction Fee For Action
 *  @brief set transaction fee for an action. the transaction fee for each code/action is determined by the 2/3+ block producers.
 *  if code == account_name(0), this sets a transaction fee for the built-in common actions (e.g. InfraBlockchain standard token actions) that every account has.
 *  if code == account_name(0) and action == action_name(0), this sets default transaction fee for actions that don't have explicit transaction fee setup.
 *
 *  @param code - account name of contract code
 *  @param action - action name
 *  @param value - transaction fee value
 *  @param fee_type - transaction fee type (1: fixed_tx_fee_per_action_type)
 */
__attribute__((eosio_wasm_import))
void set_trx_fee_for_action( capi_name code, capi_name action, int32_t value, uint32_t fee_type );

/**
 *  Unset Transaction Fee For Action
 *  @brief delete transaction fee entry for an action (to the unsset status)
 *
 *  @param code - account name of contract code
 *  @param action - action name
 */
__attribute__((eosio_wasm_import))
void unset_trx_fee_for_action( capi_name code, capi_name action );

/**
 *  Get Transaction Fee For Action
 *  @brief get transaction fee for an action,
 *  if code == account_name(0), transaction fee info for an built-in common action is retrieved.
 *  if code == account_name(0) and action == action_name(0), retrieves default transaction fee setup for actions that don't have explicit transaction fee setup.
 *
 *  @param code - account name of contract code
 *  @param action - action name
 *  @param data - output buffer of the packed 'infrablockchain::tx_fee_for_action' object, only retrieved if sufficient size to hold packed data.
 *  @param datalen - size of the data buffer, 0 to report required size.
 *  @return size of the packed 'tx_fee_for_action' data
 *  @pre `data` is a valid pointer to a range of memory at least `datalen` bytes long
 *  @post `data` is filled with packed 'infrablockchain::tx_fee_for_action' object
 */
__attribute__((eosio_wasm_import))
uint32_t get_trx_fee_for_action_packed( capi_name code, capi_name action, char* data, uint32_t datalen );

/**
 *  Get the transaction fee payer account name
 *  @brief Get the transaction fee payer account to which transaction fee is charged
 *  @return the transaction fee payer account name
 */
__attribute__((eosio_wasm_import))
capi_name trx_fee_payer();



#ifdef __cplusplus
}
#endif
