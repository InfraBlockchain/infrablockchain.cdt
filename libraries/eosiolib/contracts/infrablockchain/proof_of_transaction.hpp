#pragma once

#include "../../core/eosio/name.hpp"
#include "../../core/eosio/serialize.hpp"

namespace infrablockchain {

   using namespace eosio;

   namespace internal_use_do_not_use {
      extern "C" {
         __attribute__((eosio_wasm_import))
         uint32_t get_top_transaction_vote_receivers_packed( char *buffer, size_t size, uint32_t offset_rank, uint32_t limit );

         __attribute__((eosio_wasm_import))
         double get_total_weighted_transaction_votes();
      }
   }

   /**
    * Transaction vote statistics item for an account
    */
   struct tx_vote_stat_for_account {
      /**
       * account name
       */
      name account;

      /**
       * weighted transaction vote amount received by this account
       */
      double tx_votes_weighted;

      /**
       * accumulated transaction vote amount received by this account
       */
      uint64_t tx_votes;

      EOSLIB_SERIALIZE( tx_vote_stat_for_account,
                        (account)(tx_votes_weighted)(tx_votes) )
   };

   /**
    * Get Top Transaction Vote Receivers
    * @brief Retrieve top transaction vote receiver list from blockchain core.
    *        Transaction votes are processed and accrued for each vote target account on blockchain core by InfraBlockchain Proof-of-Transaction/Transaction-as-a-Vote protocol
    *        Smart contract code including system contract can retrieve the top transaction vote receiver list
    *        sorted by the accumulated time-decaying weighted transaction vote amount for each tx vote receiver account.
    *        The whole list of transaction vote receivers can be arbitrarily long,
    *        so the sorted list can be retrieved by multiple function call with different offset_rank and limit parameter values.
    *
    * @param vote_receivers - [out] the top sorted transaction vote receiver list data, vector of 'infrablockchain::tx_vote_stat_for_account' struct
    * @param offset_rank - offset-rank of first item in the returned list. offset-rank n means the returned list starts from the rank n+1 tx vote receiver.
    *                      e.g. if offset_rank = 0, the first item in the returned list is the top 1 vote receiver.
    * @param limit - max limit of the returned item count
    *
    * @return the size of the sorted transaction vote receiver list data written to the buffer (array of 'infrablockchain_tx_vote_stat_for_account' struct),
    *         or number of bytes required if the output buffer is empty.
    */
   void get_top_transaction_vote_receivers( std::vector<infrablockchain::tx_vote_stat_for_account>& vote_receivers, uint32_t offset_rank, uint32_t limit );

   /**
    * Get Total Weighted Transaction Votes
    * @brief Retrieve the total weighted (time-decaying) transaction vote amount accumulated for all blockchain transactions in the blockchain history
    *
    * @return total weighted transaction vote amount
    */
   inline double get_total_weighted_transaction_votes() {
      return internal_use_do_not_use::get_total_weighted_transaction_votes();
   }

}
