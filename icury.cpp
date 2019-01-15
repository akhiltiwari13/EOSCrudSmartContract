#include <eosiolib/eosio.hpp>
#include "icury.hpp"

using namespace eosio;

  void icury::writetx(uint64_t transaction_id, std::string icecat_userid_from, std::string icecat_userid_to, std::string currency) {
    require_auth( _self );
    transaction_index transactions(_code, _code.value);
    auto iterator = transactions.find(transaction_id);
    if( iterator == transactions.end() )
    {
      transactions.emplace(_self, [&]( auto& row ) {
       row.transaction_id = transaction_id;
       row.icecat_userid_from = icecat_userid_from;
       row.icecat_userid_to = icecat_userid_to;
       row.currency = currency;
      });
    }
    else {
      transactions.modify(iterator, _self, [&]( auto& row ) {
        row.transaction_id = transaction_id;
        row.icecat_userid_from = icecat_userid_from;
        row.icecat_userid_to = icecat_userid_to;
        row.currency = currency;
      });
    }
  }

 
  void icury::removetx(uint64_t transaction_id) {
    transaction_index transactions(_self, _code.value);
    auto iterator = transactions.find(transaction_id);
    eosio_assert(iterator != transactions.end(), "Record does not exist");
    transactions.erase(iterator);
  }

void icury::writetxln( uint64_t transactionln_id,
    uint64_t transaction_id,
    uint64_t tstmp,
    std::string icecat_id,
    std::string value,
    uint16_t item_quantity,
    std::string item_description,
    uint16_t vat){
    require_auth( _self );
    transactionln_index trxlns(_code, _code.value);
    auto iterator = trxlns.find(transactionln_id);
     if( iterator == trxlns.end()){
      trxlns.emplace(_self, [&]( auto& row ) {
       row.transactionln_id = transactionln_id;
       row.transaction_id = transaction_id;
       row.tstmp = tstmp;
       row.icecat_id = icecat_id;
       row.value = value;
       row.item_quantity=item_quantity;
       row.item_description=item_description;
       row.vat=vat;
      });
     }
    else{
       trxlns.modify(iterator, _self, [&]( auto& row ) {
       row.transactionln_id = transactionln_id;
       row.transaction_id = transaction_id;
       row.tstmp = tstmp;
       row.icecat_id = icecat_id;
       row.value = value;
       row.item_quantity=item_quantity;
       row.item_description=item_description;
       row.vat=vat;
      });
    }

    }


  void icury::removetxln(uint64_t transactionln_id) {
    require_auth(_self);
    transactionln_index trxlns(_self, _code.value);
    auto iterator = trxlns.find(transactionln_id);
    eosio_assert(iterator != trxlns.end(), "Record does not exist");
    trxlns.erase(iterator);
  }

EOSIO_DISPATCH( icury, (writetx)(removetx)(writetxln)(removetxln))

      
    
    