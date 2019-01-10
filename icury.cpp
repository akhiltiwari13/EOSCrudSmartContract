#include <eosiolib/eosio.hpp>

using namespace eosio;

class [[eosio::contract]] icury : public eosio::contract {

public:
  using contract::contract;
  
  icury(name receiver, name code,  datastream<const char*> ds): contract(receiver, code, ds) {}
 
  [[eosio::action]]
  void writetx(uint64_t transaction_id, std::string icecat_userid_from, std::string icecat_userid_to, std::string currency, std::string city, std::string state) {
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
      std::string changes;
      transactions.modify(iterator, _self, [&]( auto& row ) {
        row.transaction_id = transaction_id;
        row.icecat_userid_from = icecat_userid_from;
        row.icecat_userid_to = icecat_userid_to;
        row.currency = currency;
      });
    }
  }

  [[eosio::action]]
  void erase(uint64_t transaction_id) {
    // require_auth(transaction_id);
    transaction_index transactions(_self, _code.value);
    auto iterator = transactions.find(transaction_id);
    eosio_assert(iterator != transactions.end(), "Record does not exist");
    transactions.erase(iterator);
  }

private:
  struct [[eosio::table]] transaction {
    uint64_t transaction_id;
    std::string icecat_userid_from;
    std::string icecat_userid_to;
    std::string currency;
    uint64_t primary_key() const { return transaction_id; }
  };
  typedef eosio::multi_index<"transactions"_n, transaction> transaction_index;

};

EOSIO_DISPATCH( icury, (writetx)(erase))

      
    
    