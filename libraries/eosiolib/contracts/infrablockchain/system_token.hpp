#pragma once

#include "../../core/eosio/name.hpp"
#include "../../core/eosio/serialize.hpp"

namespace infrablockchain {

   using namespace eosio;

   namespace internal_use_do_not_use {
      extern "C" {
         __attribute__((eosio_wasm_import))
         uint32_t get_system_token_count();

         __attribute__((eosio_wasm_import))
         uint32_t get_system_token_list_packed( char* data, uint32_t datalen );

         __attribute__((eosio_wasm_import))
         int64_t set_system_token_list_packed( const char* data, uint32_t datalen );
      }
   }

   /**
    *  System token item selected by producers
    *  @ingroup system_token
    */
   struct system_token {

      /**
       * token account name selected as system token
       */
      name token_id;

      /**
       * token value weight as transaction fee payment,
       * 10000 = 1.0x, 5000 = 0.5x (tx fee is charged 2x)
       */
      uint32_t token_weight;

      EOSLIB_SERIALIZE( system_token,
                        (token_id)(token_weight) )
   };

   /**
    *  Get System Token Count
    *  @brief get the number of active system tokens authorized by block producers and used as transaction fee payment token
    *
    *  @return the number of system tokens
    */
   inline uint32_t get_system_token_count() {
      return internal_use_do_not_use::get_system_token_count();
   }

   /**
    * Get System Token List
    * @brief Retrieve the system token list
    *
    * @param system_tokens - output vector of the retrieved system token list
    */
   void get_system_token_list( std::vector<infrablockchain::system_token>& system_tokens );

   /**
    * Set System Token List
    * @brief set the list of system tokens (std::vector<infrablockchain::system_token>) used as transaction fee payment token.
    *        2/3+ block producers have to sign any modification of system token list.
    *
    * @param system_tokens - vector of system_token in the appropriate system token order
    *
    * @return an optional value of the version of the new system token list if successful
    */
   std::optional<uint64_t> set_system_token_list( const std::vector<infrablockchain::system_token>& system_tokens );

}
