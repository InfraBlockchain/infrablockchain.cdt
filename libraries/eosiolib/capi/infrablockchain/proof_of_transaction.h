/**
 *  @file capi/infrablockchain/proof_of_transaction.h
 *  @author bezalel@infrablockchain.com
 *  @copyright defined in infrablockchain/LICENSE
 */
#pragma once
#include "../eosio/types.h"
#ifdef __cplusplus
extern "C" {
#endif

/**
 *  @defgroup pot_trx_vote_c InfraBlockchain Proof-of-Transaction C API
 *  @ingroup c_api
 *  @brief Defines API for InfraBlockchain Proof-of-Transaction Operations
 */

/**
 * Get Top Transaction Vote Receivers
 * @brief Retrieve top transaction vote receiver list from blockchain core.
 *        Transaction votes are processed and accrued for each vote target account on blockchain core by InfraBlockchain Proof-of-Transaction/Transaction-as-a-Vote protocol
 *        Smart contract code including system contract can retrieve the top transaction vote receiver list
 *        sorted by the accumulated time-decaying weighted transaction vote amount for each tx vote receiver account.
 *        The whole list of transaction vote receivers can be arbitrarily long,
 *        so the sorted list can be retrieved by multiple function call with different offset_rank and limit parameter values.
 *
 * @param buffer - a buffer to write the top sorted transaction vote receiver list data to,
 *                 returned buffer memory contains array of 'infrablockchain::tx_vote_stat_for_account' struct
 * @param size - the size of the buffer, 0 to return required size
 * @param offset_rank - offset-rank of first item in the returned list. offset-rank n means the returned list starts from the rank n+1 tx vote receiver.
 *                      e.g. if offset_rank = 0, the first item in the returned list is the top 1 vote receiver.
 * @param limit - max limit of the returned item count
 *
 * @return the size of the sorted transaction vote receiver list data written to the buffer (array of 'infrablockchain::tx_vote_stat_for_account' struct),
 *         or number of bytes required if the output buffer is empty.
 */
__attribute__((eosio_wasm_import))
uint32_t get_top_transaction_vote_receivers_packed( char *buffer, size_t size, uint32_t offset_rank, uint32_t limit );


/**
 * Get Total Weighted Transaction Votes
 * @brief Retrieve the total weighted (time-decaying) transaction vote amount accumulated for all blockchain transactions in the blockchain history
 *
 * @return total weighted transaction vote amount
 */
__attribute__((eosio_wasm_import))
double get_total_weighted_transaction_votes();


#ifdef __cplusplus
}
#endif
