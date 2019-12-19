// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from ethereum_like_wallet.djinni

#ifndef DJINNI_GENERATED_ETHEREUMLIKEACCOUNT_HPP
#define DJINNI_GENERATED_ETHEREUMLIKEACCOUNT_HPP

#include <cstdint>
#include <memory>
#include <string>
#include <vector>
#ifndef LIBCORE_EXPORT
    #if defined(_MSC_VER)
       #include <libcore_export.h>
    #else
       #define LIBCORE_EXPORT
    #endif
#endif

namespace ledger { namespace core { namespace api {

class BigIntCallback;
class BigIntListCallback;
class ERC20LikeAccount;
class EthereumLikeTransaction;
class EthereumLikeTransactionBuilder;
class StringCallback;
struct EthereumGasLimitRequest;

/** Class representing a Ethereum account. */
class LIBCORE_EXPORT EthereumLikeAccount {
public:
    virtual ~EthereumLikeAccount() {}

    /** Send a raw (binary) transaction on the Ethereum blockchain. */
    virtual void broadcastRawTransaction(const std::vector<uint8_t> & transaction, const std::shared_ptr<StringCallback> & callback) = 0;

    /** Send a transaction on the Ethereum blockchain. */
    virtual void broadcastTransaction(const std::shared_ptr<EthereumLikeTransaction> & transaction, const std::shared_ptr<StringCallback> & callback) = 0;

    /** Get a builder object to construct transactions. */
    virtual std::shared_ptr<EthereumLikeTransactionBuilder> buildTransaction() = 0;

    /** Get the list of ERC20 accounts associated with this Ethereum account. */
    virtual std::vector<std::shared_ptr<ERC20LikeAccount>> getERC20Accounts() = 0;

    /**
     * Get gas price from network
     * Note: it would have been better to have this method on EthereumLikeWallet
     * but since EthereumLikeWallet is not used anywhere, it's better to keep all
     * specific methods under the same specific class so it will be easy to segratate
     * when the right time comes !
     */
    virtual void getGasPrice(const std::shared_ptr<BigIntCallback> & callback) = 0;

    /**
     * Get estimated gas limit to set so the transaction will succeed
     * The passed address could be EOA or contract
     * This estimation is based on X last incoming txs (to address) that succeeded
     * Note: same note as above
     */
    virtual void getEstimatedGasLimit(const std::string & address, const std::shared_ptr<BigIntCallback> & callback) = 0;

    /**
     * Get estimated gas limit to set so the transaction will succeed
     * The passed address could be EOA or contract
     * This estimation is based on a dry-run on the node, and it will fail if the request is ill-formed
     * Note: same note as above
     */
    virtual void getDryrunGasLimit(const std::string & address, const EthereumGasLimitRequest & request, const std::shared_ptr<BigIntCallback> & callback) = 0;

    /**
     * Get balance of ERC20 token
     * The passed address is an ERC20 account
     * Note: same note as above
     */
    virtual void getERC20Balance(const std::string & erc20Address, const std::shared_ptr<BigIntCallback> & callback) = 0;

    /**
     * Get balance of ERC20 tokens
     * The passed addresses are ERC20 accounts
     * Note: same note as above
     */
    virtual void getERC20Balances(const std::vector<std::string> & erc20Addresses, const std::shared_ptr<BigIntListCallback> & callback) = 0;
};

} } }  // namespace ledger::core::api
#endif //DJINNI_GENERATED_ETHEREUMLIKEACCOUNT_HPP
