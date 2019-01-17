# icury EOSIO Contracts

## Introduction
This is an EOSIO contract to read, write and modify transaction related data for icecat.The primary purpose of this contract is: 
1. Writing transaction and transaction_line data in their coressponding multi_index_containers.
2. Deleting the 
2. Getting the multi_index_container data.

This readme guides you through two processes:-

1. How to set up the EOSIO network with all the dependent modules.


# Project Dependencies
- This contract requires the following programs for it's functioning.
1. nodeos
2. cleos
3. keosd
4. eosio.cdt (contract development toolkit for EOSIO)


# Setup step

- cleos wallet list
- curl http://localhost:8888/v1/chain/get_info

- cleos wallet create --to-console
```Creating wallet: default
Save password to use in the future to unlock this wallet.
Without password imported keys will not be retrievable.
"PW5JnzdV9mrY3RJiVNiUrfvnbrwdRepsCQiizAkY3LtL7pj1JARTY"
```

-  cleos wallet open
Opened: default

- cleos wallet list
``` Wallets:
[
  "default"
]
````

- cleos wallet unlock
password: Unlocked: default

- cleos wallet list
```
Wallets:
[
  "default *"
]
```

- ##### Import the keys for wallet ######
```
cleos wallet import 
private key: 5K44658mCyJQtmT2TtwgDJtCmduDGibq64mQ9MBBQVWtWSMLvYu
imported private key for: EOS8kJJjEV27b6MZW9n6toS3sTCE8mw9wULnF7J5PvKBn1uDuViFH
```
- ##### Import the dev key for the wallet #####
```
cleos wallet import 
private key: 5KQwrPbwdL6PhXujxW37FSSQZ1JiwsST4cqQzDeyXtP79zkvFD3
imported private key for: EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV
```

- #### Never use the development key for a production account! Doing so will most certainly result in the loss of access to your account, this private key is publicly known.####


```
rehan@vps433578:~/eosio_home$ cleos create account eosio icury EOS8kJJjEV27b6MZW9n6toS3sTCE8mw9wULnF7J5PvKBn1uDuViFH
executed transaction: cd8241a9b13abb76b986131670da4fb572abf33f6dfab2c5f14846703e7ce33a  200 bytes  511 us
#         eosio <= eosio::newaccount            {"creator":"eosio","name":"icury","owner":{"threshold":1,"keys":[{"key":"EOS8kJJjEV27b6MZW9n6toS3sTC...
warning: transaction executed locally, but may not be confirmed by the network yet        ] 
```

- Navigate to the root of the current folder to set the contracts in eosio.
- cleos set contract icury /home/rehan/eosio_home/contracts/icury/ -p icury@active

```
Reading WASM from /home/rehan/eosio_home/contracts/icury/icury.wasm...
Publishing contract...
executed transaction: 6645f29b46bde7affb4ea5c503332bc5497a854f674e82eb4dbfbc911f54a8dd  7200 bytes  1766 us
#         eosio <= eosio::setcode               {"account":"icury","vmtype":0,"vmversion":0,"code":"0061736d0100000001a7011a60027f7e0060057f7e7f7f7f...
#         eosio <= eosio::setabi                {"account":"icury","abi":"0e656f73696f3a3a6162692f312e3100060872656d6f7665747800010e7472616e73616374...
warning: transaction executed locally, but may not be confirmed by the network yet         ] 
```
- cleos push action icury writetxln '[0, 0, 12345, "icecat_id", "ICY", 12, "printers", 2]' -p eosio@active
```executed transaction: 5c13b85c535352a35bba5bb843d2edf79996588457251a7a67a21e618b623017  144 bytes  3220 us
#         icury <= icury::writetxln             {"transactionln_id":0,"transaction_id":0,"tstmp":12345,"icecat_id":"icecat_id","value":"ICY","item_q...
warning: transaction executed locally, but may not be confirmed by the network yet         ] 
```
- ##### do note that you are using the required authority as specified in the contract #####

- Created new private key with a public key of: "EOS5Y1FetisMMPbutRJYXZXgXkm6mSxfXZJQBJeosDKuFbjoionH7"

- cleos create account eosio icury EOS5Y1FetisMMPbutRJYXZXgXkm6mSxfXZJQBJeosDKuFbjoionH7EOS5Y1FetisMMPbutRJYXZXgXkm6mSxfXZJQBJeosDKuFbjoionH7 -p eosio@active

- ##### Compiling the contract to .wasm #####
- eosio-cpp -o icury.wasm icury.cpp --abigen

- cleos set contract icury /home/rails/files/projects/contracts/icury/ -p icury@active

- ##### Examples #####

- cleos get table icury icury  trxs

- cleos push action icury writetx '[1,"alice", "bob", "USD"]' -p icury@active

- cleos push action icury writetxln '[0, 0, 12345, "icecat_id", "ICY", 12, "printers", 2]' -p icury@active

- cleos push action icury removetxln '[0]' -p icury@active


# work in progress:
The Contract is in active development, Here are a few noteworthy points.
1. master branch has the stable code
2. develop branch has code currently under development.
