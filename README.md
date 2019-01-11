# icury EOSIO Contracts

## Introduction
This is an EOSIO contract to read, write and modify transaction related data for icecat.The primary purpose of this contract is: 
1. Writing transaction and transaction_line data in their coressponding multi_index_containers.
2. Getting the multi_index_container data.

This readme guides you through two processes:-

1. How to set up the EOSIO network with all the dependent modules.


# Project Dependencies
- This service requires the following programs for it's functioning.
1. nodeos
2. cleos
3. keosd
4. eosio.cdt (contract development toolkit for EOSIO)


# Setup step
- Creating wallet: default
    Save password to use in the future to unlock this wallet.
    Without password imported keys will not be retrievable.
    "PW5J63mMVVn9Stmgu7tqkqQhr9w9cVsCxS2P59PVkZKFKuTobV6FF"


- Created new private key with a public key of: "EOS5Y1FetisMMPbutRJYXZXgXkm6mSxfXZJQBJeosDKuFbjoionH7"

- cleos create account eosio icury
EOS5Y1FetisMMPbutRJYXZXgXkm6mSxfXZJQBJeosDKuFbjoionH7EOS5Y1FetisMMPbutRJYXZXgXkm6mSxfXZJQBJeosDKuFbjoionH7 -p eosio@active


- cleos set contract icury /home/rails/files/projects/contracts/icury/ -p icury@active

- cleos set contract icury /home/rails/files/projects/contracts/icury/ -p icury@active


- eosio-cpp -o icury.wasm icury.cpp --abigen

- cleos get table icury icury  trxs


- cleos push action icury writetx '[1,"akhil", "shanu", "USD"]' -p icury@active


- cleos push action icury writetxln '[0, 0, 12345, "icecat_id", "ICY", 12, "printers", 2]' -p icury@active

- cleos push action icury removetxln '[0]' -p icury@active



# work in progress:
The Contract is in active development, Here are a few noteworthy points.
1. master branch has the stable code
2. develop branch has code currently under development.
