#pragma once

namespace infrablockchain {

   using namespace eosio;

   namespace internal_use_do_not_use {
      extern "C" {
         __attribute__((eosio_wasm_import))
         void set_trx_fee_for_action( uint64_t code, uint64_t action, int32_t value, uint32_t fee_type );

         __attribute__((eosio_wasm_import))
         void unset_trx_fee_for_action( uint64_t code, uint64_t action );

         __attribute__((eosio_wasm_import))
         uint32_t get_trx_fee_for_action_packed( uint64_t code, uint64_t action, char* data, uint32_t datalen );

         __attribute__((eosio_wasm_import))
         uint64_t trx_fee_payer();
      }
   }

   /**
    * Transaction fee setting for an action
    * @ingroup trx_fee_c
    */
   struct tx_fee_for_action {
      /**
       * transaction fee value
       */
      int32_t value;

      /**
       * transaction fee type enum. value
       * 1: fixed_tx_fee_per_action_type, tx_fee_for_action.value => fixed transaction fee amount per action
       * 2: resource_consumption_dynamic_tx_fee_type, tx_fee_for_action.value => multiplier applied to resource consumption metric, 10000 = x1.0
       */
      uint32_t fee_type;
   };

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
   inline void set_trx_fee_for_action( name code, name action, int32_t value, uint32_t fee_type ) {
      return internal_use_do_not_use::set_trx_fee_for_action( code.value, action.value, value, fee_type );
   }

   /**
    *  Unset Transaction Fee For Action
    *  @brief delete transaction fee entry for an action (to the unsset status)
    *
    *  @param code - account name of contract code
    *  @param action - action name
    */
   inline void unset_trx_fee_for_action( name code, name action ) {
      internal_use_do_not_use::unset_trx_fee_for_action( code.value, action.value );
   }

   /**
    *  Get Transaction Fee For Action
    *  @brief get transaction fee for an action,
    *  if code == account_name(0), transaction fee info for an built-in common action is retrieved.
    *  if code == account_name(0) and action == action_name(0), retrieves default transaction fee setup for actions that don't have explicit transaction fee setup.
    *
    *  @param code - account name of contract code
    *  @param action - action name
    *  @param trx_fee_for_action - 'infrablockchain::tx_fee_for_action' object
    */
   void get_trx_fee_for_action( name code, name action, infrablockchain::tx_fee_for_action& trx_fee_for_action );

   /**
    *  Get the transaction fee payer account name
    *  @brief Get the transaction fee payer account to which transaction fee is charged
    *  @return the transaction fee payer account name
    */
   inline name trx_fee_payer() {
      return name( internal_use_do_not_use::trx_fee_payer() );
   }

}
