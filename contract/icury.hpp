#include <eosiolib/eosio.hpp>

using namespace eosio;

class [[eosio::contract]] icury : public eosio::contract {

public:
  using contract::contract;
  
  icury(name receiver, name code,  datastream<const char*> ds): contract(receiver, code, ds) {}
 
  [[eosio::action]]
  void writetx(uint64_t transaction_id, std::string icecat_userid_from, std::string icecat_userid_to, std::string currency);

  [[eosio::action]]
  void removetx(uint64_t transaction_id); 

  [[eosio::action]]
void writetxln( uint64_t transactionln_id,
    uint64_t transaction_id,
    uint64_t tstmp,
    std::string icecat_id,
    std::string value,
    uint16_t item_quantity,
    std::string item_description,
    uint16_t vat);

     [[eosio::action]]
  void removetxln(uint64_t transactionln_id);

private:
  struct [[eosio::table]] transaction {
    uint64_t transaction_id;
    std::string icecat_userid_from;
    std::string icecat_userid_to;
    std::string currency;

    uint64_t primary_key() const { return transaction_id; }
  };
  typedef eosio::multi_index<"trxs"_n, transaction> transaction_index;

  struct [[eosio::table]] transactionln {
    uint64_t transactionln_id;
    uint64_t transaction_id;
    uint64_t tstmp;
    std::string icecat_id;
    std::string value;
    uint16_t item_quantity;
    std::string item_description;
    uint16_t vat;
   
    uint64_t primary_key() const { return transactionln_id; }
  };
  typedef eosio::multi_index<"trxlns"_n, transactionln> transactionln_index;

};


      
    
    