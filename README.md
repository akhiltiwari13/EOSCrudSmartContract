
Creating wallet: default
Save password to use in the future to unlock this wallet.
Without password imported keys will not be retrievable.
"PW5J63mMVVn9Stmgu7tqkqQhr9w9cVsCxS2P59PVkZKFKuTobV6FF"


Created new private key with a public key of: "EOS5Y1FetisMMPbutRJYXZXgXkm6mSxfXZJQBJeosDKuFbjoionH7"

cleos create account eosio icury EOS5Y1FetisMMPbutRJYXZXgXkm6mSxfXZJQBJeosDKuFbjoionH7EOS5Y1FetisMMPbutRJYXZXgXkm6mSxfXZJQBJeosDKuFbjoionH7 -p eosio@active


cleos set contract icury /home/rails/files/projects/contracts/icury/ -p icury@active

cleos set contract icury /home/rails/files/projects/contracts/icury/ -p icury@active


eosio-cpp -o icury.wasm icury.cpp --abigen

cleos get table icury icury  trxs


cleos push action icury writetx '[1,"akhil", "shanu", "USD"]' -p icury@active


cleos push action icury writetxln '[0, 0, 12345, "icecat_id", "ICY", 12, "printers", 2]' -p icury@active

cleos push action icury removetxln '[0]' -p icury@active