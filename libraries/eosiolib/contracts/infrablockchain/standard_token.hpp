#pragma once

#include "../../core/eosio/name.hpp"
#include "../../core/eosio/symbol.hpp"
#include "../../core/eosio/asset.hpp"

namespace infrablockchain {

   using namespace eosio;

   namespace internal_use_do_not_use {
      extern "C" {
         __attribute__((eosio_wasm_import))
         uint64_t get_token_symbol( uint64_t token_id );

         __attribute__((eosio_wasm_import))
         int64_t get_token_total_supply( uint64_t token_id );

         __attribute__((eosio_wasm_import))
         int64_t get_token_balance( uint64_t token_id, uint64_t account );

         __attribute__((eosio_wasm_import))
         void issue_token( uint64_t to, int64_t amount );

         __attribute__((eosio_wasm_import))
         void transfer_token( uint64_t from, uint64_t to, int64_t amount );

         __attribute__((eosio_wasm_import))
         void retire_token( int64_t amount );
      }
   }

   /**
    *  Get Token Symbol
    *  @brief get token symbol of a token
    *
    *  @param token - token account name
    *  @return token symbol code (eosio::symbol_code)
    */
   inline symbol get_token_symbol( name token ) {
      return symbol(internal_use_do_not_use::get_token_symbol( token.value ));
   }

   /**
    *  Get Token Total Supply Amount
    *  @brief get current total supply amount of a token
    *
    *  @param token - token account name
    *  @return current total supply amount of the token
    */
   inline int64_t get_token_total_supply_amount( name token ) {
      return internal_use_do_not_use::get_token_total_supply( token.value );
   }

   /**
    *  Get Token Total Supply
    *  @brief get current total supply of a token
    *
    *  @param token - token account name
    *  @return current total supply of the token in asset type
    */
   inline asset get_token_total_supply( name token ) {
      return asset( internal_use_do_not_use::get_token_total_supply( token.value ),
                    symbol(internal_use_do_not_use::get_token_symbol( token.value )) );
   }

   /**
    *  Get Token Balance Amount
    *  @brief get token balance of an account for an token
    *
    *  @param token - token account name
    *  @param account - account name to retrieve token balance
    *  @return token balance of the account
    */
   inline int64_t get_token_balance_amount( name token, name account ) {
      return internal_use_do_not_use::get_token_balance( token.value, account.value );
   }

   /**
    *  Get Token Balance
    *  @brief get token balance of an account for an token
    *
    *  @param token - token account name
    *  @param account - account name to retrieve token balance
    *  @return token balance of the account in asset type
    */
   inline asset get_token_balance( name token, name account ) {
      return asset( internal_use_do_not_use::get_token_balance( token.value, account.value ),
                    symbol(internal_use_do_not_use::get_token_symbol( token.value )) );
   }

   /**
    *  Issue Token
    *  @brief issue new token to a specific account,
    *  token account is implicitly the action receiver (token owner) account,
    *  the contract code of token owner account can issue its own token only.
    *
    *  @param to - account name to which new token is issued
    *  @param amount - amount of token to issue
    */
   inline void issue_token( name to, int64_t amount ) {
      internal_use_do_not_use::issue_token( to.value, amount );
   }

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
   inline void transfer_token( name from, name to, int64_t amount ) {
      internal_use_do_not_use::transfer_token( from.value, to.value, amount );
   }

   /**
    *  Retire(Burn) Token
    *  @brief retire(burn) token from token owner account,
    *  token_id is implicitly the action receiver (token owner) account,
    *  the contract code of token owner account can burn its own token only.
    *
    *  @param amount - amount of token to retire(burn)
    */
   inline void retire_token( int64_t amount ) {
      internal_use_do_not_use::retire_token( amount );
   }

}
